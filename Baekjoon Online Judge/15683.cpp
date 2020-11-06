#include <cstdio>
#include <cstring>

#define MIN(a, b) a > b ? b : a

using namespace std;

struct CCTV {
	int y, x, type;
};

int N, M, cctv_count, min(64);
int office[8][8], rotations_count[5] = { 4, 2, 4, 4, 1 };
CCTV cctvs[8];

void watch(int y, int x, int d) {
	d = d % 4;

	if (d == 0) {
		for (int i = y - 1; i >= 0; --i) {
			if (office[i][x] == 6)
				break;

			office[i][x] = -1;
		}
	}
	else if (d == 1) {
		for (int i = x + 1; i < M; ++i) {
			if (office[y][i] == 6)
				break;

			office[y][i] = -1;
		}
	}
	else if (d == 2) {
		for (int i = y + 1; i < N; ++i) {
			if (office[i][x] == 6)
				break;

			office[i][x] = -1;
		}
	}
	else if (d == 3) {
		for (int i = x - 1; i >= 0; --i) {
			if (office[y][i] == 6)
				break;

			office[y][i] = -1;
		}
	}
}

void dfs(int n) {
	if (n == cctv_count) {
		int count(0);

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				if (!office[i][j])
					++count;
			}

		min = MIN(min, count);

		return;
	}

	CCTV cctv = cctvs[n];

	for (int i = 0; i < rotations_count[cctv.type - 1]; ++i) {
		int cache[8][8] = { 0, };
		memcpy(cache, office, sizeof(office));
		
		if (cctv.type == 1)
			watch(cctv.y, cctv.x, i);
		else if (cctv.type == 2) {
			watch(cctv.y, cctv.x, i);
			watch(cctv.y, cctv.x, i + 2);
		}
	    else if (cctv.type == 3) {
			watch(cctv.y, cctv.x, i);
			watch(cctv.y, cctv.x, i + 1);
		}
		else if (cctv.type == 4) {
			watch(cctv.y, cctv.x, i);
			watch(cctv.y, cctv.x, i + 1);
			watch(cctv.y, cctv.x, i + 2);
		}
		else if (cctv.type == 5) {
			watch(cctv.y, cctv.x, i);
			watch(cctv.y, cctv.x, i + 1);
			watch(cctv.y, cctv.x, i + 2);
			watch(cctv.y, cctv.x, i + 3);
		}

		dfs(n + 1);
		memcpy(office, cache, sizeof(office));
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			scanf("%d", &office[i][j]);
			
			if (office[i][j] > 0 && office[i][j] < 6) {
				CCTV cctv;
				cctv.y = i;
				cctv.x = j;
				cctv.type = office[i][j];
                cctvs[cctv_count++] = cctv;
			}
		}

	dfs(0);

	printf("%d", min);

	return 0;
}
