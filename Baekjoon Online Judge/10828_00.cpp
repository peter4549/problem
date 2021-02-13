#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int N, n;
	stack<int> s;
	string command;

	cin >> N;

	for (int i(0); i < N; ++i) {
		cin >> command;

		if (command == "empty")
			cout << s.empty() << endl;
		else if (command == "pop") {
			if (s.empty())
				cout << -1 << endl;
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (command == "push") {
			cin >> n;
			s.push(n);
		}
		else if (command == "size")
			cout << s.size() << endl;
		else if (command == "top") {
			if (s.empty())
				cout << -1 << endl;
			else
			    cout << s.top() << endl;
		}
	}

	return 0;
}
