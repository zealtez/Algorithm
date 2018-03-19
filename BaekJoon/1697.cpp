#include <iostream>
#include <queue>
#define MAX(a,b)(a>b?b:a)
using namespace std;

int const moveFrom[3] = { 1,-1, 0};
int N, K;
bool visit[1000001];

int main(void) {
	scanf("%d %d", &N, &K);
	int t = 0;
	queue<int> Q;
	Q.push(N);
	visit[N] = true;

	while (1) {
		int qSize = Q.size();
		for (int i = 0; i < qSize; i++) {
			int from = Q.front();
			visit[from] = true;
			Q.pop();
			if (from == K) {
				printf("%d", t);
				return 0;
			}//종료
			for (int k = 0; k < 3; k++) {
				int next;
				if (k == 2) {
					next = from * 2;
				}
				else {
					next = from + moveFrom[k];
				}
				if (next < 0 || next > 1000001) continue;
				if (visit[next]) continue;
				Q.push(next);
			}
		}
		t++;
	}
	scanf("%d %d", &N, &K);
	return 0;
}
