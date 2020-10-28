#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string N, integer("");
	bool afterMinus(false);
	int answer(0);
	
	cin >> N;

	for (int i = 0; i <= N.size(); ++i) {
		if (N[i] == '-' || N[i] == '+' || N[i] == '\0') {
			if (afterMinus)
				answer -= stoi(integer);
			else
				answer += stoi(integer);

			if (N[i] == '-')
				afterMinus = true;

			integer = "";
			continue;
		}

		integer += N[i];
	}

	printf("%d", answer);

	return 0;
}
