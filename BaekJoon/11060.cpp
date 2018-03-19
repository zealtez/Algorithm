#include <iostream>
using namespace std;

int dp[1001] = { 0 };
int val[1001] = {0};
int main(void)
{
	int T; cin >> T;
	fill_n(dp+1,T-1,999999);
	for (int i = 0; i < T; i++)
		cin >> val[i];
	for (int i = 0; i < T; i++)
		for (int j = 1; j <= val[i]; j++)
		{
			if (dp[i + j] > dp[i] + 1)
				dp[i + j] = dp[i] + 1;
		}
	if (dp[T - 1] == 999999)
		cout << "-1";
	else cout << dp[T-1];
	return 0;
}
