#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_vps(string ps) {
	stack<char> s;

	for (auto& it : ps)
		if (it == '(')
			s.push(it);
		else
			if (!s.empty())
				s.pop();
			else
				return false;

	if (s.empty())
		return true;
	else
		return false;
}

int main() {
	int T;
	string ps;
	cin >> T;

	for (int i(0); i < T; ++i) {
		cin >> ps;

		if (is_vps(ps))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
