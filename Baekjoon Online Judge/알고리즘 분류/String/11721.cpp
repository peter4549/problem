#include <iostream>
#include <string>

using namespace std;

int main() {
	string word;

	cin >> word;

	for (int i(1); i <= word.length(); ++i) {
		cout << word.at(i - 1);

		if (i % 10 == 0)
			cout << endl;
	}

	return 0;
}
