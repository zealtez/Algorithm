#include <iostream>
#include <cstring>
using namespace std;

int moveX[] = { 0,0,-1,1 };
int moveY[] = { -1,1,0,0 };

char board[101][101];
bool visit[101][101] = { false, };
int N;
void dfs(int x, int y, char ch) {
	for (int next = 0; next < 4; next++) {
		int nx = x + moveX[next];
		int ny = y + moveY[next];
		if (nx < 0 || ny < 0 || nx == N || ny == N || visit[nx][ny] || board[nx][ny] != ch) continue;
		visit[nx][ny] = true;
		dfs(nx, ny, ch);
	}
	return;
}

void bdfs(int x, int y, char ch) {
	for (int next = 0; next < 4; next++) {
		int nx = x + moveX[next];
		int ny = y + moveY[next];
		if (nx < 0 || ny < 0 || nx == N || ny == N || visit[nx][ny]) continue;
		if (ch == 'R' && board[nx][ny] == 'B') continue;
		if (ch == 'G' && board[nx][ny] == 'B') continue;
		if (ch == 'B' && board[nx][ny] == 'R') continue;
		if (ch == 'B' && board[nx][ny] == 'G') continue;
		visit[nx][ny] = true;
		bdfs(nx, ny, ch);
	}
	return;
}

int main(void) {
	scanf("%d", &N);
	int cnt = 0, sol = 0;
	getchar();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1c", &board[i][j]);
		}
		getchar();
	}//입력정리

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				cnt++;
				visit[i][j] = true;
				dfs(i, j,board[i][j]);
			}
		}
	}
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				sol++;
				visit[i][j] = true;
				bdfs(i, j, board[i][j]);
			}
		}
	}
	cout << cnt<<" "<<sol;
	return 0;
}
