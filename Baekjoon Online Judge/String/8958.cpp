#include <cstdio>
#include <cstring>

int main() {
	int T;
	scanf("%d", &T);

	for (int t(0); t < T; ++t) {
		char string[81];
		int score(0), unit(1);

		scanf("%s", string);

		for (int i(0); i < strlen(string); ++i) {
			if (string[i] == 'O') {
				score += unit;
				++unit;
			}
			else if (string[i] == 'X') {
				unit = 1;
			}
		}

		printf("%d \n", score);
	}

	return 0;
}
