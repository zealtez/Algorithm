#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, Q;
int nums[2001];
int dp[2001][2001];

int go(int i, int j) {
	if (i == j) return 1;
	else if (i + 1 == j) {
		if (nums[i] == nums[j]) return 1;
		else return 0;
	}
	//기저 사례 

	int &ret = dp[i][j];
	if (ret != -1) return ret; //메모제이션

	if (nums[i] != nums[j]) return ret = 0;
	else return ret = go(i + 1, j - 1);
}

int main(void) {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d", &nums[i]);
	go(1, N);

	scanf("%d", &Q);
	while (Q--) {
		int from, to; scanf("%d%d", &from, &to);
		cout << dp[from][to] << endl;
	}


	return 0;
}
