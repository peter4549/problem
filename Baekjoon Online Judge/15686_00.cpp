#include <cstdio>
#include <cstdlib>
#include <vector>

#define MIN(a, b) a > b ? b : a

using namespace std;

int N, M, type, minimum_city_chicken_distance;
vector<pair<int, int>> house, chicken_place, picked;

void dfs(int n) {
	if (picked.size() == M) {
		int city_chicken_distance(0);

		for (int i = 0; i < house.size(); ++i) {
			int chicken_distance = 250000;

			for (int j = 0; j < picked.size(); ++j)
				chicken_distance = MIN(chicken_distance, abs(house[i].first - picked[j].first) + abs(house[i].second - picked[j].second));
			
			city_chicken_distance += chicken_distance;
		}

		minimum_city_chicken_distance = MIN(minimum_city_chicken_distance, city_chicken_distance);
	}

	for (int i = n; i < chicken_place.size(); ++i) {
		picked.push_back(chicken_place[i]);
		dfs(i + 1);
		picked.pop_back();
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &type);

			if (type == 1) 
				house.push_back(make_pair(i, j));
			else if (type == 2)
				chicken_place.push_back(make_pair(i, j));
		}
	}

	minimum_city_chicken_distance = 0x7FFFFFFF;
	dfs(0);

	printf("%d", minimum_city_chicken_distance);

	return 0;
}
