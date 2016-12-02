/*Floyd*/
#include <iostream>
#include <vector>
using namespace std;

int N, M, S;
int con[401][401];
int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int from, to; scanf("%d %d", &from, &to);
		con[from][to] = -1;
		con[to][from] = 1;
	}//입력정리

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (con[i][k] + con[k][j] == 0) continue;
				if (con[i][k] == 1 && con[k][j] == 1)
					con[i][j] = 1;
				else if (con[i][k] == -1 && con[k][j] == -1)
					con[i][j] = -1;
			}
		}
	}

	scanf("%d", &S);
	while (S--) {
		int start, end; scanf("%d %d", &start, &end);
		printf("%d\n", con[start][end]);
	}


	return 0;
}
