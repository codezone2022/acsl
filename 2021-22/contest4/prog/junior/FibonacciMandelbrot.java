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
			boolean esc = false;
			for(int i=1; i<=5; ++i) { // Evaluate func() 5 times or stop when greater than 4
				z = func(z, C);
				if(absComplex(z) > 4.0) {
					System.out.println("ESCAPES " + Integer.toString(i));
					esc = true;
					break;
				}
			}
			if(esc == false) {
				double res = Math.round(absComplex(z) * 1000.0)/1000.0;
				System.out.println(res);
			}
		}
	}
}
