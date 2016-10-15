#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> a[1002];
vector<int> g[1002];
int ind[1002] = { 0, };
bool visit[1002];

int main(void) {
	scanf("%d %d", &N, &M);
	vector<int> rout;
	for (int i = 0; i < M; i++) {
		int cnt; scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int num; scanf("%d", &num);
			a[i].push_back(num);
		}
		for (int j = 0; j < cnt-1; j++) {
			g[a[i][j]].push_back(a[i][j + 1]);
			ind[a[i][j+1]]++;
		}
	}
	//입력정리

	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (ind[i] == 0)
			q.push(i);

	if (q.empty()) {
		printf("0"); return 0;
	}
	for (int k = 0; k < N; k++) {
		if (q.empty()) {
			printf("0"); return 0;
		}
		int x = q.front();
		q.pop();
		visit[x] = true;
		rout.push_back(x);
		for (int i = 0; i < g[x].size(); i++) {
			int y = g[x][i];
			ind[y]--;
			if (ind[y] == 0) {
				if (visit[y]) {
					printf("0"); return 0;
				}
				q.push(y);

			}
		}
	}
	if (rout.size() != N) {
		printf("0");
	}
	else {
		for(auto a : rout){
			printf("%d\n", a);
		}
	}
	
return		0;
}
