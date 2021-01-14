#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int main() {
	stack<int> s;
	int N;
    scanf("%d", &N);

	for (int i(0); i < N; ++i) {
		char command[6];
		scanf("%s", command);
		
		if (!strcmp(command, "push")) {
			int j;
			scanf("%d", &j);
			s.push(j);
		}
		else if (!strcmp(command, "pop")) {
			if (s.empty()) {
				printf("-1 \n");
				continue;
			}

			printf("%d \n", s.top());
			s.pop();
		}
		else if (!strcmp(command, "size"))
			printf("%d \n", s.size());
		else if (!strcmp(command, "empty"))
			printf("%d \n", s.empty());
		else if (!strcmp(command, "top")) {
			if (s.empty()) {
				printf("-1 \n");
				continue;
			}

			printf("%d \n", s.top());
		}
	}

	return 0;
}
