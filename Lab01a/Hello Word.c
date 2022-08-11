#include <unistd.h>

void func_putchar (char c);
void strign (char *s);

int main (void)
{
	char hi[] = {'S','a','l','v','e',' ','\0'};
	char mundo[] = {'M','u','n','d','o','\0'};
	char c;
	
	strign(hi);
	strign(mundo);
	return 0;
}

void strign (char *s)
{
	while (*s != '\0')
	{
		func_putchar (*s);
		s++;
	}

}

void func_putchar (char c)
{
	write(1, &c, 1);
}
