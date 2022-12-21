#include <bits/stdc++.h>
using namespace std;

void tolower(string& s) {
	for(auto& c : s)
		if(isupper(c))
			c = tolower(c);
}

int main() {
	string s;
	getline(cin, s);
	int diffs[26] = {};
	int vowels = 0;
	int up = 0;
	for(char& c : s) { // Use Counting Array and case insensitive
		if(isupper(c)) {
			++diffs[c-'A'];
			switch(c) {
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				++vowels;
				break;
			}
			++up;
		} else if(islower(c)) {
			++diffs[c-'a'];
			switch(c) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				++vowels;
				break;
			}
		}
		else { // non-letter
			c = ' '; // replace with a space
		}
	}
	int cnt = 0; int max_val = 0;
	for(int i = 0; i < 26; ++i) {
		if(diffs[i])
			++cnt;
		max_val = max(max_val, diffs[i]);
	}
	cout << cnt << endl;
	cout << vowels << endl;
	cout << up << endl;
	cout << max_val << endl;

	vector<string> words;
	istringstream is(s);
	do {
		string word;
		is >> word; //getline(is, word, ' ');
		if(word.empty())
			break;
		if(words.empty()) {
			words.push_back(word);
			continue;
		}
		if(word.length() < words.back().length())
			continue; // skip shorter word
		if(word.length() == words.back().length()) {
			words.push_back(word);
			continue; // add same length word
		}
		words.clear(); // empty storage for new longer length
		words.push_back(word);
	} while(is);

	if(words.size() == 1) {
		cout << words[0] << endl;
		return 0;
	}

	auto low_words = words;
	for(auto& word : low_words)
		tolower(word); // Convert to lower case for sorting
	auto sorted = low_words;
	sort(sorted.begin(), sorted.end());
	auto first = sorted[0];
	for(int i = 0; i < low_words.size(); ++i)
		if(low_words[i] == first) {
			cout << words[i] << endl; // Output the one before conversion
			return 0;
		}
	return 0;
}
