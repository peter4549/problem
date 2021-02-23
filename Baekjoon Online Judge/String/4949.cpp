#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_vps(string ps) {
	stack<char> s;

	for (auto& it : ps) {
		if (it == '(' || it == '[')
			s.push(it);
		else if (it == ')') {
			if (s.empty())
				return false;
			else if (s.top() == '(')
				s.pop();
			else
				return false;
		}
		else if (it == ']') {
			if (s.empty())
				return false;
			else if (s.top() == '[')
				s.pop();
			else
				return false;
		}
	}

	return s.empty();
}

int main() {
	string input;

	while (getline(cin, input)) {

		if (input == ".")
			break;

		if (is_vps(input))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}
