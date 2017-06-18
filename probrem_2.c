#include <stdio.h>

int main(void)
{
  int ans, sum, range, check_even;
  int num[100] = {1,2};
  int i, j, k;

  range = 4000000;
  ans = 0;

  for(i=2; i<100; i++) {
    sum = num[i-1] + num[i-2];

    if(sum <= range) {
      num[i] = sum;
    } else {
      break;
    }
  }

  for(j=0; j<=i; j++) {
    check_even = num[j] % 2;

    ans += (check_even == 0) ? num[j] : 0;
  }

  printf("Answer = %d\n", ans);

  return 0;
}
