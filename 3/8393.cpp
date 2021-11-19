#include <iostream>
using namespace std;

int	main(void)
{
	int	n;
	int	res;

	res = 0;
	cin >> n;
	while (n > 0)
		res += n--;
	cout << res;
	return (0);
}
