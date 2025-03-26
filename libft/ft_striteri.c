#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	aux;

	aux = 0;
	if (!s || !f)
		return ;
	while (s[aux])
	{
		f(aux, &s[aux]);
		aux++;
	}
}

void	to_lower_odd(unsigned int i, char *s)
{
	if (i % 2 != 0)
	{
		if (*s >= 'A' && *s <= 'Z')
			*s = *s + 32;
	}
}

/*int main(void)
{
	char s[] = "HELLO";

	ft_striteri(s, to_lower_odd );
	printf("the result is: %s", s);
	return 0;
}*/