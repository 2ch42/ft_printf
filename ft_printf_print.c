/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:16:17 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/16 17:45:10 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	print_num(const char c, va_list *ap_p, unsigned long long *len_addr)
{
	int	ret_val;

	if (c == 'd' || c == 'i')
	{
		ret_val = print_d(ap_p, len_addr);
	}
	else if (c == 'u')
	{
		ret_val = print_u(ap_p, len_addr);
	}
	else if (c == 'x')
	{
		ret_val = print_x(ap_p, len_addr);
	}
	else
		ret_val = print_big_x(ap_p, len_addr);
	return (ret_val);
}

int	print_c(va_list *ap_p, unsigned long long *len_addr)
{
	unsigned char	arg;
	int				d;

	d = va_arg(*ap_p, int);
	arg = (unsigned char)d;
	if (write(1, &d, 1) == -1)
		return (-1);
	*len_addr += 1;
	return (1);
}

int	print_s(va_list *ap_p, unsigned long long *len_addr)
{
	char	*s;

	s = va_arg(*ap_p, char *);
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*len_addr += 6;
		return (1);
	}
	else
	{
		if (ft_putstr_fd(s, 1) == -1)
			return (-1);
		*len_addr += ft_strlen(s);
		return (1);
	}
}

int	print_p(va_list *ap_p, unsigned long long *len_addr)
{
	unsigned long long	p;
	char				*s;

	p = va_arg(*ap_p, unsigned long long);
	s = ft_ll_convert_base(p, "0123456789abcdef");
	if (!s)
		return (-1);
	if (write(1, "0x", 2) == -1)
	{
		free(s);
		return (-1);
	}
	*len_addr += 2;
	if (ft_putstr_fd(s, 1) == -1)
		return (-1);
	*len_addr += ft_strlen(s);
	free(s);
	return (1);
}
