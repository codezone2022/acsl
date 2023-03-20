#include <bits/stdc++.h>
using namespace std;

// Using a list of two items to represent a complex number as [ real, imaginary ]

vector<double> addComplex(vector<double> x, vector<double> y) {
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

int main() {
	for(int n = 0; n < 5; ++n) {
		vector<double> C(2,0.0), z(2, 0.0);
		cin >> C[0] >> C[1];
		bool esc = false;
		for(int i=1; i<=5; ++i) { // Evaluate func() 5 times or stop when greater than 4
			z = func(z, C);
			if(absComplex(z) > 4.0) {
				cout << "ESCAPES " << i << endl;
				esc = true;
				break;
			}
		}
		if(esc == false) {
			auto res = round(absComplex(z) * 1000.0)/1000.0;
			cout << fixed << setprecision(3) << res << endl;
		}
	}
	return 0;
}
