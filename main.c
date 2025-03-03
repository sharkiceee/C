#include<stdio.h>
//#include <stdbool.h>
//#define n 6      //邮票的面值种类加1，因为还要添加面值为0的邮票
//#define m 4      //最多贴m张邮票
int money = 0, tmoney = 0;//money是连续区间的上限;  tmoney是过程值
int m = 0, n = 0;
printf("请输入总共有几种邮票：");
scanf("%d", &n);
n = n + 1;
int a[n];
a[0] = 0;
printf("请输入几种邮票的面值：");
for (i = 1; i < n; i++) {
    scanf("%d", &a[i]);
};
printf("请输入最多贴几张邮票：");
scanf("%d", &m);
bool flag;

void traceback(int t) {
    if (t == m) {
        if (tmoney == money + 1)
            flag = true;
        return;
    }
    for (int i = 0; i < n; i++) {
        tmoney += a[i];
        if (tmoney <= money + 1)
            traceback(t + 1);
        tmoney -= a[i];
    }
}

int main() {
    while (true) { //最大值为多少，不知道，需不断循环确定
        flag = false;
        traceback(0);     //t代表邮票的数量
        if (flag)
            money++;
        else
            break;
    }
    printf("%d", money);
    return 0;
}
