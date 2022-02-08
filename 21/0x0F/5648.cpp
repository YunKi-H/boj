// https://www.acmicpc.net/problem/5648
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
long long arr[100001];
string str[100001];
string tmp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		reverse(tmp.begin(), tmp.end());
		str[i] = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		long long sum = 0;
		for (int j = 0; j < str[i].length(); j++)
		{
			sum *= 10;
			sum += str[i][j] - '0';
		}
		arr[i] = sum;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
}
