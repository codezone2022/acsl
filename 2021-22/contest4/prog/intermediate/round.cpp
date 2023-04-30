#include <bits/stdc++.h>
using namespace std;

double python_round(double num) {
    double whole_part, frac_part;
    frac_part = fabs(modf(num, &whole_part));
    if (frac_part < 0.5 || frac_part >= 0.500000000000001) {
        return round(num);
    } else {
        if (static_cast<long long>(whole_part) % 2 == 0) {
            return whole_part;
        } else {
            return (num > 0.0) ? whole_part + 1 : whole_part - 1;
        }
    }
}

int main() {
	cout << python_round(68.5) << endl;
	cout << python_round(68.51) << endl;
	cout << python_round(68.501) << endl;
	cout << python_round(68.5000000001) << endl;
	cout << python_round(68.969999) << endl;
	cout << python_round(1.5) << endl;
	cout << python_round(2.5) << endl;
	cout << python_round(3.5) << endl;
	cout << python_round(4.5) << endl;
	cout << python_round(-1.5) << endl;
	cout << python_round(-2.5) << endl;
	cout << python_round(-3.5) << endl;
	cout << python_round(-4.5) << endl;
	return 0;
}
