// https://www.acmicpc.net/problem/9251
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];
string a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	int al = a.length();
	int bl = b.length();
	for (int i = 1; i <= al; i++)
	{
		for (int j = 1; j <= bl; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[al][bl];
}
