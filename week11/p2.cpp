#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
소주1병 = 7잔
N 은 최대 80200
*/
struct NodeRelation {
	int node1 = 0;
	int node2 = 0;
	int node3 = 0;
};
int T;
int B, L, N;
double capacity[100000];
double newQuantity[100000];
double quantity[100000];
NodeRelation* noderelation[100000];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	for (int i = 1; i <= 400; i++) {
		for (int j = (i-1)*i/2; j <= i*(i+1)/2; j++) {
			noderelation[j] = new NodeRelation;
			noderelation[j]->node1 = j + 1;
			noderelation[j]->node2 = j + i + 1;
			noderelation[j]->node3 = j + i + 2;
		}
	}
	while (T--) {
		cin >> B >> L >> N;
		quantity[0] = 7.0 * B;
		double ans = 0;
		for (int layer = 0; layer < 400; layer++) {
			for (int i = 0; i < (layer + 2) * (layer + 3) / 2; i++) {
				capacity[i] = 0;
				newQuantity[i] = 0;
			}
			for (int num = 0; num < (layer+1)*(layer+2)/2; num++) {
				if(layer == 100)
				cout << layer+1<<" "<<num+1 << " " << quantity[num] << endl;
				if (capacity[num] + quantity[num] <= 1) {
					capacity[num] += quantity[num];
				}
				else {
					double remain = quantity[num] - (1 - capacity[num]);
					capacity[num] = 1;
					newQuantity[noderelation[num]->node1 - 1] += remain / 3;
					newQuantity[noderelation[num]->node2 - 1] += remain / 3;
					newQuantity[noderelation[num]->node3 - 1] += remain / 3;
				}
			}
			if (layer + 1 == L) {
				ans = capacity[N - 1];
				break;
			}
			for (int i = 0; i < (layer + 2) * (layer + 3) / 2; i++) {
				quantity[i] = newQuantity[i];
			}
		}
		if (ans == 1) {
			cout << 1 << endl;
		}
		else if (ans > 0) {
			cout << 2 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}