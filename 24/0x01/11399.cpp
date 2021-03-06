// https://www.acmicpc.net/problem/11399
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int arr[1000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			ans += arr[j];
	cout << ans;
}
