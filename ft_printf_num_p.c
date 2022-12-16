/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:20:00 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/16 16:32:38 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	print_d(va_list *ap_p, unsigned long long *len_addr)
{
	int	d;
	int	len;

	d = va_arg(*ap_p, int);
	len = ft_putnbr_fd(d, 1);
	if (len < 0)
		return (-1);
	*len_addr += len;
	return (1);
}

int	print_u(va_list *ap_p, unsigned long long *len_addr)
{
	unsigned int	d;
	int				len;

	d = va_arg(*ap_p, unsigned int);
	len = ft_put_u_nbr_fd(d, 1);
	if (len < 0)
		return (-1);
	*len_addr += len;
	return (1);
}

int	print_x(va_list *ap_p, unsigned long long *len_addr)
{
	int				d;
	unsigned int	i;
	char			*s;

	d = va_arg(*ap_p, int);
	i = (unsigned int)d;
	s = ft_convert_base(i, "0123456789abcdef");
	if (ft_putstr_fd(s, 1) == -1)
		return (-1);
	*len_addr += ft_strlen(s);
	free(s);
	return (1);
}

int	print_big_x(va_list *ap_p, unsigned long long *len_addr)
{
	int				d;
	unsigned int	i;
	char			*s;

	d = va_arg(*ap_p, int);
	i = (unsigned int)d;
	s = ft_convert_base(i, "0123456789ABCDEF");
	if (ft_putstr_fd(s, 1) == -1)
		return (-1);
	*len_addr += ft_strlen(s);
	free(s);
	return (1);
}
