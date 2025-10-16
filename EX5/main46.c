#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{
    // 基礎情況 (Base Case): 如果只剩下一個圓盤，就直接移動
    if (n == 1) 
    {
        printf("將圓盤 1 從 %c 移動到 %c\n", from_rod, to_rod);
        return; // 結束這次函式呼叫
    }

    // 第 1 步 (遞迴): 將 n-1 個圓盤從「起始柱」移到「輔助柱」
    // 注意！此時「目標柱」暫時變成了輔助的角色
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // 第 2 步: 移動最底下那個最大的圓盤 (第 n 個)
    printf("將圓盤 %d 從 %c 移動到 %c\n", n, from_rod, to_rod);

    // 第 3 步 (遞迴): 將 n-1 個圓盤從「輔助柱」移到「目標柱」
    // 注意！此時「起始柱」變成了輔助的角色
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() 
{
    int n = 3; 

    printf("解決 %d 個圓盤的河內塔問題步驟如下：\n", n);
    towerOfHanoi(n, 'A', 'B', 'C'); 
    
    return 0; // 代表程式正常結束
}
