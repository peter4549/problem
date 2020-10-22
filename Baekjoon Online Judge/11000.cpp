#include <stdio.h>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int N;
pair<int, int> ST[200001];

bool compare(pair<int, int> first, pair<int, int> second) {
	return first.second < second.second;
}

int main() {
	int i, t, count(1);
	pair<int, int> st;
	
	scanf("%d", &N);
	
	for (i = 0; i < N; ++i)
		scanf("%d %d", &ST[i].first, &ST[i].second);

	sort(ST, ST + N);

	st = ST[0];
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(st.second);

	for (i = 1; i < N; ++i) {
		t = pq.top();

		if (t > ST[i].first) {
			pq.push(ST[i].second);
			++count;
		} else {
			pq.push(ST[i].second);
			pq.pop();
		}
	}

	printf("%d", count);

	return 0;
}
