// https://www.acmicpc.net/problem/2011
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
	if (n[0] == '0')
	{
		cout << 0;
		return (0);
	}
	len = n.size();
	n = ' ' + n;
	for (int i = 2; i <= len; i++)
	{
		if (n[i] != '0')
			dp[i] += dp[i - 1];
		if (n[i - 1] == '1' || (n[i - 1] == '2' && n[i] <= '6'))
			dp[i] += dp[i - 2];
		dp[i] %= MOD;
	}
	cout << dp[len];
}
