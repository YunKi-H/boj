#include <iostream>
using namespace std;

int	main(void)
{
	int	i;
	int	a;
	int	b;
	int	c;

	c = 0;
	cin >> i;
	while (c++ < i)
	{
		cin >> a >> b;
		cout << "Case #" << c << ": " << a + b << "\n";
	}
	return (0);
}
