#include <cstdio>
#include <vector>

using namespace std;

const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Fireball {
	int r, c;
	int m, s, d;
};

int K, M, N, m;
vector<Fireball> v;
vector<int> grid[50][50];

void move() {
	vector<int> copy[50][50];

	for (int i(0); i < v.size(); ++i) {
		int d(v[i].d);
		int s(v[i].s % N);
		int r((v[i].r + (dy[d] * s) + N) % N);
		int c((v[i].c + (dx[d] * s) + N) % N);

		copy[r][c].push_back(i);
		v[i].r = r;
		v[i].c = c;
	}

	for (int r(0); r < N; ++r)
		for (int c(0); c < N; ++c)
			grid[r][c] = copy[r][c];
}

void sum() {
	vector<Fireball> copy;

	for (int r(0); r < N; ++r) {
		for (int c(0); c < N; ++c) {
			if (grid[r][c].size() == 0)
				continue;

			if (grid[r][c].size() == 1) {
				copy.push_back(v[grid[r][c][0]]);
				continue;
			}

			bool all_even(true), all_odd(true);
			int m(0), s(0);

			for (int i(0); i < grid[r][c].size(); ++i) {
				int j(grid[r][c][i]);

				m += v[j].m;
				s += v[j].s;

				if (v[j].d % 2 == 0)
					all_odd = false;
				else
					all_even = false;
			}

			m /= 5;
			
			if (m == 0)
				continue;

			s /= grid[r][c].size();

			for (int i(0); i < 4; ++i) {
				if (all_even || all_odd)
					copy.push_back({ r, c, m, s, i * 2 });
				else
					copy.push_back({ r, c, m, s, i * 2 + 1 });
			}
		}
	}

	v = copy;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i(0); i < M; ++i) {
		int r, c, m, d, s;
		scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
		v.push_back({ --r, --c, m, s, d });
		grid[r][c].push_back(i);
	}

	while (K--) {
		move();
		sum();
	}

	int sum(0);

	for (auto& it : v)
		sum += it.m;

	printf("%d \n", sum);

	return 0;
}
