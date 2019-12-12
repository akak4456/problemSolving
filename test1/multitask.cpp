#include <iostream>
using namespace std;
int T;
int N;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		long long int currentTime = 0;
		long long int waitingTime = 0;
		long long int responseTime = 0;
		for (int i = 0; i < N; i++) {
			int startTime, cpuTime;
			cin >> startTime >> cpuTime;
			if (currentTime < startTime) {
				currentTime = startTime;
			}
			waitingTime += currentTime - startTime;
			currentTime += cpuTime;
			responseTime += currentTime - startTime;
		}
		cout << waitingTime / N << " " << responseTime / N << endl;
	}
}