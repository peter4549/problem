#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

#define INF 1 << 18

int D[20000];
vector<pair<int, int>> G[300000];

void dijkstra(int source) {
	D[source] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, source));

	while (!pq.empty()) {
		int u = pq.top().second;
		int w = -pq.top().first;
		pq.pop();

		if (D[u] < w)
			continue;

		for (int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i].second;
			int alt = w + G[u][i].first;

			if (alt < D[v]) {
				D[v] = alt;
				pq.push(make_pair(-alt, v));
			}
		}
	}
}

int main() {
	int V, E, K, u, v, w, i;

	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	for (i = 1; i <= V; ++i)
		D[i] = INF;

	for (i = 0; i < E; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(make_pair(w, v));
	}

	dijkstra(K);

	for (i = 1; i <= V; ++i) {
		if (D[i] == INF)
		    printf("INF\n");
		else
		    printf("%d\n", D[i]);
	}
}
