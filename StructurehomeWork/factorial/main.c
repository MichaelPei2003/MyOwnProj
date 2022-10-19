#include <stdio.h>

int main() {
    int x, sum = 0;
    scanf("%d", &x);
    for (; x > 0; x--) {
        sum += x;
    }
    printf("sum = %d", sum);
    return 0;
}
