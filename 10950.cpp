#include <iostream>
using namespace std;

int	main(void)
{
	int	i;
	int	a;
	int	b;

	cin >> i;
	while (i > 0)
	{
		cin >> a >> b;
		cout << a + b << '\n';
		i--;
	}
	return (0);
}
