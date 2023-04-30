import java.io.*;
import java.util.*;
import java.lang.*;

// Using a list of two items to represent a complex number as [ real, imaginary ]

public class FibonacciMandelbrot {

	public static double[] addComplex(double[] x, double[] y) {
		return new double[] { x[0]+y[0], x[1]+y[1] };
	}

	public static double[] mulComplex(double[] x, double[] y) {
		return new double[] { x[0]*y[0] - x[1]*y[1], x[0]*y[1]+x[1]*y[0] };
	}

	public static double absComplex(double[] x) {
		return Math.sqrt( x[0]*x[0] + x[1]*x[1] );
	}

	public static double[] func(double[] z, double[] C) {
		return addComplex( mulComplex(z, z), C );
	}

	// What the problem description says about Python, Java, C++ round() function behave the same is incorrect.
	// Python3 behaves differently when numbers that are *exactly* halfway between two integers.
	// And the problem expect the Python3 rounding!!!
	public static double python_round(double num) {
		long whole_part = (long)num;
		double frac_part = Math.abs(num - whole_part);
		if (frac_part < 0.5 || frac_part >= 0.500000000000001) {
			return Math.round(num);
		} else {
			if (whole_part % 2 == 0) {
				return whole_part;
			} else {
				return (num > 0.0) ? whole_part + 1 : whole_part - 1;
			}
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) {
			double[] C = new double[2];
			double[] z = new double[2];
			C[0] = input.nextDouble();
			C[1] = input.nextDouble();
			HashMap<String,Integer> results = new HashMap<String, Integer>();
			for(int i = 0;;) {
				++i;
				z = func(z, C);
				z = new double[] { python_round(z[0]*100.0)/100.0, python_round(z[1]*100.0)/100.0 };
				if(absComplex(z) > 4.0) { // Has an escape?
					System.out.println("ESCAPES " + Integer.toString(i));
					break;
				}
				String s = String.format("%.2f %.2f", z[0], z[1]); // Avoid double comparision
				if(results.containsKey(s)) { // Has a cycle?
					System.out.println(i-results.get(s)); // The length of cycle is a delta!
					break;
				}
				results.put(s, i);
			}
		}
	}
}
