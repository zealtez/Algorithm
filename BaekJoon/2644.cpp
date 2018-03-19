/*BFS 촌수 계산*/
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int N,M;
vector<int> con[101];
int board[101];

int main(void) {
	memset(con, 0, sizeof(con));
	scanf("%d", &N);
	int from, to; scanf("%d %d", &from, &to);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a, b; scanf("%d %d", &a, &b);
		con[a].push_back(b);
		con[b].push_back(a);
	}
	for (int i = 1; i <= 100; i++)
			board[i] = INT_MAX;
	if (from == to) {
		printf("0");
		return 0;
	}
	//입력정리
	queue<int> q;
	q.push(from);
	board[from] = 0;

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		
		for (int i = 0; i < con[here].size(); i++) {
			int there = con[here][i];
			if (board[there] > board[here] + 1) {
				board[there] = board[here] + 1;
				q.push(there);
			}
		}
	}
	if (board[to] == INT_MAX) {
		printf("-1\n");
	}
	else {
		printf("%d", board[to]);
	}
	return 0;
}
