#include <iostream>
#include <algorithm>
using namespace std;

int	dp[2][1001];
int	a[1001];

int	main(void)
{
	int	n;
	int	max = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int	asc = 0;

		cin >> a[i];
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
			{
				if (dp[0][j] > asc)
					asc = dp[0][j];
			}
		}
		dp[0][i] = asc + 1;
	}
	for (int i = n; i >= 1; i--)
	{
		int desc = 0;

		for (int j = n; j >= i; j--)
		{
			if (a[j] < a[i])
			{
				if (dp[1][j] > desc)
					desc = dp[1][j];
			}
		}
		dp[1][i] = desc + 1;
		if (dp[0][i] + dp[1][i] > max)
			max = dp[0][i] + dp[1][i] - 1;
	}
	cout << max;
}
