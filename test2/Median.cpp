#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int T;
int N;
priority_queue<int, vector<int>, less<int> > maxHeap;
priority_queue<int, vector<int>, greater<int> > minHeap;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		while (!maxHeap.empty()) {
			maxHeap.pop();
		}
		while (!minHeap.empty()) {
			minHeap.pop();
		}
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			if (maxHeap.size() == minHeap.size()) {
				maxHeap.push(input);
			}
			else {
				minHeap.push(input);
			}
			if (!maxHeap.empty()&&!minHeap.empty()&&maxHeap.top() > minHeap.top()) {
				int tmp1 = maxHeap.top();
				maxHeap.pop();
				int tmp2 = minHeap.top();
				minHeap.pop();
				maxHeap.push(tmp2);
				minHeap.push(tmp1);
			}
			cout << maxHeap.top() << " ";
		}
		cout << endl;
	}
}