/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:24:38 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/13 22:05:27 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_ts(const	char c, va_list *ap_p, int *len_p)
{
	char	arg;
	int		d;

	if (c == 'c')
	{
		c = va_arg(*ap_p, char);
		write(1, &c, 1);
		*len_p += 1;
	}
	else if (c == 's')
		print_s(c, ap_p, len_p);	
	else if (c == 'p')
	{
		print_p(c, ap_p, len_p);
	}
	else if (c == 'd' || 'i' || 'u' || 'x' || 'X')
		print_num(c, ap_p, len_p);
	else if (c == %%)
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

	len = 0;
	va_start(ap, str);
	while (*str++ && len != -1)
	{
		if (*str == %)
		{
			*str++;
			check_ts(*str, &ap, &len);
		}
		else
		{
			write(1, str, 1);
			*str++;
		}
	}
	va_end(ap);
	return (len);
}
