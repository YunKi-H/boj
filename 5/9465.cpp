#include <iostream>
#include <algorithm>
using namespace std;

int	dp[2][100001];
int	a[2][100001];

int	main(void)
{
	int	t;
	int	n;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
			cin >> a[0][j];
		for (int j = 1; j <= n; j++)
			cin >> a[1][j];

		dp[0][1] = a[0][1];
		dp[1][1] = a[1][1];

		for (int j = 2; j <= n; j++)
		{
			dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + a[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + a[1][j];
		}
		cout << max(dp[0][n], dp[1][n]) << "\n";
	}
}
