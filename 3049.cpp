#include <iostream>
using namespace std;
long long C(int n, int r);

int main(void)
{
	int T; cin >> T;
	cout << C(T, 4);

	return 0;
}

long long C(int n, int r) {
	if (r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
	long long ans = 1;
	int i;

	for (i = 1; i <= r; i++) {
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}
