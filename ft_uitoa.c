/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:50:55 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/13 20:28:22 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	real_ft_uitoa(unsigned int n, char *str, int start_idx, int len)
{
	unsigned int	i;
	unsigned int	divider;

	divider = 1;
	i = start_idx;
	while (i + 1 < len)
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

char	*ft_uitoa(unsigned int n)
{
	int			i;
	int			len;
	char		*ret_str;

	len = get_n_len(n);
	ret_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret_str)
		return (NULL);
	i = 0;
	real_ft_uitoa(n, ret_str, i, len);
	return (ret_str);
}
