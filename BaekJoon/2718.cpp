#include <iostream>
#include <cstring>
using namespace std;

long long D[1001][17] = { 0 };
int main(void)
{
	int T; cin >> T;
	D[0][16] = 1;
	for (int i = 1; i <= 1001; i++)
	{
		D[i][1] = D[i - 1][16];
		D[i][2] = D[i - 1][14];
		D[i][3] = D[i - 1][15];
		D[i][4] = D[i - 1][13];
		D[i][5] = D[i - 1][12];
		D[i][6] = D[i - 1][8]+D[i - 1][16];
		D[i][7] = D[i - 1][11] + D[i - 1][16];
		D[i][8] = D[i - 1][6] + D[i - 1][16];
		D[i][9] = D[i - 1][10];
		D[i][10] = D[i - 1][9];
		D[i][11] = D[i - 1][7];
		D[i][12] = D[i - 1][3] +D[i - 1][5] + D[i - 1][14];
		D[i][13] = D[i - 1][4] + D[i - 1][12];
		D[i][14] = D[i - 1][2] + D[i - 1][12] + D[i - 1][15];
		D[i][15] = D[i - 1][3] + D[i - 1][14];
		D[i][16] = D[i - 1][1] +D[i - 1][6] + D[i - 1][7] + D[i - 1][8] +D[i-1][16];
	}
	while (T--) {
		int n; cin >> n;
		cout << D[n][16]<<endl;
	}
	return 0;
}
