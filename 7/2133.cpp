#include <iostream>
using namespace std;

int dp[31] = {1, 0, 3, };

int	main(void)
{
	int	n;

	cin >> n;
	for (int i = 4; i <= n; i += 2)
	{
		dp[i] += dp[i - 2] * 3;
		for (int j = 4; j <= i; j += 2)
			dp[i] += dp[i - j] * 2;
	}
	cout << dp[n];
}
