// https://www.acmicpc.net/problem/10942
#include <iostream>
#include <algorithm>
using namespace std;

int dp[2001][2001];
int arr[2001];
int s, e, n, m;

bool solve(int s, int e)
{
	if (dp[s][e])
		return (dp[s][e]);
	if (s == e)
		return (dp[s][e] = 1);
	if (s + 1 == e)
		return (dp[s][e] = (arr[s] == arr[e]));
	if (arr[s] == arr[e] && solve(s + 1, e - 1))
		return (dp[s][e] = 1);
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> m;
	while (m--)
	{
		cin >> s >> e;
		cout << solve(s - 1, e - 1) << '\n';
	}
}
