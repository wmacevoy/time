#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  uint64_t at = 1;
  printf("%d\n",n);
  for (int i=n-1; i>=0; --i) {
    printf("%d\n",(int) at);
    at = (UINT64_C(25214903917)*at+UINT64_C(11)) % (UINT64_C(1)<<48);
  }

  return 0;
}
