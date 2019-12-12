#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map <string, string> list;//number name
vector<string> numberOverlap;
vector<string> names;
int nameOverlap = 0;
int T;
int N;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		list.clear();
		numberOverlap.clear();
		names.clear();
		nameOverlap = 0;
		for (int i = 0; i < N; i++) {
			string t1, t2;
			cin >> t1 >> t2;
			map<string, string>::iterator it = list.find(t1);
			if (it != list.end()) {
				bool isCan = true;
				for (int i = 0; i < numberOverlap.size(); i++) {
					if (numberOverlap[i] == it->first) {
						isCan = false;
						break;
					}
				}
				if (isCan) {
					numberOverlap.push_back(it->first);
				}
			}
			map<string, string>::iterator it2 = list.find(t1);
			if(it2 == list.end()){
				for (it = list.begin(); it != list.end(); it++) {
					if (it->second == t2) {
						if (names.size() == 0) {
							nameOverlap = 2;
							names.push_back(it->second);
						}
						else {
							bool addTwo = true;
							for (int i = 0; i < names.size(); i++) {
								if (names[i] == it->second) {
									addTwo = false;
									break;
								}
							}
							if (addTwo) {
								nameOverlap += 2;
								names.push_back(it->second);
							}
							else {
								nameOverlap++;
							}
						}
						break;
					}
				}
			}
			
			list.insert(make_pair(t1,t2 ));
		}
		cout << numberOverlap.size() << " " << nameOverlap << endl;
	}
}