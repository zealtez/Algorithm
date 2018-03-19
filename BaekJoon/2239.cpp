#include <iostream>
using namespace std;

int main() {
	int n, money, coin[101];
	int d[10001];

	cin >> n; cin >> money;
	for (int i = 0; i<n; i++)
		cin >> coin[i];

	

	for (int i = 0; i <= money; i++)
		d[i] = 0;
	d[0] = 1;
	for (int i = 0; i<n; i++) {
		for (int j = coin[i]; j <= money; j++)
			d[j] += d[j - coin[i]];
	}
	cout << d[money] << endl;
	return 0;
}
