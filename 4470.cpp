#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int T; cin >> T;
	cin.ignore();
	string *text = new string[T];
	for (int i = 0; i < T; i++)
	{
		getline(cin, text[i]);
		cin.clear();
	}
	
	for (int i = 0; i < T; i++)
	{
		cout << i + 1 << ". " << text[i] << endl;
	}

	delete[] text;
	return 0;
}

