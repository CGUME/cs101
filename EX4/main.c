#include <stdio.h>

int main(void)
{
    FILE* fp = fopen("a.bin", "w+b");
    int a[] = {0,1,2};
    char b[] = "ABC";
    float c[] = {1.1,1.2,1.3};

    if (fp == NULL)
    {
        printf("找不到檔案！\n");
        return 1;
    }

    size_t na = sizeof(a)/sizeof(a[0]);
    size_t nb = sizeof(b)/sizeof(b[0]);
    size_t nc = sizeof(c)/sizeof(c[0]);

    fwrite(a, sizeof(a[0]), na, fp);
    fwrite(b, sizeof(b[0]), nb, fp);
    fwrite(c, sizeof(c[0]), nc, fp);

    rewind(fp); /* 必須把檔案位置重設到開頭，否則 fread 會失敗 */

    fread(a, sizeof(a[0]), na, fp);
    fread(b, sizeof(b[0]), nb, fp);
    fread(c, sizeof(c[0]), nc, fp);

    for (size_t i = 0; i < na; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (size_t i = 0; i < nb; i++) {
        printf("%c", b[i]);
    }
    printf("\n");

    for (size_t i = 0; i < nc; i++) {
        printf("%g ", c[i]);
    }
    printf("\n");

    fclose(fp);
    return 0;
}
