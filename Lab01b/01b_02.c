#include <stdio.h>
#include <conio.h>

char calcMedia(float n1, float n2, float n3, float mE);

int main (void)
{
	float n1, n2, n3, mE;
	scanf("%f\n%f\n%f\n%f", &n1, &n2, &n3, &mE);
	printf("%c",calcMedia(n1, n2, n3, mE));
	return (0);
}

char calcMedia(float n1, float n2, 
			   float n3, float mE)
{
	float mA = (n1 + (n2 * 2) + (n3 * 3) + mE) / 7;
	if (mA >= 9) return 'A';
	else if (mA >= 7.5) return 'B';
	else if (mA >= 6) return 'C';
	else if (mA >= 4) return 'D';
	else if (mA < 4) return 'E';
	
	return '?';
}
