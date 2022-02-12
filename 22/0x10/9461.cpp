// https://www.acmicpc.net/problem/9461
#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
long long dp[101] = {0, 1, 1, 1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 4; i < 101; i++)
		dp[i] = dp[i - 2] + dp[i - 3];
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << dp[n] << '\n';
	}
}
