#include <iostream>
#include <algorithm>
using namespace std;

int	dp[10001];
int	wine[10001];

int	main(void)
{
	int	n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];
	dp[1] = wine[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + wine[i]);
		dp[i] = max(dp[i], dp[i - 3] + wine[i - 1] + wine[i]);
	}
	cout << dp[n];
	return (0);
}
