#include <iostream>
#include <algorithm>
using namespace std;

int	dp[1001][10];

int	main(void)
{
	int	n;
	long long sum = 0;

	cin >> n;
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
				dp[i][j] += dp[i - 1][k];
			dp[i][j] %= 10007;
		}
	}
	for (int i = 0; i <= 9; i++)
		sum += dp[n][i];
	cout << sum % 10007;
}
