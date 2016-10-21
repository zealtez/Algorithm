#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int moveX[] = { 0,0,-1,1 };
const int moveY[] = { -1,1,0,0 };

int N, M;
int board[1001][1001];
int d[1001][1001];

int main(void) {
	memset(d, -1, sizeof(d));
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &board[i][j]);
	//입력 정리

	priority_queue<pair<int, pair<int, int>>> q;
	// 뿅망치가 있는 경우 1의 가중치를 둔다.
	q.push({ 1,make_pair(0,0) });
	d[0][0] = 0;
	while (!q.empty()) {
		int ability = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();
		for (int next = 0; next < 4; next++) {
			int nx = x + moveX[next];
			int ny = y + moveY[next];
			if (nx < 0 || nx == N || ny < 0 || ny == M) continue;

			if (ability == 0 && board[nx][ny] == 1) continue;
			else if (board[nx][ny] == 0) {
				if (d[nx][ny] == -1 || d[nx][ny] > d[x][y] + 1) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ ability,make_pair(nx, ny) });
				}
			}
			else if (ability == 1 && board[nx][ny] == 1) {
				if (d[nx][ny] == -1 || d[nx][ny] > d[x][y] + 1) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ 0,make_pair(nx, ny) });
				}
			}

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d", d[i][j]);
		puts("");
	}

	if (d[N - 1][M - 1] == -1)
		printf("-1");
	else printf("%d", d[N - 1][M - 1] + 1);
	return 0;
	return 0;
}
