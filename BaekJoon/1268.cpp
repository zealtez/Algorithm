/*https://www.acmicpc.net/problem/1268*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX(a,b)(a>b?a:b)
using namespace std;

int N;
int stu[1002][5];

int main(void) {

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) 
		for (int j = 0; j < 5; j++) 
			scanf("%d", &stu[i][j]);

	bool visit[1002][1002] = { false, };

	//입력 정리
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 5; j++) {
			int w = stu[i][j];
			for (int k = 1; k <= N; k++) {
				if (k == i || visit[i][k]) continue;
				if (w == stu[k][j])
					visit[i][k] = true;
			}
		}
	}
	int max_V = 0, index = 1;
	for (int i = 1; i <= N; i++) {
		int value = 0;
		for (int j = 1; j <= N; j++) {
			if (visit[i][j])
				value++;
		}
		if (max_V < value) {
			max_V = value;
			index = i;
		}
	}
	printf("%d", index);
	return 0;
}
