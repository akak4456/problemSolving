#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
int T;
int N;
map<string, set<int> >nameToIdSet;
set<int> dupSet;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		nameToIdSet.clear();
		dupSet.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			int num;
			string name;
			cin >> num >> name;
			map<string, set<int> >::iterator it = nameToIdSet.find(name);
			if (it == nameToIdSet.end()) {
				set<int> tmp;
				tmp.insert(num);
				nameToIdSet.insert(make_pair(name,tmp));
				tmp.clear();
			}
			else {
				set<int>::iterator it2 = (it->second).find(num);
				if (it2 == (it->second).end()) {
					(it->second).insert(num);
				}
				else {
					dupSet.insert(num);
				}
			}
		}
		int H = 0;
		for (map<string, set<int> >::iterator it = nameToIdSet.begin(); it != nameToIdSet.end(); it++) {
			if ((it->second).size() > 1) {
				H += (it->second).size();
			}
		}
		cout << dupSet.size() << " " << H << endl;
	}
}