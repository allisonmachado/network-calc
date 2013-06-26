#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int number = 10;
	unsigned int x = 2;
	unsigned int bit;
	
	number |= 1 << x;
	printf("%d\n",number);

	number &= ~(1 << x);
	printf("%d\n",number);

	number ^= 1 << x;
	printf("%d\n",number);

	bit = number & (1 << x);
	printf("%d\n",bit);
}
