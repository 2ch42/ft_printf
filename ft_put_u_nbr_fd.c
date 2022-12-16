/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_nbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:47:57 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/16 13:01:07 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	how_long(unsigned int var)
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

static unsigned int	make_divide(unsigned int var)
{
	unsigned int	re_val;

	re_val = 1;
	while (var > 1)
	{
		var--;
		re_val *= 10;
	}
	return (re_val);
}

void	print_result(unsigned int nb, int fd)
{
	unsigned int	length;
	int				div_val;
	char			c;

	length = how_long(nb);
	div_val = make_divide(length);
	while (length-- > 0)
	{
		c = '0' + nb / div_val;
		write(fd, &c, 1);
		nb = nb % div_val;
		div_val /= 10;
	}
}

int	ft_put_u_nbr_fd(unsigned int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else
		print_result(n, fd);
	return (how_long(n));
}
