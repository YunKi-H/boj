#include <iostream>
#include <algorithm>
using namespace std;

int	dp[1001];
int	p[1001];

int	main(void)
{
	int	n;
	int	rst = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + p[j]);
	}
	cout << dp[n];
}
