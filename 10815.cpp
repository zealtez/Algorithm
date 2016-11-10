/*이분 탐색 set활 https://www.acmicpc.net/problem/10815 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, M;

int main(void) {
	set<int> s;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp; scanf("%d", &temp);
		s.insert(temp);
	}
	scanf("%d", &M);
	//입력 정리
	vector<int> sol;
	for (int i = 0; i < M; i++) {
		int temp; scanf("%d", &temp);
		if (s.count(temp) > 0)
			sol.push_back(1);
		else
			sol.push_back(0);
	}
	for (auto a : sol)
		printf("%d ", a);
	return 0;
}
