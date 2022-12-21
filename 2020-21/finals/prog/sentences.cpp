#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> getWords() {
	string line;
	getline(cin,line);
	istringstream is(line);
	vector<string> res;
	while(is) {
		string word;
		is >> word;
		if(word.empty())
			break;
		res.push_back(word);
	}
	return res;
}

string getWord(vector<string>& words, int& index) {
	auto res = words[index++];
	index %= words.size();
	return res;
}

void cap(bool& needCap, string& word) {
	if(needCap) {
		needCap = false;
		word[0] = toupper(word[0]);
	}
}

int main() {
	int K;
	cin >> K;
	vector<string> Ns, Cs, Vs, Js, Bs, Ps;
	int Ni = 0, Ci = 0, Vi = 0, Ji = 0, Bi = 0, Pi = 0;
	for(int k = 0; k < K; ++k) {
		char part = '\0';
		cin >> part;
		switch(part) {
		case 'N': Ns = getWords(); break;
		case 'C': Cs = getWords(); break;
		case 'V': Vs = getWords(); break;
		case 'J': Js = getWords(); break;
		case 'B': Bs = getWords(); break;
		case 'P': Ps = getWords(); break;
		}
	}
	auto sentences = getWords();
	for(int i = 0; i < sentences.size(); ++i) {
		string beg,mid,end;
		bool needCapital = true;
		switch(sentences[i][0]) {
		case 'D':
			end = ".";
			break;
		case 'I':
			end = ".";
			break;
		case 'Q':
			beg = "What ";
			end = "?";
			needCapital = false;
			break;
		case 'E':
			end = "!";
			break;
		}
		for(int j = 1; j < sentences[i].size(); ++j) {
			switch(sentences[i][j]) {
			case 'T':
				{
					string curr = "the";
					cap(needCapital, curr);
					mid += curr;
				}	
				break;
			case 'A':
				{
					string curr, next;
					switch(sentences[i][j+1]) { // Don't worry about buffer over-run!
					case 'N': next = Ns[Ni]; break;
					case 'C': next = Cs[Ci]; break;
					case 'V': next = Vs[Vi]; break;
					case 'J': next = Js[Ji]; break;
					case 'B': next = Bs[Bi]; break;
					case 'P': next = Ps[Pi]; break;
					}
					switch(next[0]) {
					case 'a': curr = "an"; break;
					case 'e': curr = "an"; break;
					case 'i': curr = "an"; break;
					case 'o': curr = "an"; break;
					case 'u': curr = "an"; break;
					default: curr = "a"; break;
					}
					cap(needCapital,curr);
					mid += curr;
				}
				break;
			case 'N': { auto curr = getWord(Ns,Ni); cap(needCapital,curr); mid += curr; } break;
			case 'C': { auto curr = getWord(Cs,Ci); cap(needCapital,curr); mid += curr; } break;
			case 'V': { auto curr = getWord(Vs,Vi); cap(needCapital,curr); mid += curr; } break;
			case 'J': { auto curr = getWord(Js,Ji); cap(needCapital,curr); mid += curr; } break;
			case 'B': { auto curr = getWord(Bs,Bi); cap(needCapital,curr); mid += curr; } break;
			case 'P': { auto curr = getWord(Ps,Pi); cap(needCapital,curr); mid += curr; } break;
			}
			if(j < sentences[i].size()-1)
				mid += ' ';
		}
		cout << beg << mid << end;
		if(i < sentences.size()-1)
			cout << ' ';
	}
	cout << endl;
	return 0;
}
