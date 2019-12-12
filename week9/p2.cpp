#include <iostream>
using namespace std;
const int MOD = 1000000007;
int T;
int N, K;
long long int facNum[4001];
long long int fac(long long int n) {
	long long int ret = 1;
	while (n > 1) {
		ret = (ret * n) % MOD;
		n--;
	}
	return ret;
}
long long int pow(long long int a, int b) {
	long long int ret = 1;
	long long int aa = a;
	while (b > 0) {
		if (b % 2 == 1) ret = (ret * aa) % MOD;
		b = b / 2;
		aa = (aa * aa) % MOD;
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	for (int i = 0; i <= 4000; i++) {
		facNum[i] = fac(i);
	}
	while (T--) {
		cin >> N >> K;
		long long int A = facNum[N];
		long long int B = (facNum[N-K]*facNum[K])%MOD;
		long long int result = (A * pow(B, MOD - 2)) % MOD;
		cout << result << endl;
	}
}