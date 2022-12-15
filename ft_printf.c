/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:24:38 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/15 20:09:33 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_ts(const	char c, va_list *ap_p, int *len_p)
{
	unsigned char	arg;
	int				d;

	if (c == 'c')
	{
		d = va_arg(*ap_p, int);
		arg = (unsigned char)d;
		write(1, &d, 1);
		*len_p += 1;
	}
	else if (c == 's')
		print_s(ap_p, len_p);
	else if (c == 'p')
		print_p(ap_p, len_p);
	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		print_num(c, ap_p, len_p);
	else if (c == '%')
	{
		write(1, "%", 1);
		*len_p += 1;
	}
	else
		*len_p = -1;
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(ap, str);
	while (*(str + i) && len != -1)
	{
		if (*(str + i) == '%')
		{
			i++;
			check_ts(*(str + i), &ap, &len);
		}
		else
		{
			write(1, str + i, 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

/*
#include <stdio.h>

int main()
{
	int i1 = printf("abcdef%d", 1);
	printf("\n");
	int i2 = ft_printf("abcdef%d", 2);
	printf("\n");
	printf("i1 = %d, i2 = %d", i1, i2);
	return (0);
}
*/
