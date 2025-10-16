// 右邊: Do after
#include <stdio.h>
int recursion(int n) {
    if (n == 0) return 0; // 走到樓梯底了，準備回頭
    recursion(n-1);       // 【動作點】先往下走一層，等下面的人回來
    printf("%d\n", n);    // 等下面的人回來後，才印出自己的樓層數字
}

int main() {
    recursion(5);
  return 0;
}
