#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define RAM (1024)

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  unsigned char *ram = (unsigned char*) malloc(RAM);
  uint64_t at = 1;
  int max = 0;
  for (int i=n-1; i>=0; --i) {
    int r=++ram[(at>>16)%RAM];
    if (r > max) max=r;
    at = (UINT64_C(25214903917)*at+UINT64_C(11)) % (UINT64_C(1)<<48);
  }

  free(ram);
  printf("%d\n",max);
  return 0;
}
