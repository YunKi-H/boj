#include <iostream>
#include <algorithm>
using namespace std;

int	dp[1001];
int	a[1001];

int	main(void)
{
	int	n;
	int max = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[i])
			{
				if (dp[j] > tmp)
					tmp = dp[j];
			}
		}
		dp[i] = tmp + 1;
		if (dp[i] > max)
			max = dp[i];
	}
	cout << max;
}

