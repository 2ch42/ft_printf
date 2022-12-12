/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:24:38 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/12 20:24:44 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	arg;

	i = 0;
	va_start(ap, str);
	while (*str++)
	{
		if (*str == '%')
		{
			if 
		}
		else
			write(1, s + i, 1);
		i++;
	}
	va_end(ap);
}
