#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
	int start, to, cost;
};

int p[1001];

int find(int x) {
	if (x == p[x]) 
		return x;
	else 
		return p[x] = find(p[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	p[x] = y;
}

int main(void) {
	int T; scanf("%d", &T);
	while (T--) {
		int N, M; scanf("%d %d", &N, &M);
		
		for (int i = 1; i <= N; i++)
			p[i] = i;

		vector<edge> a(M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &a[i].start, &a[i].to);
		}

		int ans = 0;
		for (int i = 0; i < M; i++) {
			edge e = a[i];
			int x = find(e.start);
			int y = find(e.to);
			if (x != y) {
				uni(e.start, e.to);
				ans += 1;
			}
		}
		cout << ans<<endl;
	}
	return 0;
}
