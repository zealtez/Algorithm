#include <iostream>
#include <cstring>
#define MAX(a,b)(a>b?a:b)
using namespace std;

int maxValue;

int sol(int value) {
	maxValue = MAX(value, maxValue);
	if (value == 1)
		return maxValue;

	if (value % 2) {
		return sol((value * 3) + 1);
	}
	else {
		return sol(value / 2);
	}
	return maxValue;
}

int main(void) {
	int T; scanf("%d", &T);
	while (T--) {
		maxValue = 0;
		int N; scanf("%d", &N);
		printf("%d\n", sol(N));
	}
	return 0;
}
