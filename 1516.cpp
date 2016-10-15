/* 위상정렬 기본*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX(a,b)(a>b?a:b)
using namespace std;

int N, ind[502], val[502] = { 0, };
int d[502] = { 0, };
vector<int> a[502];

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int num; scanf("%d",&num); 
		d[i] = num;
		while (1) {
			scanf("%d", &num);
			if (num == -1) break;
			a[num].push_back(i);
			ind[i]++;
		}
	}//입력정리 
	
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (ind[i] == 0) {
			q.push(i);
			val[i] = d[i]; //고립된 노드에 초기값 넣기
		}

	for (int k = 0; k < N; k++) {
		int x = q.front(); q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			ind[y] -= 1;
			val[y] = MAX(val[y], val[x]+d[y]);
			if (ind[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", val[i]);
	return 0;
}
