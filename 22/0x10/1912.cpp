// https://www.acmicpc.net/problem/1912
#include <iostream>
#include <algorithm>
using namespace std;

int n, input, ans = -1000;
int dp[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		dp[i] = max(dp[i - 1] + input, input);
		if (dp[i] > ans)
			ans = dp[i];
	}
	cout << ans;
}
