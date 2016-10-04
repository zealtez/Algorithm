#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int count = 0;
	string str;
	while (getline(cin,str)) {
		if (cin.bad())
			break;
		count++;
	}
	cout << count;
	return 0;
}
