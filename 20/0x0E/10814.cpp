// https://www.acmicpc.net/problem/10814
#include <iostream>
using namespace std;

int n;
int arr[100000];
int tmp[100000];
string str[100000];
string temp[100000];

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
		{
			tmp[i] = arr[l];
			temp[i] = str[l];
			l++;
		}
		else if (l == mid)
		{
			tmp[i] = arr[r];
			temp[i] = str[r];
			r++;
		}
		else if (arr[l] <= arr[r])
		{
			tmp[i] = arr[l];
			temp[i] = str[l];
			l++;
		}
		else
		{
			tmp[i] = arr[r];
			temp[i] = str[r];
			r++;
		}
	}
	for (int i = st; i < en; i++)
	{
		arr[i] = tmp[i];
		str[i] = temp[i];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i] >> str[i];
	merge_sort(0, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ' << str[i] << '\n';
}
