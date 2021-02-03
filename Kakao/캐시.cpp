#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cache[31];

int main() {
	int cacheSize, runTime(0);
	vector<string> lru;

	scanf("%d", &cacheSize);
	cin.ignore(256, '\n');

	while (true) {
		string city;
		getline(cin, city);

		if (city == "\0")
			break;

		transform(city.begin(), city.end(), city.begin(), ::tolower);

		auto it = find(lru.begin(), lru.end(), city);

		if (it != lru.end()) {
			runTime += 1;
			lru.erase(it);
		}
		else {
			runTime += 5;

			if (cacheSize == lru.size() && !cacheSize)
				lru.erase(lru.end());
		}

		if (!cacheSize) 
			lru.insert(lru.begin(), city);
	}

	printf("%d", runTime);

	return 0;
}
