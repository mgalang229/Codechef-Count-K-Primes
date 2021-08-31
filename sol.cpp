#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5;

vector<int> Sieve(int n) {
	// for every prime number, increment all of its multiples (including itself) by 1 that are <= 'n'
	vector<int> prime(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		if (prime[i] == 0) {
			for (int j = i ; j <= n; j += i) {
				prime[j] += 1;
			}
		}
	}
	return prime;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// precompute the prime numbers for every number ung SoE (Sieve of Eratosthenes)
	vector<int> prime = Sieve(MAX + 1);
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b, k;
		cin >> a >> b >> k;
		int cnt = 0;
		for (int i = a; i <= b; i++) {
			// if the prime factors of 'i' is EXACTLY equal to 'k', then increment 'cnt'
			if (prime[i] == k) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
