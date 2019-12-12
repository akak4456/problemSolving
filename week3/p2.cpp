#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
int T;
int N, M;
long long int currentTime;
long long int waitingTime;
long long int responseTime;
struct Process {
	bool isEvent;
	int id;
	int startTime;
	int cpuTime;
	int priority;
};

struct cmp {
	bool operator()(const Process& a, const Process& b) {
		if (a.priority > b.priority) {
			return true;
		}
		else if (a.priority == b.priority) {
			if (a.startTime > b.startTime) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
};
priority_queue<Process, vector<Process>, cmp> readyList;
void execute(const Process& P) {
	if (currentTime < P.startTime) {
		currentTime = P.startTime;
	}
	waitingTime += currentTime - P.startTime;
	currentTime = currentTime+P.cpuTime;
	responseTime += currentTime - P.startTime;
}
void changePriority(const Process& P) {
	vector<Process> tmp;
	while (!readyList.empty()) {
		Process t = readyList.top();
		if (t.id == P.id) {
			t.priority = P.priority;
		}
		tmp.push_back(t);
		readyList.pop();
	}
	while (!tmp.empty()) {
		readyList.push(tmp.back());
		tmp.pop_back();
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		while (!readyList.empty()) {
			readyList.pop();
		}
		currentTime = waitingTime = responseTime = 0;
		cin >> N >> M;
		for (int i = 0; i < N + M; i++) {
			string t1;
			int t2, t3, t4;
			cin >> t1 >> t2 >> t3 >> t4;
			Process P;
			if (t1 == "N") {
				P.isEvent = true;
				P.startTime = t2;
				P.id = t3;
				P.priority = t4;
				P.cpuTime = 0;
			}
			else {
				P.isEvent = false;
				P.id = atoi(t1.c_str());
				P.startTime = t2;
				P.cpuTime = t3;
				P.priority = t4;
			}
			if (P.isEvent == true) {
				if (P.startTime <= currentTime) {
					changePriority(P);
				}
				else {
					while (!readyList.empty() && P.startTime >= currentTime) {
						execute(readyList.top());
						readyList.pop();
					}
					if (P.startTime <= currentTime) {
						changePriority(P);
					}
				}
			}
			else {
				if (P.startTime < currentTime) {
					readyList.push(P);
				}
				else {
					if (readyList.empty()) {
						execute(P);
					}
					else {
						while (!readyList.empty() && P.startTime >= currentTime) {
							execute(readyList.top());
							readyList.pop();
						}
						readyList.push(P);
					}
				}
			}
		}
		while (!readyList.empty()) {
			execute(readyList.top());
			readyList.pop();
		}
		cout << waitingTime / N << " " << responseTime / N << endl;
	}
}