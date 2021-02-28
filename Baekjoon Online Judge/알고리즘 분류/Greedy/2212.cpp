#include <algorithm>
#include <cstdio>

using namespace std;

int n[10001], k[10000];

int main() {
	int N, K, min(0);

	scanf("%d", &N);
	scanf("%d", &K);

	for (int i(0); i < N; ++i)
		scanf("%d", &n[i]);

	sort(n, n + N);

	for (int i(0); i < N - 1; ++i)
		k[i] = n[i + 1] - n[i];
	
	sort(k, k + N - 1);

	for (int i(0); i < N - K; ++i)
		min += k[i];

	printf("%d \n", min);

	return 0;
}
