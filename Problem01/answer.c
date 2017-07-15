#include <stdio.h>

// times未満の数字の中から，numの倍数になっている数字の合計を返す関数
int sum(int num, int times);

int main(void)
{
  int result = 0;

  result += sum(3, 1000);
  result += sum(5, 1000);
  result -= sum(15, 1000);

  printf("result = %d\n", result);

  return 0;
}

int sum(int num, int times)
{
  int sum = 0;
  int i;

  for(i=1; i<times; i++) {
    sum += (i%num == 0) ? i : 0;
  }

  return sum;
}
