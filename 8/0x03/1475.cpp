// 문제
// 다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.

// 다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)

// 입력
// 첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 필요한 세트의 개수를 출력한다.
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, tmp, k = 0;
	int arr[10] = {};
	cin >> n;
	for (int i = n; i > 0; i /= 10)
	{
		k = i % 10;
		arr[k] += 1;
	}
	tmp = arr[6] + arr[9];
	if (tmp % 2)
		tmp = tmp / 2 + 1;
	else
		tmp /= 2;
	arr[6] = tmp;
	arr[9] = tmp;
	cout << *max_element(arr, arr + 10);
}
