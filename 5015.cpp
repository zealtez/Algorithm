#include<iostream>
#include <string>
#include <cstring>
#include <list>
using namespace std;

int cache[102][102];
list<string> ans;
string W, S;

bool match(int w, int s) {

	int &ret = cache[w][s];
	if (ret != -1)return ret;

	while (s < S.size() && w < W.size() && W[w] == S[s]) {
		++w;
		++s;
	}
	if (w == W.size()) {
		if (s == S.size()) { return ret = 1; }
		else { return ret = 0;}
	}
	if (W[w] == '*')
		for (int next = 0; next + s <= S.size(); ++next)
			if (match(w + 1, s + next)) {return ret = 1;}
	
	return ret = 0;
}

int main(void) {
	
	getline(cin, W);
	int T; cin >> T; cin.clear(); cin.ignore();

	for (int i = 0; i < T; i++) {
		memset(cache, -1, 101 * 101);
		getline(cin, S);
		if (match(0, 0))
			ans.push_back(S);
	}
	while (!ans.empty()) {
		cout << ans.front() << endl; ans.pop_front();
	}
	return 0;
}
