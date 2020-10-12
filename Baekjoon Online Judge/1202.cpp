#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> gems[300000];
int C[300000];

int main() {

	int N, K, i(0), j(0);
	long long sum(0);
	priority_queue<int> priorityQueue;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; ++i)
		scanf("%d %d", &gems[i].first, &gems[i].second);

	for (i = 0; i < K; ++i)
		scanf("%d", &C[i]);

	sort(gems, gems + N);
	sort(C, C + K);

	for (i = 0, j = 0; i < K; ++i) {
		while (j < N && gems[j].first <= C[i])
			priorityQueue.push(gems[j++].second);

		if (!priorityQueue.empty()) {
			sum += priorityQueue.top();
			priorityQueue.pop();
		}
	}

	printf("%lld", sum);

	return 0;
}
