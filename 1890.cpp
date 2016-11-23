#include <iostream>
#include <cstring>
using namespace std;

int n;
int board[101][101];
long long dp[200][200] = { 0 };

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			int jump = board[i][j];
			int nextX = i + jump;
			int nextY = j + jump;
			if (jump == 0) continue;
			if (dp[i][j] == 0)continue;

			if (i == 0 || j == 0) {
				dp[i][nextY] += dp[0][0];
				dp[nextX][j] += dp[0][0];
			}
			else {
				dp[i][nextY] += dp[i][j];
				dp[nextX][j] += dp[i][j];
			}
		}
	}

	cout << dp[n - 1][n - 1];
}
