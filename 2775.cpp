#include <iostream>
using namespace std;

int main(void) {
	int T; scanf("%d", &T);
	while (T--) {
		int sol[15][15] = { 0, };
		int k, n; scanf("%d %d", &k, &n);
		for (int i = 1; i <= n; i++)
			sol[0][i] = i;

		for (int i = 1; i <= k; i++) {
			int sum = sol[i-1][1];
			for (int j = 1; j <= n; j++) {
				if (j == 1) sol[i][j] = sum;
				else {
					sum += sol[i - 1][j];
					sol[i][j] = sum;
				}
			}
		}
		cout << sol[k][n] << endl;
	}
	return 0;
}
