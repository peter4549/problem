#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>

using namespace std;

vector<tuple<int, int, int>> v;

struct Truck {
	int c = 0, max = 0;
	int box[2001] = { 0, };
};

bool compare(tuple<int, int, int>& rhs, tuple<int, int, int>& lhs) {
	if (get<1>(rhs) == get<1>(lhs))
		return get<0>(rhs) < get<0>(lhs);

	return get<1>(rhs) < get<1>(lhs);
}

int main() {
	int N, C, M;

	scanf("%d %d", &N, &C);
	scanf("%d", &M);

	for (int m(0); m < M; ++m) {
		int i, j, k;

		scanf("%d %d %d", &i, &j, &k);
		v.push_back({ i, j ,k });
	}

	sort(v.begin(), v.end(), compare);

	Truck truck;
	
	for (auto& it : v) {
		int box(0), i(get<0>(it)), j(get<1>(it)), k(get<2>(it));

		for (i; i < j; ++i)
			box = max(box, truck.box[i]);

		int u(min(k, C - box));

		truck.max += u;

		for (i = get<0>(it); i < j; ++i)
			truck.box[i] += u;
	}

	printf("%d \n", truck.max);

	return 0;
}
