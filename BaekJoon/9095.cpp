#include <iostream>
using namespace std;

int countN = 0;

void make(int sum, int target) {
	if (sum == target)
		countN++;
	else if (sum > target)
		return;
	else {
		make(sum + 1, target);
		make(sum + 2, target);
		make(sum + 3, target);
	}
}

int main(void) {
	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		countN = 0;
		int target; cin >> target;
		make(0, target);
		cout << countN<<endl;
	}
	return 0;
}
