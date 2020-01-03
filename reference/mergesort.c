// https://rosettacode.org/wiki/Sorting_algorithms/Merge_sort#C.2B.2B

#include <stdio.h>
#include <stdlib.h>

void merge(double *a, int n, int m) {
    int i, j, k;
    double *x = (double*) malloc(n * sizeof (double));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             : a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}

void merge_sort (double *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}
 
int main () {
  int n;
  scanf("%d",&n);
  double *a = (double*) malloc(n*sizeof(double));
  int i;
  for (i = 0; i < n; i++) {
    scanf("%lf",&a[i]);
  }
  merge_sort(a, n);
  printf("%d\n",n);
  for (i = 0; i < n; i++) {
    printf("%lf\n",a[i]);
  }
  return 0;
}
