#include <stdio.h>

int roots[1000001];

int find(int u) {
	if (u == roots[u])
		return u;

	return roots[u] = find(roots[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v)
		return;

	roots[u] = v;
}

int main() {
	int n, m, i, o, a, b;

	scanf("%d %d", &n, &m);

	for (i = 0; i <= n; ++i)
		roots[i] = i;

	for (i = 0; i < m; ++i) {
		scanf("%d %d %d", &o, &a, &b);
		
		if (o == 1) {
			if (find(a) == find(b))
				printf("YES\n");
			else 
				printf("NO\n");
		} else
			merge(a, b);
	}

	return 0;
}
