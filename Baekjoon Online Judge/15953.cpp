#include <cstdio>

int main() {
	int T, a, b, reward;

	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		scanf("%d %d", &a, &b);

		reward = 0;

		if (a <= 0)
			reward += 0;
		else if (a == 1)
			reward += 500;
		else if (a <= 3)
			reward += 300;
		else if (a <= 6)
			reward += 200;
		else if (a <= 10)
			reward += 50;
		else if (a <= 15)
			reward += 30;
		else if (a <= 21)
			reward += 10;

		if (b <= 0)
			reward += 0;
		else if (b == 1)
			reward += 512;
		else if (b <= 3)
			reward += 256;
		else if (b <= 7)
			reward += 128;
		else if (b <= 15)
			reward += 64;
		else if (b <= 31)
			reward += 32;

		printf("%d\n", reward * 10000);
	}

	return 0;
}
