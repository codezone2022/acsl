#include <iostream>
using namespace std;

bool is_vowel(char c) {
	switch(c) {
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		return true;
	}
	return false;
}

string remove_double_consonants(string s) {
	string res;
	for(char c : s) {
		char p = res.back();
		if(!res.empty() && !is_vowel(p) && !is_vowel(c) && p == c)
				continue; // ignore the current character if both are consonants
		res += c;
	}
	return res;
}

string remove_vowel(string s) {
	string res;
	for(char c : s)
		if(!is_vowel(c))
			res += c;
	return res;
}

pair<string, string> remove_like_LR(string s1, string s2) {
	string r1,r2;
	auto len = min(s1.length(), s2.length());
	for(int i = 0; i < len; ++i) {
		if(s1[i] == s2[i])
			continue; // skip if same
		r1 += s1[i];
		r2 += s2[i];
	}
	if(len == s1.length())
		for(int i = len; i < s2.length(); ++i)
			r2 += s2[i];
	if(len == s2.length())
		for(int i = len; i < s1.length(); ++i)
			r1 += s1[i];
	return {r1,r2};
}

pair<string, string> remove_like_RL(string s1, string s2) {
	string r1,r2;
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	tie(r1,r2) = remove_like_LR(s1, s2);
	reverse(r1.begin(), r1.end());
	reverse(r2.begin(), r2.end());
	return {r1,r2};
}

int main() {
	for(int n = 0; n < 5; ++n) {
		string one, two;
		cin >> one >> two;

		one = remove_double_consonants(one);
		two = remove_double_consonants(two);

		one = remove_vowel(one);
		two = remove_vowel(two);

		// Use 'tie()' to bundle 'one' and 'two' as the receiving pair
		tie(one,two) = remove_like_LR(one, two);
		tie(one,two) = remove_like_RL(one, two);

		if(one.length() == two.length()) {
			cout << (one < two ? one : two) << endl;
		} else {
			cout << (one.length() < two.length() ? one : two) << endl;
		}
	}
	return 0;
}
