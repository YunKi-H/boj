// https://www.acmicpc.net/problem/11727
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1001] = {0, 1, 3,};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	cout << dp[n];
}
