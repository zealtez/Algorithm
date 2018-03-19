#include <iostream>
#include <vector>
#include <queue>
#define MAX(a,b)(a>b?a:b)
using namespace std;

struct Edge {
	int to, cost;
	Edge(int ato, int acost) : to(ato),cost(acost){}
};

int inf = 100000000;
int N, M, X;
int ans[1001] = { 0, };
void dijkstra(int start,vector<Edge> *board) {
	bool check[1001] = { false };
	int dist[1001];
	for (int i = 1; i <= N; i++)
		dist[i] = inf;

	dist[start] = 0;
	for (int k = 0; k < N - 1; k++) {
		int m = inf + 1;
		int x = -1;
		for (int i = 1; i <= N; i++) {
			if (check[i] == false && m > dist[i]) {
				m = dist[i];
				x = i;
			}
		}
		check[x] = true;
		for (int i = 0; i < board[x].size(); i++) {
			int y = board[x][i].to;
			if (dist[y] > dist[x] + board[x][i].cost)
				dist[y] = dist[x] + board[x][i].cost;
		}
	}
	for (int i = 1; i <= N; i++)
		ans[i] += dist[i];
}

int main(void) {
	int sol = 0;
	vector<Edge> a[1001];
	vector<Edge> b[1001];
	scanf("%d %d %d", &N, &M, &X);
	for (int i = 0; i < M; i++) {
		int from, to, cost; scanf("%d %d %d", &from, &to, &cost);
		a[from].push_back(Edge(to, cost));
		b[to].push_back(Edge(from, cost));
	}
	dijkstra(X, a);dijkstra(X, b);
	for (int i = 1; i <= N; i++)
		sol = MAX(sol, ans[i]);
	printf("%d", sol);
	return 0;
}
