// https://www.acmicpc.net/problem/1431
#include <iostream>
#include <algorithm>
using namespace std;

int n;
string str[50];

bool cmp(string s1, string s2)
{
	int sum1 = 0, sum2 = 0;
	int len1 = s1.length(), len2 = s2.length();
	if (len1 == len2)
	{
		for (int i = 0; i < len1; i++)
			if (s1[i] >= '0' && s1[i] <= '9')
				sum1 += s1[i] - '0';
		for (int i = 0; i < len2; i++)
			if (s2[i] >= '0' && s2[i] <= '9')
				sum2 += s2[i] - '0';
		if (sum1 == sum2)
			return (s1 < s2);
		return (sum1 < sum2);
	}
	return (len1 < len2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	sort(str, str + n, cmp);
	for (int i = 0; i < n; i++)
		cout << str[i] << '\n';
}
