#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <vector>
using namespace std;
vector<string> input;
vector<string> postfix;
stack<long long int> operand;
stack<string> st;
int T;
long long int result;
bool calculate() {
	for (int i = 0; i < input.size(); i++) {
		if (i == 0 && (input[i] == "+" || input[i] == "-")) {
			postfix.push_back("0");
		}
		if (input[i] == "(") {
			st.push("(");
			if (input[i + 1] == "-" || input[i + 1] == "+") {
				postfix.push_back("0");
			}
		}
		else if (input[i] == ")") {
			while (st.top() != "(") {
				postfix.push_back(st.top());
				st.pop();
				if (st.empty()) {
					return false;
				}
			}
			st.pop();
		}
		else if (input[i] == "+" || input[i] == "-") {
			while (!st.empty() && st.top() != "(") {
				postfix.push_back(st.top());
				st.pop();
			}
			st.push(input[i]);
		}
		else {
			postfix.push_back(input[i]);
		}
	}
	while (!st.empty()) {
		if (st.top() == "(") {
			return false;
		}
		postfix.push_back(st.top());
		st.pop();
	}
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] == "+" || postfix[i] == "-") {
			if (operand.size() < 2) {
				return false;
			}
			int operand2 = operand.top();
			operand.pop();
			int operand1 = operand.top();
			operand.pop();
			if (postfix[i] == "+") {
				operand.push(operand1 + operand2);
			}
			else {
				operand.push(operand1 - operand2);
			}
		}
		else {
			operand.push(atoi(postfix[i].c_str()));
		}
	}
	if (operand.size() != 1) {
		return false;
	}
	result = operand.top();
	return true;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin.ignore();
		input.clear();
		postfix.clear();
		while (!st.empty()) {
			st.pop();
		}
		while (!operand.empty()) {
			operand.pop();
		}
		string s;
		while (cin >> s) {
			if (s == "$") {
				break;
			}
			input.push_back(s);
			cin.ignore();
		}
		if (calculate()) {
			cout << result << endl;
		}
		else {
			cout << "N" << endl;
		}
	}
}