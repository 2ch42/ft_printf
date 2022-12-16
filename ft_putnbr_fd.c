/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:47:57 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/16 16:37:43 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	how_long(int var)
{
	int	count;

	count = 0;
	while (var > 0)
	{
		var /= 10;
		count++;
	}
	return (count);
}

static int	make_divide(int var)
{
	int	re_val;

	re_val = 1;
	while (var > 1)
	{
		var--;
		re_val *= 10;
	}
	return (re_val);
}

static int	print_result(int nb, int fd)
{
	int		length;
	int		div_val;
	char	c;

	length = how_long(nb);
	div_val = make_divide(length);
	while (length-- > 0)
	{
		c = '0' + nb / div_val;
		if (write(fd, &c, 1) == -1)
			return (-1);
		nb = nb % div_val;
		div_val /= 10;
	}
	return (1);
}

static int	exception(int n, int fd)
{
	if (n == 0)
	{
		if (ft_putstr_fd("0", fd) == -1)
			return (-1);
		return (1);
	}
	else
	{
		if (ft_putstr_fd("-2147483648", fd) == -1)
			return (-1);
		return (11);
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n == 0 || n == -2147483648)
		return (exception(n, fd));
	else
	{
		if (n < 0)
		{
			n = -n;
			if (write(fd, "-", 1) == -1)
				return (-1);
			len++;
		}
		if (print_result(n, fd) == -1)
			return (-1);
		len += how_long(n);
	}
	return (len);
}
