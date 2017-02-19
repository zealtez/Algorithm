#include <iostream>
#include <cstring>
#define MAX(a,b)(a>b?a:b)
using namespace std;
typedef long long LL;

int N;
LL cake[2001];
LL dp[2001][2001][2];

int findIndex(int left, int right) {
	return cake[left] > cake[right] ? left : right;
}

LL sol(int L, int R, bool JOI) {
	if (L < 0 || R < 0 || L == N || R == N) return 0;
	if (L == R) {
		if (N % 2)
			return cake[L];
		else
			return 0;
	}

	LL &ret = dp[L][R][JOI];
	if (ret != -1) return ret;
	
	ret = 0;
	if (L == N - 1 && R == 0) {
		if (JOI)
			ret = MAX(sol(0, R, 0) + cake[L], sol(L, N-1, 0) + cake[R]);
		else {
			if (L == findIndex(L, R))
				ret = MAX(sol(0, R, 1), ret);
			else
				ret = MAX(sol(L, N - 1, 1), ret);
		}
	}
	else if (L == N-1) {
		if(JOI)
			ret = MAX(sol(0, R, 0) + cake[L], sol(L, R - 1, 0) + cake[R]);
		else {
			if (L == findIndex(L, R))
				ret = MAX(sol(0, R, 1), ret);
			else
				ret = MAX(sol(L, R - 1, 1), ret);
		}
	}
	else if (R == 0) {
		if(JOI)
			ret = MAX(sol(L + 1, R, 0) + cake[L], sol(L, N - 1, 0) + cake[R]);
		else {
			if (L == findIndex(L, R))
				ret = MAX(sol(L + 1, R, 1), ret);
			else
				ret = MAX(sol(L, N - 1, 1), ret);
		}
	}
	else {
		if (JOI)
			ret = MAX(sol(L + 1, R, 0) + cake[L], sol(L, R - 1, 0) + cake[R]);
		else {
			if (L == findIndex(L, R))
				ret = MAX(sol(L + 1, R, 1), ret);
			else
				ret = MAX(sol(L, R - 1, 1), ret);
		}

	}
	return ret;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &cake[i]);
	memset(dp, -1, sizeof(dp));
	//입력정리

	LL ans = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			ans = MAX(ans, sol(i + 1, N - 1, 0) + cake[i]);
		}
		else if (i == N - 1) {
			ans = MAX(ans, sol(0, i - 1, 0) + cake[i]);
		}
		else {
			ans = MAX(ans, sol(i + 1, i - 1, 0) + cake[i]);
		}
	}
	cout << ans;
	return 0;
}
