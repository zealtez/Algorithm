/*그리디 https://www.acmicpc.net/problem/2217 */
#include <iostream>
#include <algorithm>
#define MAX(a,b)(a>b?a:b)
using namespace std;

int main(void) {
	int N; scanf("%d", &N);
	int rope[100001];
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		scanf("%d", rope + i);
	}
	sort(rope+1, rope + N+1);
	//입력정리 
	for (int i = 0,j=1; i < N; i++) {
		int minV = rope[N - i];
		while (j < minV*(i+1)) {
			j++;
		}
		ans = MAX(ans, j);
	}
	cout << ans;
	return 0;
}
