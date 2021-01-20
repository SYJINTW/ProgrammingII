#include <stdio.h>

int main()
{
	int x, count = 0, carry = 0;
	int bin[12] = {-1};
	scanf("%d", &x);
	for (; x > 0; ++count)
	{
		bin[count] = x % 2;
		x /= 2;
		printf("%d\n", x);
	}

	for (int i = 0; i < 11; i++) {
		printf("%d ", bin[i]);
	}

	while (carry <= count)
	{
		int y = bin[carry] + 1;
		printf("%d\n", bin[carry]);
		printf("%d\n", bin[carry]+1);
		if (y == 1) {
			bin[carry] = 1;
			break;
		}
		else if (y == 2) {
			bin[carry] = 0;
			carry++;
		}
		else{
			bin[carry] = 1;
			++count;
			break;
		}
	}

	for (--count; count >= 0; --count) {
		//printf("%d", bin[count]);
	}
	//printf(" %d", carry);
	return 0;
}