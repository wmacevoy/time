#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

char buffer[32];

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  uint64_t at = 1;
  snprintf(buffer,sizeof(buffer),"%d\n",n);
  sscanf(buffer,"%d",&n);
  int max=0;
  for (int i=n-1; i>=0; --i) {
    int x;
    snprintf(buffer,sizeof(buffer),"%d\n",(int) at);
    sscanf(buffer,"%d",&x);
    if (x > max) max=x;
    at = (UINT64_C(25214903917)*at+UINT64_C(11)) % (UINT64_C(1)<<48);
  }

  printf("%d\n",max);

  return 0;
}
