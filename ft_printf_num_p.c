/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:20:00 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/15 22:23:08 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d(va_list *ap_p, int *len_addr)
{
	int	d;
	int	len;

	d = va_arg(*ap_p, int);
	len = ft_putnbr_fd(d, 1);
	*len_addr += len;
}

void	print_u(va_list *ap_p, int *len_addr)
{
	unsigned int	d;
	int				len;

	d = va_arg(*ap_p, unsigned int);
	len = ft_put_u_nbr_fd(d, 1);
	*len_addr += len;
}

void	print_x(va_list *ap_p, int *len_addr)
{
	int				d;
	unsigned int	i;
	char			*s;

	d = va_arg(*ap_p, int);
	i = (unsigned int)d;
	s = ft_convert_base(i, "0123456789abcdef");
	ft_putstr_fd(s, 1);
	*len_addr += ft_strlen(s);
	free(s);
}

void	print_big_x(va_list *ap_p, int *len_addr)
{
	int				d;
	unsigned int	i;
	char			*s;

	d = va_arg(*ap_p, int);
	i = (unsigned int)d;
	s = ft_convert_base(i, "0123456789ABCDEF");
	ft_putstr_fd(s, 1);
	*len_addr += ft_strlen(s);
	free(s);
}
