// https://rosettacode.org/wiki/Sorting_algorithms/Merge_sort#C.2B.2B

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, const char *argv[]) {
  int n = 0;
  int s = 1;
  int i;
  for (i=1; i<argc; ++i) {
    if (strcmp(argv[i],"-n")==0) {
      n = atoi(argv[++i]);
      continue;
    }
    if (strcmp(argv[i],"-s")==0) {
      s = atoi(argv[++i]);
      continue;
    }
  }
  srand(s);
  printf("%d\n",n);
  for (int i=0; i<n; ++i) {
    printf("%d\n",rand());
  }
  return 0;
}
