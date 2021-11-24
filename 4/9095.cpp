#include <iostream>
#include <algorithm>
using namespace std;

int	dp[11];

void	solve(int n)
{
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	cout << dp[n] << "\n";
}

int	main(void)
{
	int	t;
	int	n;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = dp[2 - 1] + dp[2 - 2];
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		solve(n);
	}
	return (0);
}
