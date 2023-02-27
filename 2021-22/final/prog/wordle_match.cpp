#include <bits/stdc++.h>
using namespace std;

string target; // target word

vector<bool> counting_array(string word) {
	vector<bool> arr(26, false);
	for(char ch : word)
		arr[ch-'a'] = true;
	return arr;
}

int check_greens(string& target, string& guess) {
	int res = 0;
	for(int i = 0; i < 5; ++i) {
		if(target[i] == guess[i]) {
			++res;
			target[i] = 'G';
			guess[i] = 'G';
		}
	}
	return res;
}

int check_yellows(const string& target, string& guess) {
	int res = 0;
	for(int i = 0; i < 5; ++i) {
		char ch = guess[i];
		if('a' <= ch && ch <= 'z') {
			if(target.find(ch) != string::npos) {
				guess[i] = 'Y';
				++res;
			}
		}
	}
	return res;
}

int check_vowels(const string& origin, const string& guess) {
	int res = 0;
	for(int i = 0; i < 5; ++i) {
		if(guess[i] == 'G') {
			char ch = origin[i];
			if(ch == 'a' || ch == 'e' | ch == 'i' | ch == 'o' | ch == 'u')
				++res;
		}
	}
	return res;
}

int main() {
	while(true) {
		string line;
		getline(cin, line);
		if(line.empty())
			break;
		istringstream sin(line);
		vector<string> words; // guess words
		while(true) {
			string word;
			sin >> word;
			if(word.empty())
				break;
			if(target.empty())
				target = word;
			else
				words.push_back(word);
		}
		// rule#1
		auto target_arr = counting_array(target);
		vector<string> guess;
		vector<bool> used(26,false);
		for(auto word : words) {
			bool found = false;
			for(char ch : word) {
				used[ch-'a'] = true;
				if(target_arr[ch-'a']) {
					found = true;
				}
			}
			if(found)
				guess.push_back(word);
		}
		if(guess.size() < 6) {
			string res;
			for(int i = 0; i < 26; ++i)
				if(!used[i])
					res += ('a'+i);
			cout << res << endl;
		} else {
			sort(guess.begin(), guess.end(), [](const string& a, const string& b) {
				auto s1 = a;
				auto s2 = b;
				auto t1 = target;
				auto t2 = target;
				// rule#2
				int greens1 = check_greens(t1, s1);
				int greens2 = check_greens(t2, s2);
				if(greens1 > greens2)
					return true;
				if(greens1 < greens2)
					return false;
				// rule#3
				int yellows1 = check_yellows(t1, s1);
				int yellows2 = check_yellows(t2, s2);
				if(yellows1 > yellows2)
					return true;
				if(yellows1 < yellows2)
					return false;
				// rule#4a
				if(s1[0] == 'G' && s2[0] != 'G')
					return true;
				if(s1[0] != 'G' && s2[0] == 'G')
					return false;
				// rule#4b
				if(s1.back() == 'G' && s2.back() != 'G')
					return true;
				if(s1.back() != 'G' && s2.back() == 'G')
					return false;
				// rule#4c
				int c1 = check_vowels(a, s1);
				int c2 = check_vowels(b, s2);
				if(c1 > c2)
					return true;
				if(c1 < c2)
					return false;
				// rule#5
				return a < b;
			});
			for(int i = 0; i < 5; ++i)
				cout << guess[i] << ' ';
			cout << guess[5] << endl;
		}
		target.clear();
	}
	return 0;
}
