#include <iostream>
#include <string.h>
using namespace std;
#define MOD 1000000

int	dp[5001] = {1, 1, 0, };
string n;

int	main(void)
{
	int	len;

	cin >> n;
	len = n.size();
	n = ' ' + n;
	if (n[1] == '0')
	{
		cout << 0;
		return (0);
	}
	for (int i = 2; i <= len; i++)
	{
		if (n[i] != '0')
			dp[i] += dp[i - 1] % MOD;
		if (n[i - 1] == '1' || n[i - 1] == '2' && n[i] <= '6')
			dp[i] += dp[i - 2] % MOD;
	}
	cout << dp[len] % MOD;
}
