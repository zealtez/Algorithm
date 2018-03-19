#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++,printf("\n"))
            for(int j=0;j<n;j++)
                printf("%c",(i==0||i==n-1||j==0||j==n-1)?'#':'J');
        printf("\n");
    }
}
