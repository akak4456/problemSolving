#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int N, M;
struct Card {
	int x;
	int y;
};
struct Dist {
	Card a;
	Card b;
	int dist;
};
vector<Card> cardVec[26];
vector<Dist> distVec;
bool compareRule(const Dist& a,const Dist& b){
	return ((a.dist < b.dist) || (a.dist == b.dist&&a.a.y+a.b.y < b.a.y + b.b.y)|| (a.dist == b.dist&&a.a.y + a.b.y == b.a.y + b.b.y&&a.a.x + a.b.x < b.a.x + b.b.x));
}
void func(int cardShape) {
	distVec.clear();
	for (int i = 0; i < cardVec[cardShape].size(); i++) {
		for (int j = i + 1; j < cardVec[cardShape].size(); j++) {
			Dist tmp;
			if ((cardVec[cardShape][j].y < cardVec[cardShape][i].y)|| (cardVec[cardShape][j].y == cardVec[cardShape][i].y)&& (cardVec[cardShape][j].x < cardVec[cardShape][i].x)) {
				tmp.a = cardVec[cardShape][j];
				tmp.b = cardVec[cardShape][i];
			}
			else {
				tmp.a = cardVec[cardShape][i];
				tmp.b = cardVec[cardShape][j];
			}
			tmp.dist = (tmp.a.x - tmp.b.x)*(tmp.a.x - tmp.b.x) + (tmp.a.y - tmp.b.y)*(tmp.a.y - tmp.b.y);
			distVec.push_back(tmp);
		}
	}
	sort(distVec.begin(), distVec.end(), compareRule);
	for (int i = 0; i < distVec.size(); i++) {
		if (distVec[i].dist != -1) {
			cout << (char)(cardShape + 65) << " " << distVec[i].a.x << " " << distVec[i].a.y << " " << distVec[i].b.x << " " << distVec[i].b.y << endl;
			for (int j = i + 1; j < distVec.size(); j++) {
				if ((distVec[i].a.x == distVec[j].a.x&&distVec[i].a.y == distVec[j].a.y) ||
					(distVec[i].a.x == distVec[j].b.x&&distVec[i].a.y == distVec[j].b.y) ||
					(distVec[i].b.x == distVec[j].a.x&&distVec[i].b.y == distVec[j].a.y) ||
					(distVec[i].b.x == distVec[j].b.x&&distVec[i].b.y == distVec[j].b.y)) {
					distVec[j].dist = -1;

				}
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 26; i++) {
			cardVec[i].clear();
		}
		cin >> N >> M;
		while(M--) {
			char t1;
			int t2;
			int t3;
			Card tmp;
			cin >> t1 >> t2 >> t3;
			tmp.x = t2;
			tmp.y = t3;
			cardVec[t1 - 65].push_back(tmp);
		}
		for (int i = 0; i < 26; i++) {
			func(i);
		}
	}
}