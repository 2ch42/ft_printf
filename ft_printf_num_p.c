/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:20:00 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/13 22:05:23 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d(va_list *ap_p, int *len_addr)
{
	int		d;
	char	*s;

	d = va_arg(*ap_p, int);
	s = ft_itoa(s);
	ft_putstr_fd(s, 1);
	*len_addr += ft_strlen(s);
}

void	print_u(va_list *ap_p, int *len_addr)
{
	unsigned int	d;
	char			*s;

	d = va_arg(*ap_p, unsigned int);
	s = ft_uitoa(d);
	ft_putstr_fd(s, 1);
	*len_addr += ft_strlen(s);
}

void	print_x(va_list *ap_p, int *len_addr)
{
	int		d;
	char	*s;

	d = va_arg(*ap_p, int);
	s = ft_convert_base(d, "0123456789abcdef");
	ft_putstr_fd(s, 1);
	*len_addr += ft_strlen(s);
}

void	print_big_X(va_list *ap_p, int *len_addr)
{
	int		d;
	char	*s;

	d = va_arg(*ap_p, int);
	s = ft_convert_base(d, "0123456789ABCDEF");
	ft_putstr_fd(s, 1);
	*len_addr += ft_strlen(s);
}
