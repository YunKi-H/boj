// https://www.acmicpc.net/problem/1915
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int dp[1001][1001];
string map[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dp[i][j] = map[i][j] - '0';
			if (i && j && dp[i][j] && dp[i][j - 1] && dp[i - 1][j] && dp[i - 1][j - 1])
				dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
			if (ans < dp[i][j])
				ans = dp[i][j];
		}
	}
	cout << ans * ans;
}
