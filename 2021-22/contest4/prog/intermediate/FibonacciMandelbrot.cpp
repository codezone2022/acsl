#include <bits/stdc++.h>
using namespace std;

// Using a list of two items to represent a complex number as [ real, imaginary ]

vector<double> addComplex(vector<double> x, vector<double> y) {
	// vector<double> res;
	// res.push_back(x[0]+y[0]);
	// res.push_back(x[1]+y[1]);
	return { x[0]+y[0], x[1]+y[1] };
}

vector<double> mulComplex(vector<double> x, vector<double> y) {
	return { x[0]*y[0] - x[1]*y[1], x[0]*y[1]+x[1]*y[0] };
}

double absComplex(vector<double> x) {
	return sqrt( x[0]*x[0] + x[1]*x[1] );
}

vector<double> func(vector<double> z, vector<double> C) {
	return addComplex( mulComplex(z, z), C );
}

// What the problem description says about Python, Java, C++ round() function behave the same is incorrect.
// Python3 behaves differently when numbers that are *exactly* halfway between two integers.
// And the problem expect the Python3 rounding!!!
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
	for(int n = 0; n < 5; ++n) {
		vector<double> C(2,0.0), z(2, 0.0); // zeros!
		cin >> C[0] >> C[1]; // reading C from input
		map<pair<long long,long long>,int> results;
		for(int i = 0;;) {
			++i;
			z = func(z, C);
			z = { python_round(z[0]*100.0)/100.0, python_round(z[1]*100.0)/100.0 };
			// Do we have an escape?
			if(absComplex(z) > 4.0) {
				cout << "ESCAPES " << i << endl;
				break;
			}
			// Do we have a cycle? A repeated value
			auto p = make_pair( python_round(z[0]*100.0), python_round(z[1]*100.0) );
			if(results.find(p) != results.end())
			{
				cout << i - results[p] << endl; // The lenght of cycle is a delta!
				break;
			}
			results[p] = i;
		}
	}
	return 0;
}
