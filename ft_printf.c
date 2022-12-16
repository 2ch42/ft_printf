/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:24:38 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/16 16:40:42 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	check_ts(const	char c, va_list *ap_p, unsigned long long *len_p)
{
	int	ret_val;

	if (c == 'c')
		ret_val = print_c(ap_p, len_p);
	else if (c == 's')
		ret_val = print_s(ap_p, len_p);
	else if (c == 'p')
		ret_val = print_p(ap_p, len_p);
	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		ret_val = print_num(c, ap_p, len_p);
	else if (c == '%')
	{
		if (write(1, "%", 1) == -1)
			ret_val = -1;
		else
			ret_val = 1;
		*len_p += 1;
	}
	else
		ret_val = -1;
	return (ret_val);
}

static int	print_len_ret(const char *str, va_list *ap_p)
{
	unsigned long long	len;
	int					i;
	int					check;

	len = 0;
	i = 0;
	check = 1;
	while (*(str + i) && check != -1)
	{
		if (*(str + i) == '%')
		{
			i++;
			check = check_ts(*(str + i), ap_p, &len);
		}
		else
		{
			if (write(1, str + i, 1) == -1)
				return (-1);
			len++;
		}
		i++;
	}
	if (len > 2147483647 || check == -1)
		return (-1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list				ap;
	int					len;

	va_start(ap, str);
	len = print_len_ret(str, &ap);
	va_end(ap);
	return (len);
}
