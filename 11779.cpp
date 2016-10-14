#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct edge {
	int to, cost;
	edge(int ato,int acost):to(ato),cost(acost){}
};
const int inf = 100000;
bool visit[1001];
int d[1001], v[1001];

vector<edge> a[1001];

int main(void) {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		a[x].push_back(edge(y, z));
	}
	int start, end; scanf("%d %d", &start, &end);
	for (int i = 1; i <= N; i++)
		d[i] = inf;
	//입력 정리
	 d[start] = 0;
	for (int k = 0; k < N - 1; k++) {
		int m = inf + 1;
		int x = -1;
		for (int i = 1; i <= N; i++) {
			if (visit[i] == false && m > d[i]) {
				m = d[i];
				x = i;
			}
		}
		visit[x] = 1;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i].to;
			if (d[y] > d[x] + a[x][i].cost) {
				d[y] = d[x] + a[x][i].cost;
				v[y] = x;
			}
		}
	}
	int x = end;
	stack<int> route;
	while (x != start) {
		route.push(x);
		x = v[x];
	}
	route.push(start);
	printf("%d\n%d\n", d[end],route.size());
	while (!route.empty()) {
		printf("%d ", route.top());
		route.pop();
	}

	return 0;
}
