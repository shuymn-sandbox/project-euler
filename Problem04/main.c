#include <stdio.h>

int count(int num);

int palindrome(int num, int fig);

int main() {
    int i, j, res, is_pal;
    int max;

    max = 0;

    for (i = 100; i < 1000; i++) {
        for (j = 100; j < 1000; j++) {

            res = i * j;
            is_pal = palindrome(res, count(res));

            if (is_pal && res > max) {
                max = res;
            }
        }
    }

    printf("result: %d", max);

    return 0;
}

int count(int num) {
    int fig = 0;

    while (num != 0) {
        num /= 10;
        fig++;
    }

    return fig;
}

int palindrome(int res, int fig) {
    int i, tmp, num, count;
    int a_num[fig], reverse[fig];

    tmp = res;
    num = 1;
    count = 0;

    for (i = 0; i < fig - 1; i++) {
        num *= 10;
    }

    for (i = 0; i < fig; i++) {
        a_num[i] = tmp / num;
        tmp -= a_num[i] * num;
        num /= 10;
    }

    for (i = 0; i < fig; i++) {
        reverse[fig - i - 1] = a_num[i];
    }

    for (i = 0; i < fig; i++) {
        if (a_num[i] != reverse[i]) {
            count++;
        }
    }

    if (count) {
        return 0;
    } else {
        return 1;
    }
}

