#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;

int main() {
	string input;

	while (getline(cin, input) && !input.empty())
		v.push_back(input);

	for (auto& it : v)
		cout << it << endl;

	return 0;
}
