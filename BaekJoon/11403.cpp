#include <iostream>
#include <cstdio>
using namespace std;


int main() {
	int n, i, j;
	int map[100][100];
	scanf("%d", &n);
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int k = 0; k<n; k++) {
		for (i = 0; i<n; i++) {
			for (j = 0; j<n; j++) {
				if (map[i][j] > 0)
				{
					map[i][j] = 1;
				}
				else
				{
					if (map[i][k] > 0 && map[k][j] > 0) {
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
	}
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			if (map[i][j] >= 1)
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	return 0;
}
