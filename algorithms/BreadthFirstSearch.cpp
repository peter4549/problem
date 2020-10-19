#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define GRAPH_SIZE 8

bool visited[GRAPH_SIZE];
vector<int> graph[GRAPH_SIZE];


void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;

	while (!q.empty()) {
		int x = q.front();
		visited[x] = true;
		q.pop();

		cout << x << ' ';

		for (int i = 0; i < graph[x].size(); ++i) {
			int y = graph[x][i];

			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {
	graph[0].push_back(1);
	graph[1].push_back(0);

	graph[0].push_back(2);
	graph[2].push_back(0);

	graph[1].push_back(2);
	graph[2].push_back(1);

	graph[1].push_back(3);
	graph[3].push_back(1);

	graph[1].push_back(4);
	graph[4].push_back(1);

	graph[2].push_back(5);
	graph[5].push_back(2);

	graph[2].push_back(6);
	graph[6].push_back(2);

	graph[3].push_back(4);
	graph[4].push_back(3);

	graph[5].push_back(6);
	graph[6].push_back(5);

	graph[3].push_back(7);
	graph[7].push_back(3);

	bfs(0);

	return 0;
}
