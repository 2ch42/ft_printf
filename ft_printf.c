#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	i;
	char	arg;

	i = 0;
	va_start(ap, str);
	while (*str++)
	{
		if (*str == '%')
		{
			//
			//va_arg ~ 
		}
		else
			write(1, s + i, 1);
		i++;
	}
	va_end(ap);
}
