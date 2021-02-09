#include <cstdio>

int get(int n) {
	int count(0);

	while (true) {
		if (n <= 5) {
			if (n == 1 || n == 3) {
				count = -1;
				break;
			}
			else if (n == 5) {
				++count;
				break;
			}
			else {
				count += n / 2;
				break;
			}
		}
		else if (n - 5 >= 5) {
			n -= 5;
			++count;
			continue;
		}
		else if ((n - 5) % 2 == 0) {
			n -= 5;
			++count;
			continue;
		}
		else {
			count += n / 2;
			break;
		}
	}

	return count;
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%d", get(n));

	return 0;
}
