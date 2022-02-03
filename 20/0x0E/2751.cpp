// https://www.acmicpc.net/problem/2751
#include <iostream>
using namespace std;

int n;
int arr[1000000];
int tmp[1000000];

void merge_sort(int st, int en)
{
	if (en - st == 1)
		return;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	int l = st;
	int r = mid;
	for (int i = st; i < en; i++)
	{
		if (r == en)
			tmp[i] = arr[l++];
		else if (l == mid)
			tmp[i] = arr[r++];
		else if (arr[l] <= arr[r])
			tmp[i] = arr[l++];
		else
			tmp[i] = arr[r++];
	}
	for (int i = st; i < en; i++)
		arr[i] = tmp[i];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	merge_sort(0, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
}
