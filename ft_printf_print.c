/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:16:17 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/13 22:05:25 by changhyl         ###   ########.fr       */
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
		print_big_X(ap_p, len_addr);
}

void	print_s(const char c, va_list *ap_p, int *len_addr)
{
	char	*s;

	s = va_arg(*ap_p, char *);
	ft_putstr(s, 1);
	*len_addr += ft_strlen(s);
}

void	print_p(const char c, va_list *ap_p, int *len_addr)
{
	void	*p;

	p = va_arg(*ap_p, void *);
	p = 
}
