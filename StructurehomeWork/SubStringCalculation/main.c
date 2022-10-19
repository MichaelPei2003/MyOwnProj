#include <stdio.h>
#include <string.h>

int main() {
    int n, pos = 0, num = 0, flag;
    scanf("%d", &n);
    char a[10001], b[10001];
    setbuf(stdin, NULL);
    for (int i = 0; i < n; i++) {
        gets(a);
        gets(b);
        for (int j = 0; j < sizeof(a); j++) {
            if (strcmp(&a[j], &b[0]) == 0) {
                for (int k = j; k < j + sizeof(b); k++) {
                    if (strcmp(&a[k], &b[k - j]) != 0) {
                        flag = 1;
                        break;
                    }
                    if (k + 1 - j == sizeof(b)) {
                        num++;
                        pos = j + 1;
                    }
                }
                if(flag == 1) {
                    flag = 0;
                    break;
                }
                j = j + sizeof(b);
            }
        }
        printf("%d %d", pos, num);
        if(i+1 <= n) {
            printf("\n");
        }
    }
}
