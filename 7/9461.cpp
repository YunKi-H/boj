#include <iostream>
using namespace std;

long	dp[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };

int	main(void)
{
	int	t, n;

	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 6; i <= n; i++)
			dp[i] = dp[i - 5] + dp[i - 1];
		cout << dp[n] << "\n";
	}
}
