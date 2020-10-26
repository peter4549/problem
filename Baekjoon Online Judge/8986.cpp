#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const long long INF = 1e15;

int N;
int X[100000];

inline long long f(int x) {
	long long y = 0;

	for (int i = 1; i < N; ++i)
		y += abs(1LL * x * i - X[i]);
	
	return y;
}

int main() {
	int i, p, q;

	scanf("%d", &N);

	for (i = 0; i < N; ++i)
		scanf("%d", X + i);

	long long lo(0), hi(X[N - 1]);

	while (hi - lo >= 5) {
		p = (2 * lo + hi) / 3;
		q = (lo + 2 * hi) / 3;

		if (f(p) > f(q))
			lo = p;
		else 
			hi = q;
	}

	long long minimumDistanceSum(INF);

	for (i = lo; i <= hi; ++i)
		minimumDistanceSum = min(minimumDistanceSum, f(i));

	printf("%lld", minimumDistanceSum);

	return 0;
}
