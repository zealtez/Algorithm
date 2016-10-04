#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[5];
int n,m,l;
int main()
{
    scanf("%s %d", s, &m);
    int n = atoi(s);
    l = strlen(s);
    for (int i = 0; i < n*l && i<m;i++) printf("%c", s[i%l]);
    return 0;
}
