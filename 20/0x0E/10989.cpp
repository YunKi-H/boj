// https://www.acmicpc.net/problem/10989
#include <iostream>
using namespace std;

int n, k;
int arr[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		arr[k]++;
	}
	for (int i = 1; i < 10001; i++)
	{
		while (arr[i])
		{
			cout << i << '\n';
			arr[i]--;
		}
	}
}
