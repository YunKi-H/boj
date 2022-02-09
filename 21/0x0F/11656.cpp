// https://www.acmicpc.net/problem/11656
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str, arr[1000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++)
		arr[i] = str.substr(i);
	sort(arr, arr + len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << '\n';
}
