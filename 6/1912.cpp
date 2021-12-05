#include <iostream>
#include <algorithm>
using namespace std;

int	dp[100001];
int	a[100001];

int	main(void)
{
	int	n;
	int	res = 0;

	cin >> n;
	cin >> a[1];
	dp[1] = res = a[1];
	for (int i = 2; i <= n; i++)
	{
		cin >> a[i];

		dp[i] = max(dp[i - 1] + a[i], a[i]);
		if (dp[i] > res)
			res = dp[i];
	}
	cout << res;
}
