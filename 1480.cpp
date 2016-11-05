/*배낭 문제와 같으나, 개수를 구하는 것이므로 index순으로 진행할 수 는 없다.
https://www.acmicpc.net/problem/1480 보석의 상태를 S로 bitMask로 표현*/

#include <iostream>
#include <cstring>
#define MAX(a,b)(a>b?a:b)

using namespace std;

int N, M, C;
int dia[15];
int dp[12][22][1<<15]; //dp[M][C][1<<N]

int sol(int bag, int cap, int s) {
	if (bag == (M+1)) return 0;
	
	int &ret = dp[bag][cap][s];
	if (ret != -1) return ret;

	ret =  sol(bag + 1, 0, s);
	for (int i = 0; i < N; i++) 
		if ((s & (1 << i)) == 0 && (cap + dia[i] <= C)) 
			ret = MAX(ret, sol(bag, cap + dia[i], (s | (1 << i))) + 1);

	return ret;
}

int main(void) {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &N, &M, &C);
	for (int i = 0; i < N; i++)
		scanf("%d", &dia[i]);
	//입력정리

	cout<<sol(1, 0, 0);
	return 0;
}
