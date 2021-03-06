#include <cstdio>

int K[21];

int main() {
	int N, M, begin(1), end(1), j, k(0);

	scanf("%d %d", &N, &M);
	scanf("%d", &j);

	end += M - 1;

	for (int i(1); i <= j; ++i)
		scanf("%d", K + i);

	for (int i(1); i <= j; ++i) {
		if (K[i] < begin) {
			k += begin - K[i];
			begin = K[i];
			end = begin + M - 1;
		} else if (K[i] > end) {
			k += K[i] - end;
			end = K[i];
			begin = end - M + 1;
		}
	}

	printf("%d \n", k);

	return 0;
}
