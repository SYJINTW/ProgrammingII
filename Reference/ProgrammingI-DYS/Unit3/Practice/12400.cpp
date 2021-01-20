#include <stdio.h>


int main(int argc, char const *argv[])
{
	int mwage = 0, hwage = 0, twage = 0;
	int h1, h2, m1, m2, s1, s2;
	scanf("%d %d", &mwage , &hwage);
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

	twage = h2 * hwage + h2 * 60 * mwage + m2 * mwage;

	printf("Working Time: %d Hour(s) %d Minute(s) %d Second(s)\n", h2, m2, s2);
	printf("Daily Wage: %d TWD\n", twage);
	return 0;
}