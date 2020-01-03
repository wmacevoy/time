#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
  int n;
  scanf("%d",&n);
  int max=0;
  for (int i=n-1; i>=0; --i) {
    int x;
    scanf("%d",&x);
    if (x > max) max=x;
  }
  printf("%d\n",max);

  return 0;
}
