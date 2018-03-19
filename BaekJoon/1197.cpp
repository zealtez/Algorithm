#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> p;

int V, E;
bool visit[100001] = { false ,};
vector<p> num[10001];

int main(void) {
	int sol = 0;
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++) {
		int A, B, C; scanf("%d %d %d", &A, &B, &C);
		num[A].push_back(make_pair(C, B));
		num[B].push_back(make_pair(C, A));
	}//입력정리 

	priority_queue<p, vector<p>, greater<p>> q;
	for (int i = 0; i < num[1].size(); i++) {
		q.push({num[1][i].first, num[1][i].second});
	}// 노드 1에 있는 간선 입력
	visit[1] = true;

	while (!q.empty()) {
		p next = q.top();
		q.pop();
		if (visit[next.second] == false) {
			sol += next.first;
			for (int i = 0; i < num[next.second].size(); i++) {
				q.push({ num[next.second][i].first,num[next.second][i].second });
			}
			visit[next.second] = true;
		}
		
	}
	cout << sol;
	return 0;
}
