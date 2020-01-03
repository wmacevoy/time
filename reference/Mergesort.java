import java.io.*;
import java.util.*;

public class Mergesort {
    static void merge(double [] a, int offset,int n, int m) {
	int i, j, k;
	double [] x = new double[n];
	int jb = n+offset;
	int ib = m+offset;
	for (i = offset, j = offset+m, k = 0; k < n; k++) {
	    x[k] = j == jb      ? a[i++]
		: i == ib      ? a[j++]
		: a[j] < a[i] ? a[j++]
		: a[i++];
	}
	for (i = 0; i < n; i++) {
	    a[offset+i] = x[i];
	}
    }

    static void merge_sort (double [] a, int offset, int n) {
	if (n < 2)
	    return;
	int m = n / 2;
	merge_sort(a, offset, m);
	merge_sort(a, offset + m, n - m);
	merge(a, offset, n, m);
    }
 
    public static void main (String [] args) {
	int n;
	Scanner in = new Scanner(System.in);
	n=in.nextInt();
	double [] a = new double[n];
	int i;
	for (i = 0; i < n; i++) {
	    a[i]=in.nextDouble();
	}
	merge_sort(a, 0, n);
	System.out.printf("%d%n",n);
	for (i = 0; i < n; i++) {
	    System.out.printf("%f%n",a[i]);
	}

    }
}
