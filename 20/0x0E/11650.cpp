// https://www.acmicpc.net/problem/11650
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		cout << arr[i].first << ' ' << arr[i].second << '\n';
}
