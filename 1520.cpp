#include <string>
#include <iostream>
#include <cstring>
using namespace std;

int M, N;
int map[501][501];
int memo[501][501];
int dx[4] = { -1, 1, 0, 0 };    // [j]: L, R, U, D
int dy[4] = { 0, 0, -1, 1 };    // [i]: L, R, U, D

int Route(int y, int x) {
	if (y == M - 1 && x == N - 1) return 1;

	int& ret = memo[y][x];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[ny][nx] < map[y][x])
			ret += Route(ny, nx);
	}
	return ret;
}

int main() {
	memset(memo, -1, sizeof(memo));
	scanf("%d %d", &M, &N);
	for (int i = 0; i<M; i++) {
		for (int j = 0; j<N; j++)
			scanf("%d", &map[i][j]);
	}
	printf("%d\n", Route(0, 0));
	return 0;
}
