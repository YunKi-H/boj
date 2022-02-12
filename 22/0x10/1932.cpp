// https://www.acmicpc.net/problem/1932
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[501];
int map[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> map[j];
		for (int j = i; j >= 1; j--)
			dp[j] = max(dp[j] + map[j], dp[j - 1] + map[j]);
	}
	cout << *max_element(dp, dp + n + 1);
}
