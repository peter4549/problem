#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

typedef pair<int, int> p;

p line_array[1000001];

int main() {
	int N;
	scanf("%d", &N);

	for (int i(0); i < N; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		line_array[i] = make_pair(x, y);
	}

	sort(line_array, line_array + N);

	p line(line_array[0]);
	int x(line.first), y(line.second);
	int length(y - x);

	for (int i(1); i < N; ++i) {
		p line(line_array[i]);

		if (y >= line.first) {
			if (line.second - y > 0)
			    length += line.second - y;

			y = max(y, line.second);
		}
		else {
			x = line.first;
			y = line.second;
			length += y - x;
		}
	}

	printf("%d", length);

	return 0;
}
