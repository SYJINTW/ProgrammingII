#include <stdio.h>


int main(int argc, char const *argv[])
{
	int wage = 0;
	int h1, h2, m1, m2, s1, s2;
	scanf("%d", &wage);
	scanf("%d:%d:%d ~ %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

	if (s2 >= s1) {
		s2 = s2 - s1;
	}
	else {
		s2 = 60 + s2 - s1;
		m2--;
	}

	if (m2 >= m1) {
		m2 = m2 - m1;
	}
	else {
		m2 = 60 + m2 - m1;
		h2--;
	}

	h2 = h2 - h1;


	printf("Working Time: %d Hour(s) %d Minute(s) %d Second(s)\n", h2, m2, s2);
	printf("Daily Wage: %d TWD\n", wage*h2);
	return 0;
}