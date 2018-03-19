/*bfs 귀찮아서 함수 안함.*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, S;
vector<int> front[401];
vector<int> rev[401];

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int from, to; scanf("%d %d", &from, &to);
		front[from].push_back(to);
		rev[to].push_back(from);
	}//입력정리
	scanf("%d", &S);
	while (S--) {
		int start, end; scanf("%d %d", &start, &end);
		queue<int> q;
		bool visit[401] = { false, };
		bool find = false , rfind = false;
		q.push(start);
		while (!q.empty()) {
			int here = q.front();
			visit[here] = true;
			q.pop();
			for (int i = 0; i < front[here].size(); i++) {
				int there = front[here][i];
				if (visit[there]) continue;
				if (there == end) {
					printf("-1\n");
					find = true;
					break;
				}
				q.push(there);
			}
			if (find) break;
		}
		if (!find) {
			memset(visit, false, sizeof(visit));
			q.push(start);
			while (!q.empty()) {
				int here = q.front();
				visit[here] = true;
				q.pop();
				for (int i = 0; i < rev[here].size(); i++) {
					int there = rev[here][i];
					if (visit[there]) continue;
					if (there == end) {
						printf("1\n");
						rfind = true;
						break;
					}
					q.push(there);
				}
				if (rfind) break;
			}
		}
		if (!rfind && !find) {
			printf("0\n");
		}

	}
	return 0;
}
