#include <iostream>
#include <vector>
using namespace std;
int T;
int n;
vector<int> weight;
vector<int> result;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n;
		weight.clear();
		result.clear();
		for (int i = 1; i <= n; i++) {
			int w;
			cin >> w;
			if (weight.size() == 0) {
				weight.push_back(w);
			}
			else {
				vector<int>::iterator it;
				for (it = weight.begin();; it++) {
					if (w <= *it) {
						weight.insert(it, w);
						break;
					}
					else if (it + 1 == weight.end()) {
						weight.push_back(w);
						break;
					}
				}
			}
			if (i % 2 == 1) {
				result.push_back(weight[i / 2]);
			}
			else {
				result.push_back(weight[i / 2-1]);
			}
		}
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << endl;
	}
}