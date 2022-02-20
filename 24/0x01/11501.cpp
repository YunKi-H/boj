// https://www.acmicpc.net/problem/11501
#include <iostream>
#include <algorithm>
using namespace std;

int t, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		long long ans = 0;
		int cnt = 0;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int max = arr[n - 1];
		for (int i = n - 1; i >= 0; i--)
		{
			if (arr[i] > max)
				max = arr[i];
			ans += max - arr[i];
		}
		cout << ans << '\n';
	}
}


// int main()
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> t;
// 	while (t--)
// 	{
// 		long long ans = 0;
// 		int cnt = 0;
// 		cin >> n;
// 		int arr[n];
// 		for (int i = 0; i < n; i++)
// 		{
// 			cin >> arr[i];
// 		}
// 		int max = 0;
// 		for (int i = 0; i < n; i++)
// 		{
// 			max = *max_element(arr + i, arr + n);
// 			if (arr[i] < max)
// 			{
// 				ans -= arr[i];
// 				cnt++;
// 			}
// 			if (arr[i] == max)
// 			{
// 				ans += arr[i] * cnt;
// 				cnt = 0;
// 			}
// 		}
// 		cout << ans << '\n';
// 	}
// }
