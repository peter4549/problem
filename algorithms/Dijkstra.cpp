#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define GRAPH_SIZE 8
#define INF INT_MAX;

int D[GRAPH_SIZE];
vector<pair<int, int>> G[GRAPH_SIZE];

void dijkstra(int source) {
	D[source] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(source, 0));

	while (!pq.empty()) {
		int u = pq.top().first;
		int w = -pq.top().second;
		pq.pop();

		if (D[u] < w)
			continue;

		for (int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i].first;
			int alt = w + G[u][i].second;

			if (alt < D[v]) {
				D[v] = alt;
				pq.push(make_pair(v, -alt));
			}
		}
	}
}

int main() {
	for (int i = 0; i < GRAPH_SIZE; ++i)
		D[i] = INF;

	G[0].push_back(make_pair(1, 2));
	G[0].push_back(make_pair(2, 1));

	G[1].push_back(make_pair(2, 2));
	G[1].push_back(make_pair(3, 5));
	G[1].push_back(make_pair(4, 1));

	G[2].push_back(make_pair(1, 2));
	G[2].push_back(make_pair(3, 3));
	G[2].push_back(make_pair(4, 2));

	G[3].push_back(make_pair(1, 5));
	G[3].push_back(make_pair(2, 3));
	G[3].push_back(make_pair(4, 3));
	G[3].push_back(make_pair(5, 1));
	G[3].push_back(make_pair(6, 5));

	G[4].push_back(make_pair(1, 1));
	G[4].push_back(make_pair(2, 2));
	G[4].push_back(make_pair(3, 3));
	G[4].push_back(make_pair(5, 1));
	G[4].push_back(make_pair(7, 2));

	G[5].push_back(make_pair(3, 1));
	G[5].push_back(make_pair(4, 1));
	G[5].push_back(make_pair(6, 2));

	G[6].push_back(make_pair(3, 5));
	G[6].push_back(make_pair(5, 2));
	G[6].push_back(make_pair(7, 1));

	G[7].push_back(make_pair(4, 2));
	G[7].push_back(make_pair(6, 1));

	dijkstra(0);

	for (int i = 0; i < GRAPH_SIZE; ++i)
		printf("%d ", D[i]);
}
