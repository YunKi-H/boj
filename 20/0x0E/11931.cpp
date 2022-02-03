// https://www.acmicpc.net/problem/11931
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int n;
// int arr[1000000];

// void quick_sort(int st, int en)
// {
// 	if(en <= st + 1)
// 		return;
// 	int p = arr[st];
// 	int l = st + 1;
// 	int r = en - 1;
// 	while (1)
// 	{
// 		while (l <= r && arr[l] <= p)
// 			l++;
// 		while (l <= r && arr[r] >= p)
// 			r--;
// 		if (l > r)
// 			break;
// 		swap(arr[l], arr[r]);
// 	}
// 	swap(arr[st], arr[r]);
// 	quick_sort(st, r);
// 	quick_sort(r + 1, en);
// }

// int main()
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 		cin >> arr[i];
// 	quick_sort(0, n);
// 	for (int i = n - 1; i >= 0; i--)
// 		cout << arr[i] << '\n';
// }
#include <iostream>
using namespace std;

int n, k;
int arr[2000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		arr[k + 1000000]++;
	}
	for (int i = 2000000; i >= 0; i--)
	{
		if (arr[i])
			cout << i - 1000000 << '\n';
	}
}
