#include <stdio.h>

int	main(void)
{
	int	t;
	int	a;
	int	b;

	scanf("%d\n", &t);
	while (t)
	{
		scanf("%d,%d\n", &a, &b);
		printf("%d\n", a + b);
		t--;
	}
	return (0);
}
