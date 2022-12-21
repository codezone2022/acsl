#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string tolower(string str) {
	string res;
	for(auto ch : str) {
		if(isupper(ch)) // Uppercase
			res += tolower(ch);
		else if(islower(ch)) // Lowercase
			res += ch;
		// Ignore non-letters
	}
	return res;
}

// Approach#1: Divide target string 'str' into two strings: 'res' is the remaining; 'add' is the addition for new string
string unique_sort1(string str, string& newstr) {
	bool carr[26] = {}; // Counting Array - initialized with all falses/zeros
	string res;
	string add;
	for(auto ch : str) {
		int i = ch - 'a';
		if(!carr[i]) {
			carr[i] = true;
			add += ch;
		} else {
			res += ch;
		}
	}
	sort(add.begin(),add.end());
	newstr += add;
	return res;
}

// Approach#2: Utilize 'carr' Counting Array to perform a Counting Sort
string unique_sort2(string str, string& newstr) {
	bool carr[26] = {}; // Counting Array - initialized with all falses/zeros
	string res;
	for(auto ch : str) {
		int i = ch - 'a';
		if(!carr[i]) {
			carr[i] = true;
		} else {
			res += ch;
		}
	}
	for(int i = 0; i < 26; ++i)
		if(carr[i])
			newstr += ('a' + i); // base + offset
	return res;
}

string remove_duplicate(string str) {
	string res;
	for(char ch : str) {
		if(res.empty()) {
			res += ch;
			continue;
		}
		// These are the alternative approaches to get the last character in a string:
		// res[res.length()-1]
		// *res.rbegin()
		if(res.back() != ch)
			res += ch;
	}
	return res;
}

int main() {
	for(int n = 0; n < 5; ++n) { // You do not need to loop 5 times in HackerRank.com!
		string line;
		getline(cin, line);
		string newstr;
		string str = tolower(line);
		cout << "Step0: " << str << endl;
		do {
			str = unique_sort1(str, newstr);
			//str = unique_sort2(str, newstr);
		} while(!str.empty());
		cout << remove_duplicate(newstr) << endl;
	}
	return 0;
}
