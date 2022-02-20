// https://www.acmicpc.net/problem/1700
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans;
int arr[101];
int tab[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	for (int i = 0; i < k; i++)
	{
		bool isempty = 0;
		for (int j = 0; j < n; j++)
		{
			if (tab[j] == arr[i])
			{
				isempty = 1;
				break;
			}
			if (tab[j] == 0)
			{
				tab[j] = arr[i];
				isempty = 1;
				break;
			}
		}
		if (!isempty)
		{
			int tmp[n];
			fill(tmp, tmp + n, 101);
			for (int j = 0; j < n; j++)
			{
				for (int a = i; a < k; a++)
				{
					if (tab[j] == arr[a])
					{
						tmp[j] = a - i;
						break;
					}
				}
			}
			tab[max_element(tmp, tmp + n) - tmp] = arr[i];
			ans++;
		}
	}
	cout << ans;
}
