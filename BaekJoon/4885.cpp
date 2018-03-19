#include <iostream>
#include <queue>
using namespace std;

int inf = 100000000;
int moveX[] = { 0,0,-1,1 };
int moveY[] = { -1,1,0,0 };

int main(void) {
	int T=1,N;
	while(scanf("%d", &N),N){
		int board[126][126];
		int dist[126][126];
		bool visit[126][126] = { false, };
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				scanf("%d", &board[i][j]);
				dist[i][j] = inf;
			}
		
		priority_queue<pair<int, pair<int, int>>>q;
		q.push({ 0,{ 0,0 } });
		dist[0][0] = board[0][0];
		while (!q.empty()) {
			auto p = q.top();
			q.pop();
			int x = p.second.first;
			int y = p.second.second;
			if (visit[x][y])continue;
			visit[x][y] = true;
			for (int next = 0; next < 4; next++) {
				int nx = x + moveX[next];
				int ny = y + moveY[next];
				if (nx < 0 || ny < 0 || nx == N || ny == N) continue; 

				if (dist[nx][ny] > dist[x][y] + board[nx][ny]) {
					dist[nx][ny] = dist[x][y] + board[nx][ny];
					q.push({ -dist[nx][ny],{nx,ny} });
				}
			}
		}
		printf("Problem %d: %d\n",T, dist[N - 1][N - 1]);
		T++;
	}

	return 0;
}
