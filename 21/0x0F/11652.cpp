// https://www.acmicpc.net/problem/11652
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n;
long long arr[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	long long ans = -((long long)1<<63);
	int maxcnt = 0, cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] == arr[i])
			cnt++;
		else
		{
			if (cnt > maxcnt)
			{
				maxcnt = cnt;
				ans = arr[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > maxcnt)
		ans = arr[n - 1];
	cout << ans;
}
