#include <cstdio>
#include <cstring>

int main() {
	int T, N;
	long long P[101] = { 0, };

	scanf("%d", &T);

	

	for (int t(0); t < T; ++t) {
		scanf("%d", &N);

		memset(P, 0, sizeof(P));
		P[1] = 1, P[2] = 1, P[3] = 1;

		for (int i(4); i <= N; ++i)
			P[i] = P[i - 2] + P[i - 3];

		printf("%lld \n", P[N]);
	}

	return 0;
}
