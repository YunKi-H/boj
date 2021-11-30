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

		for (int i = 2; i <= n; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + a[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + a[1][i];
		}
		cout << max(dp[0][n], dp[1][n]) << "\n";
	}
}
