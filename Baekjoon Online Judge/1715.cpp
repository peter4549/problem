#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int N;
	long long count(0);
	priority_queue<int, vector<int>, greater<int>> pq;
	scanf("%d", &N);

	if (N < 2) {
		printf("0");
		return 0;
	}

	for (int i(0); i < N; ++i) {
		int n;
		scanf("%d", &n);
		pq.push(n);
	}

	while (true) {
		int p = pq.top();
		pq.pop();
		int q = pq.top();
		pq.pop();
		int r(p + q);
		count += r;
		
		if (pq.empty())
			break;

		pq.push(r);
	}

	printf("%lld", count);

	return 0;
}
