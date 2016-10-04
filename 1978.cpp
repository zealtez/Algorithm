#include<cstdio>

int n,r;
int main() {
    scanf("%d", &n);
    r = n;
    for (int i = 0,x; i < n; i++) {
        scanf("%d", &x);
        if (x == 1) r--;
        for(int j=2; j*j<=x; j++)
            if (x%j == 0) { r--; break; }
    }
    printf("%d", r);
    return 0;
}
