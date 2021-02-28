#include <cstdio>

#define MAX(a, b) (a > b ? a : b)

int D[100001];

int main() {
	int n, sum(0);

	scanf("%d", &n);

	for (int i(0); i < n; ++i) {
		int m;

		scanf("%d", &m);

		if (i == 0) {
			D[i] = m;
			sum = D[i];
		} else {
			if (D[i - 1] + m > m)
				D[i] = D[i - 1] + m;
			else
				D[i] = m;
		}

		sum = MAX(sum, D[i]);
	}

	printf("%d \n", sum);

	return 0;
}
