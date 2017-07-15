#include <stdio.h>

int count(int num);

int palindrome(int num, int fig);

int main() {
    int i, j, res, is_pal;
    int max;

    max = 0;

    // res に 100*100 から999*999 まで順番に渡していく
    for (i = 100; i < 1000; i++) {
        for (j = 100; j < 1000; j++) {

            res = i * j;

            // 回文数なら1(true)，そうでないなら0(false)が帰ってくる
            is_pal = palindrome(res, count(res));

            // 回文数かつ，今までの回文数で一番大きい数maxよりも大きな数なら，maxを更新
            if (is_pal && res > max) {
                max = res;
            }
        }
    }

    // 結果発表
    printf("result: %d", max);

    return 0;
}

// 与えられた整数値の桁数を返す関数
int count(int num) {
    int fig = 0;

    while (num != 0) {
        num /= 10;
        fig++;
    }

    return fig;
}

// 数値とその桁数を渡すと，その数値が回文数かどうかを返す関数
int palindrome(int res, int fig) {
    int i, tmp, num, count;
    int a_num[fig], reverse[fig];

    tmp = res;
    num = 1;
    count = 0;

    // 10^(桁数)の用意
    for (i = 0; i < fig - 1; i++) {
        num *= 10;
    }

    // 与えられた数値を1つずつ取り出して，配列に格納する
    for (i = 0; i < fig; i++) {
        a_num[i] = tmp / num;
        tmp -= a_num[i] * num;
        num /= 10;
    }

    // できあがった配列を反転させた配列を作る
    for (i = 0; i < fig; i++) {
        reverse[fig - i - 1] = a_num[i];
    }

    // 2つの配列を頭から1つずつ比較して，違うなら変数countを増やす
    for (i = 0; i < fig; i++) {
        if (a_num[i] != reverse[i]) {
            count++;
        }
    }

    if (count) { // 変数countが0でなければtrueとなる
        return 0; // false を返す
    } else {
        return 1; // true を返す
    }
}

