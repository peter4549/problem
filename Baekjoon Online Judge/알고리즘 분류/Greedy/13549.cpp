#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> dw[1001];

int main() {
	int N, max(0);

	scanf("%d", &N);

	for (int i(0); i < N; ++i) {
		int d, w;

		scanf("%d %d", &d, &w);
		dw[d].push(w);
	}

	for (int i(1000); i > 0; --i) {
		if (dw[i].empty())
			continue;

		max += dw[i].top();
		dw[i].pop();

		if (i == 1)
			break;

		while (!dw[i].empty()) {
			dw[i - 1].push(dw[i].top());
			dw[i].pop();
		}
	}

	printf("%d \n", max);
		
	return 0;
}
