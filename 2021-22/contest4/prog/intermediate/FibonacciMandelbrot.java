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
				z = new double[] { Math.round(z[0]*100.0)/100.0, Math.round(z[1]*100.0)/100.0 };
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
