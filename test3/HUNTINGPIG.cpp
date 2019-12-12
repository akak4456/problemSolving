#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Vertex {
	int idx;
	int H;
	bool visited;
	vector<Vertex*> next;
};
Vertex* vertexs[1000];
int T;
int N, M;
bool sortByH(const Vertex* a, const Vertex* b) {
	return a->H < b->H;
}
void dfs(Vertex* v) {
	cout << v->idx << endl;
	vertexs[v->idx]->visited = true;
	sort(vertexs[v->idx]->next.begin(), vertexs[v->idx]->next.end(), sortByH);
	for (int i = 0; i < vertexs[v->idx]->next.size(); i++) {
		if (vertexs[v->idx]->next[i]->visited == false) {
			dfs(vertexs[v->idx]->next[i]);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			vertexs[i] = new Vertex;
			cin >> vertexs[i]->H;
			vertexs[i]->idx = i;
			vertexs[i]->visited = false;
		}
		for (int i = 0; i < M; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			vertexs[t1]->next.push_back(vertexs[t2]);
			vertexs[t2]->next.push_back(vertexs[t1]);
		}
		while (true) {
			bool allVisited = true;
			int minH = 987654321;
			int minIdx = -1;
			for (int i = 0; i < N; i++) {
				if (vertexs[i]->visited == false) {
					allVisited = false;
					if (vertexs[i]->H < minH) {
						minH = vertexs[i]->H;
						minIdx = i;
					}
				}
			}
			if (allVisited) {
				break;
			}
			dfs(vertexs[minIdx]);
		}
	}
}