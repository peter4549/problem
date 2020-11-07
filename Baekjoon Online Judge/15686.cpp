#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>

#define MIN(a, b) a > b ? b : a

using namespace std;

int N, M, chicken_place_count, minimum_city_chicken_distance;
int city[50][50];
pair<int, int> chicken_places[13];

void calculate_chicken_distance(int n) {
	int r = chicken_places[n].first;
	int c = chicken_places[n].second;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			if (city[i][j] > 0) {
				int chicken_distance = abs(r - i) + abs(c - j);
				chicken_distance *= 10;
				if (city[i][j] == 1)
					city[i][j] = chicken_distance;
				else
					city[i][j] = MIN(city[i][j], chicken_distance);
			}
		}
}

int get_city_chicken_distance() {
	int city_chicken_distance(0);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (city[i][j] > 0)
				city_chicken_distance += city[i][j];

	return city_chicken_distance;
}

void dfs(int n, int level) {
	if (level == M) {
		minimum_city_chicken_distance = MIN(minimum_city_chicken_distance, get_city_chicken_distance());
		return;
	}

	int copied_city[50][50];

	for (int i = n; i < chicken_place_count; ++i) {
		memcpy(copied_city, city, sizeof(city));
		calculate_chicken_distance(i);
		dfs(i + 1, level + 1);
		memcpy(city, copied_city, sizeof(city));
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			scanf("%d", &city[i][j]);
			
			if (city[i][j] == 2) {
				city[i][j] = -1;
				chicken_places[chicken_place_count++] = make_pair(i, j);
			}
		}
	minimum_city_chicken_distance = 125000000;
	dfs(0, 0);

	printf("%d", minimum_city_chicken_distance / 10);

	return 0;
}
