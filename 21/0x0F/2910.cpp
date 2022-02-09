// https://www.acmicpc.net/problem/2910
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int n, c;
vector<pair<int, int> > arr;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return (p1.first > p2.first);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		int check = 0;
		for (int j = 0; j < arr.size(); j++)
		{
			if (tmp == arr[j].second)
			{
				check = 1;
				arr[j].first += 1;
				break;
			}
		}
		if (!check)
				arr.push_back(make_pair(1, tmp));
	}
	stable_sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].first; j++)
			cout << arr[i].second << ' ';
	}
}
