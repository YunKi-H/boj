// https://www.acmicpc.net/problem/15486
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1500001];
int arr[2][1500001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[0][i] >> arr[1][i];
	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i], dp[i - 1]);
		if (i + arr[0][i] > n + 1)
			continue ;
		dp[i + arr[0][i]] = max(dp[i + arr[0][i]], dp[i] + arr[1][i]);
	}
	cout << *max_element(dp, dp + n + 2);
}
