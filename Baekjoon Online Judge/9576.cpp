#include <cstdio>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N;
pair<int, int> ab[1000];
bool books[1001];

int main() {
	int T, N, M, i, j, k, count;
	
	scanf("%d", &T);

	for (i = 0; i < T; ++i) {
		count = 0;

		scanf("%d %d", &N, &M);

		memset(books, true, sizeof(books));

		for (j = 0; j < M; ++j)
			scanf("%d %d", &ab[j].second, &ab[j].first);

		sort(ab, ab + M);

		for (j = 0; j < M; ++j) {
			for (k = ab[j].second; k <= ab[j].first; ++k) {
				if (books[k]) {
					books[k] = false;
					++count;
					break;
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}
