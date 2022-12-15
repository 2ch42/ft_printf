/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:16:17 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/15 22:40:12 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num(const char c, va_list *ap_p, int *len_addr)
{
	if (c == 'd' || c == 'i')
	{
		print_d(ap_p, len_addr);
	}
	else if (c == 'u')
	{
		print_u(ap_p, len_addr);
	}
	else if (c == 'x')
	{
		print_x(ap_p, len_addr);
	}
	else
		print_big_x(ap_p, len_addr);
}

void	print_s(va_list *ap_p, int *len_addr)
{
	char	*s;

	s = va_arg(*ap_p, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*len_addr += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		*len_addr += ft_strlen(s);
	}
}

void	print_p(va_list *ap_p, int *len_addr)
{
	unsigned long long	p;
	char				*s;

	p = va_arg(*ap_p, unsigned long long);
	s = ft_ll_convert_base(p, "0123456789abcdef");
	write(1, "0x", 2);
	*len_addr += 2;
	ft_putstr_fd(s, 1);
	*len_addr += ft_strlen(s);
	free(s);
}
