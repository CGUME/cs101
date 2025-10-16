// 左邊: Do before
#include <stdio.h>
int recursion(int n) {
    if (n == 0) return 0; // 走到樓梯底了，準備回頭
    printf("%d\n", n);    // 【動作點】一到這層樓，立刻印出樓層數字
    recursion(n-1);       // 繼續往下走一層
}

int main() {
    recursion(5);
}
