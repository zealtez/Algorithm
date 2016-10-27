#include <iostream>
using namespace std;

long long sum[1027][1027] = { 0, };

//입력
void summing(int x, int y, int num) {
	if (x == 0 && y == 0) {
		sum[x][y] = num;
	}
	else if (y == 0) {
		sum[x][y] = sum[x - 1][y] + num;
	}
	else if (x == 0) {
		sum[x][y] = sum[x][y - 1] + num;
	}
	else {
		sum[x][y] = sum[x][y - 1] + sum[x - 1][y] - sum[x - 1][y - 1] + num;
	}
}
//계산
long long summing(int toX, int toY, int fromX, int fromY) {
	if (fromX == 0 && fromY == 0) {
		return sum[toX][toY];
	}
	else if (fromY == 0) {
		return sum[toX][toY] - sum[fromX - 1][toY];
	}
	else if (fromX == 0) {
		return sum[toX][toY] - sum[toX][fromY - 1];
	}
	else {
		return sum[toX][toY] + sum[fromX - 1][fromY - 1] - sum[toX][fromY - 1] - sum[fromX - 1][toY];
	}
}

int main(void) {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num; scanf("%d", &num);
			summing(i, j, num);
		}
	}//입력정리

	while (M--) {
		int fX, fY, tX, tY; scanf("%d %d %d %d", &fX, &fY, &tX, &tY);
		printf("%lld\n", summing(tX - 1, tY - 1, fX - 1, fY - 1));
	}
	return 0;
}
