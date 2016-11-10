#include <iostream>
#include <queue>
using namespace std;

int top, start, goal, up, down;
bool visit[1000001];

int main(void) {
	scanf("%d %d %d %d %d", &top, &start, &goal, &up, &down);
	int const moveNow[2] = { up,-down };
	queue<pair<int, int>> Q;
	Q.push(make_pair(start, 0));
	while (!Q.empty()) {
		int now = Q.front().first;
		int dist = Q.front().second;
		Q.pop();
		visit[now] = true;
		if (now == goal) {
			printf("%d", dist); return 0;
		}
		for (int i = 0; i < 2; i++) {
			int next = now + moveNow[i];
			if (next < 1 || next>top) continue;
			if (visit[next]) continue;
			visit[next] = 1;
			Q.push(make_pair(next, dist + 1));
		}
	}
	printf("use the stairs\n");
	return 0;
}
