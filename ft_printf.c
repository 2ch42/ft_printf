/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:24:38 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/12 22:30:35 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		d;
	int		len;
	char	arg;
	char	*s;

	len = 0;
	va_start(ap, str);
	while (*str++)
	{
		if (*str == '%')
		{
			*str++;
			if (*str == 'd' || *str == 'i' || *str == 'u'
				|| *str == 'x' || *str == 'X')
			{
				d = va_arg(ap, int);
				// to print~
			}
			else if (*str == 'c')
			{
				arg = va_arg(ap, char);
				// to print~
			}
			else if (*str == 
		}
		else
		{
			write(1, str, 1);
			len++;
		}
	}
	va_end(ap);
}
