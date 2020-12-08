#include <cstdio>
#include <algorithm>

using namespace std;

long long A[1001];

int main() {
	int n, m, i;
	long long a(0);

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; ++i)
		scanf("%d", &A[i]);

	for (i = 0; i < m; ++i) {
		sort(A, A + n);
		a = A[0] + A[1];
		A[0] = a;
		A[1] = a;
	}

	a = 0;

	for (i = 0; i < n; ++i)
		a += A[i];

	printf("%lld", a);
		
    return 0;
}
