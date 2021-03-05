#include <iostream>
#include <string>

using namespace std;

int main() {
	int i(0);
	string word;

	cin >> word;

	while (i < word.length()) {
		cout << word.at(i++);

		if (i % 10 == 0)
			cout << endl;
	}

	return 0;
}
