/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:50:55 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/13 20:21:46 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_n_len(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += 1;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}

static void	real_ft_itoa(long long n, char *str, int start_idx, int len)
{
	long long	i;
	long long	divider;

	divider = 1;
	i = start_idx;
	while (i < len - 1)
	{
		divider *= 10;
		i++;
	}
	while (divider > 1)
	{
		*(str + start_idx) = n / divider + 48;
		n %= divider;
		divider /= 10;
		start_idx++;
	}
	*(str + start_idx) = n % 10 + 48;
	*(str + start_idx + 1) = '\0';
}

char	*ft_itoa(int n)
{
	int			i;
	int			len;
	long long	n_copy;
	char		*ret_str;

	n_copy = (long long)n;
	len = get_n_len(n_copy);
	ret_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret_str)
		return (NULL);
	i = 0;
	if (n_copy < 0)
	{
		*(ret_str + 0) = '-';
		n_copy *= -1;
		i++;
	}
	real_ft_itoa(n_copy, ret_str, i, len);
	return (ret_str);
}
