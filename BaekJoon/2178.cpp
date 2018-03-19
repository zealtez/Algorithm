#include <cstdio>
#include <queue>

using namespace std;

const int roff[4] = { -1, 1, 0, 0 };
const int coff[4] = { 0, 0, -1, 1 };

int N, M;
bool map[101][101];
bool visited[101][101] = { 0 };

int main() {
	int result = 1;
	scanf("%d %d", &N, &M);
	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
			scanf("%1d", &map[i][j]);
	visited[0][0] = true;
	// 입력정리
	
	queue<int> Q;
	Q.push(0);
	
	while (1) {
		int qSize = Q.size();
		for (int i = 0; i<qSize; i++) {
			int r = Q.front() / 100;
			int c = Q.front() % 100;
			Q.pop();
			if (r == N - 1 && c == M - 1) {
				printf("%d\n", result);
				return 0;
			}
			for (int d = 0; d<4; d++) {
				int nr = r + roff[d];
				int nc = c + coff[d];
				if (nr<0 || nr >= N || nc<0 || nc >= M) continue;
				if (!map[nr][nc]) continue;
				if (visited[nr][nc]) continue;
				visited[nr][nc] = true;
				Q.push(nr * 100 + nc);
			}
		}
		result++;
	}
}
