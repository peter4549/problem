#include <cstdio>
#include <cmath>

using namespace std;

int dolls[500];

int main() {
	int N, K, i, j;
	double m, v, min(500 * 1E6);

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; ++i)
		scanf("%d", dolls + i);

	while (K <= N) {
		for (i = 0; i < N - K + 1; ++i) {
			m = 0, v = 0;

			for (j = i; j < K + i; ++j)
				m += dolls[j];

			m /= K;

			for (j = i; j < K + i; ++j)
				v += pow(dolls[j] - m, 2);

			v /= K;
			
			if (min > v)
				min = v;
		}

		++K;
	}

	printf("%.6lf", sqrt(min));

	return 0;
}
