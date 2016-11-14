#include <iostream>
#include <cstring>
#include <cmath>
#define MIN(a,b)(a>b?b:a)
#define INFI 100000000001
using namespace std;

const int moveX[5] = { 0,0,0,-1,1 };
const int moveY[5] = { 0,-1,1,0,0 };

int N;
pair<int, int> g[100001];
long long dp[100001][5];

long long sol(int index, int cnt) {
	if (index == N) return 0;

	long long & ret = dp[index][cnt];
	if (ret != -1) return ret;

	ret = INFI;
	int x = g[index].first, y = g[index].second;
	int nx = g[index + 1].first, ny = g[index + 1].second;
	for (int next = 0; next < 5; next++) {
		g[index+1].first =nx+moveX[next], g[index+1].second = ny+moveY[next];
		ret = MIN(ret, sol(index + 1,next) + abs(g[index+1].first - x) + abs(g[index+1].second - y));
		g[index+1].first = nx, g[index+1].second = ny;
	}
	return ret;
}

int main(void) {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 0; i <= N; i++)
		scanf("%d %d", &g[i].first, &g[i].second);
	//입력정리 
	cout << sol(0, 0);
	return 0;
}
