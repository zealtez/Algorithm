/*https://www.acmicpc.net/problem/1865*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int from;
	int end;
	int cost;
};

int main(void) {
	int T; scanf("%d", &T);
	while (T--) {
		int N, M, W; scanf("%d %d %d", &N, &M, &W);
		int inf = 100000000;
		int dist[501];
		
		vector <edge> a(2*M+W);
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &a[i].from, &a[i].end, &a[i].cost);
			a[i + M] = a[i];
			swap(a[i + M].from, a[i + M].end);
		}
		for (int i = 2*M; i < 2*M+W; i++) {
			scanf("%d %d %d", &a[i].from, &a[i].end, &a[i].cost);
			a[i].cost *= -1;
		}
		for (int i = 1; i <= N; i++)
			dist[i] = inf;

		M =2* M + W;
		dist[1] = 0;
		bool flag = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				int x = a[j].from;
				int y = a[j].end;
				int z = a[j].cost;
				if (dist[x] != inf && dist[y] > dist[x] + z) {
					dist[y] = dist[x] + z;
					if (i == N)
						flag = true;
				}
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
