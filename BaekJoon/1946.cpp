/* 그리디 https://www.acmicpc.net/problem/1946 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compare(const void* a,const void* b) {
	return (((pair<int, int>*)a)->first > ((pair<int, int>*)b)->first);
}

int main(void) {
	int T; scanf("%d", &T);
	while (T--) {
		int maxV = 100001;
		int sol = 0;
		int N; scanf("%d", &N);
		vector<pair<int, int>> staff(N, { 0,0 });
		for (int i = 0; i < N; i++) 
			scanf("%d %d", &staff[i].first, &staff[i].second);
		qsort(&staff[0], N, sizeof(pair<int, int>),compare);

		for (int i=0; i<N; i++){
			if (maxV > staff[i].second) {
				maxV = staff[i].second;
				sol++;
			}
		}
		printf("%d\n", sol);
	}
	return 0;
}
