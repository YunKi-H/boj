#include <iostream>
#include <algorithm>
using namespace std;

int	dp[301];
int	a[301];

int	main(void)
{
	int n;

	cin >> n;
	cin >> a[1];
	dp[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		cin >> a[i];

		dp[i] = max(dp[i - 3] + a[i - 1], dp[i - 2]) + a[i];
	}
	cout << dp[n];
}
