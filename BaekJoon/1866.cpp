/*https://www.acmicpc.net/problem/1866*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define MIN(a,b)(a>b?b:a)
using namespace std;

int N, heli, car;
int target[3001];
int dp[3001]; // 1-> 지점까지 최소

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &target[i]);

	scanf("%d %d", &car, &heli);
	sort(target+1, target + N+1);
	//입력정리

	for (int i = 1; i <= N; i++) {
		dp[i] = target[i] * car + dp[i - 1];
		for (int j = i, mid = heli; j>0; j--) {
			mid += (target[(i + j + 1)>> 1] - target[j])*car;
			dp[i] = MIN(dp[j - 1] + mid, dp[i]);
		}
	}

	/*for (int i = 0; i < N; i++)
		cout << dp[i] << " ";*/
	cout << dp[N];
	return 0;
}
