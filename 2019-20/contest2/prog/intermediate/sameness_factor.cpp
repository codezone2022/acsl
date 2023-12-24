#include <iostream>
using namespace std;

int calc(string a, string b) {
	int res = 0;
	for(int i = 0; i < a.length() && i < b.length(); ++i) {
		res += (int(a[i]) - int(b[i]));
	}
	return res + abs(int(a.length()) - int(b.length()));
}

int main() {
	for(int n = 0; n < 5; ++n) {
		string one, two;
		cin >> one >> two;
		while(true) {
			auto old_one = one; auto old_two = two;
			string new_one, new_two;

			// Delete the like characters in the like locations
			for(int i = 0, j = 0; i < one.length() || j < two.length(); ++i,++j) {
				if(i < one.length() && j < two.length() && one[i] == two[j])
					continue;
				if(i < one.length())
					new_one += one[i];
				if(j < two.length())
					new_two += two[j];
			}

			one = new_one; two = new_two;
			new_one.clear(); new_two.clear();

			// Delete for alignments
			for(int i = 0, j = 0; i < one.length() || j < two.length(); ++i,++j) {
				if(i < one.length() && j < two.length() && one[i] != two[j]) {
					if(j < two.length()-1 && one[i] == two[j+1]) {
						++j;
						continue;
					}
					if(i < one.length()-1 && one[i+1] == two[j]) {
						++i;
						continue;
					}
				}
				if(i < one.length())
					new_one += one[i];
				if(j < two.length())
					new_two += two[j];
			}

			if(old_one == new_one && old_two == new_two)
				break;
			one = new_one; two = new_two;
		}
		cout << calc(one, two) << endl;
	}
	return 0;
}
