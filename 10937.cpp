#include <iostream>
#include <cstring>
#define MAX(a,b)(a>b?a:b)
using namespace std;
 
int N, dp[12 * 12][1 << 11];
char board[12][12];
const int score[4][4] = {
    { 100,70,40,0 },
    { 70,50,30,0 },
    { 40,30,20,0 },
    { 0,0,0,0} 
};
int sol(int num, int state) {
    if (num == N*N) return 0;
 
    int &ret = dp[num][state];
    if (ret != -1) return ret;
 
    ret = 0;
    if (state & 1)
        ret = (ret,sol(num + 1, (state >> 1)));
    else {
        int x = num / N;
        int y = num % N;
        if(x<N-1)
            ret = MAX(ret, sol(num + 1, (state >> 1) | (1 << (N - 1))) + score[board[x][y] - 'A'][board[x + 1][y] - 'A']);
        if ((num%N) != (N - 1) && (state & 2) == 0)
            ret = MAX(ret, sol(num + 2, state >> 2) + score[board[x][y] - 'A'][board[x][y + 1] - 'A']);
    }
    ret = MAX(ret,sol(num + 1, (state >> 1)));
    return ret;
}
 
int main(void) {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N); getchar();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ch;scanf("%1c", &ch);
            if (ch == 'F')
                board[i][j] = 'D';
            else
                board[i][j] = ch;
        }
        getchar();
         
    }
    //입력정리
    cout << sol(0, 0);
    return 0;
 
}
