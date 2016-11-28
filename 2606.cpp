#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int con[101][101];

int main(void) {
	scanf("%d %d", &N, &M);
	memset(con, 0, sizeof(con));
	for (int i = 0; i < M; i++) {
		int from, to; scanf("%d %d", &from, &to);
		con[from][to] = con[to][from] = 1;

	}//입력정리

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (con[i][j] == false && (con[i][k] == 1 && con[k][j] == 1))
					con[i][j] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 2; i <= N; i++)
		if (con[1][i])
			cnt++;
	printf("%d\n", cnt);
	return 0;
}
