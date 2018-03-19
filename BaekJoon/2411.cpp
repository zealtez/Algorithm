/*https://www.acmicpc.net/problem/2411*/
#include <iostream>
#include <cstring>
using namespace std;

int N, M, A, B;
int board[101][101];
int dp[101][101][201];

const int moveX[] = { 1,0 };
const int moveY[] = { 0,1 };

int sol(int x, int y,int cnt) {
	if (x == N - 1 && y == M - 1) { 
		if(cnt == A) return 1; 
		else return 0;
	}

	int &ret = dp[x][y][cnt];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 2; i++) {
		int nx = x + moveX[i];
		int ny = y + moveY[i];
		if (nx < 0 || ny < 0 || nx == N || ny == M || board[nx][ny] == 2) continue;
		ret += sol(nx, ny, (board[x][y] == 1 ? cnt + 1 : cnt));
	}
	return ret;
}

int main(void) {
	memset(board, 0, sizeof(board));
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d %d", &N, &M, &A, &B);
	for (int i = 0; i < A; i++) {
		int x,y; scanf("%d %d", &x, &y);
		board[x-1][y-1] = 1; // 아이템
	}
	for (int i = 0; i < B; i++) {
		int x, y; scanf("%d %d", &x, &y);
		board[x-1][y-1] = 2; // 장애물
	}
	//입력정리 

	cout << sol(0, 0,0) << endl;

	return 0;
}
