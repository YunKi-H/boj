// https://www.acmicpc.net/problem/1541
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;
int ans, tmp;
int sign = 1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			ans += tmp * sign;
			tmp = 0;
			if (str[i] == '-')
				sign = -1;
		}
		else
		{
			tmp *= 10;
			tmp += str[i] - '0';
		}
	}
	ans += tmp * sign;
	cout << ans;
}
