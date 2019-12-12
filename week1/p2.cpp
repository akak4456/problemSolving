#include <iostream>
using namespace std;

int T;
int N;
long long int taskStart[1000];
long long int taskExecuteTime[1000];
long long int taskEnd[1000];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> taskStart[i] >> taskExecuteTime[i];
		}
		taskEnd[0] = taskStart[0] + taskExecuteTime[0];
		for (int i = 1; i < N; i++) {
			int a = 0;
			if (taskEnd[i - 1] >= taskStart[i]) {
				taskEnd[i] = taskEnd[i - 1] + taskExecuteTime[i];
			}
			else{
				taskEnd[i] = taskEnd[i - 1] + taskExecuteTime[i] + (taskStart[i] - taskEnd[i - 1]);
			}
		}
		/*
		for (int i = 0; i < N; i++) {
			cout << taskStart[i] << " " << taskEnd[i] << endl;
		}
		*/
		long long int waitingtime = 0;
		for (int i = 1; i < N; i++) {
			if (taskEnd[i - 1] > taskStart[i]) {
				waitingtime += taskEnd[i - 1] - taskStart[i];
			}
		}
		long long int responsetime = 0;
		for (int i = 0; i < N; i++) {
			responsetime += taskEnd[i] - taskStart[i];
		}
		cout << waitingtime/N << " " << responsetime/N << endl;
	}
}