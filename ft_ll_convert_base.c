/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_convert_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:02:10 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/16 17:38:28 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_putnbr_base_all_oc(unsigned long long nbr)
{
	unsigned long long	divider;
	int					mal_len;
	char				*str;

	mal_len = 0;
	divider = 1;
	while (nbr / divider >= 16)
		divider *= 16;
	while (divider != 0)
	{
		mal_len++;
		nbr %= divider;
		divider /= 16;
	}
	str = (char *)malloc(sizeof(char) * (mal_len + 1));
	if (!str)
	{
		free (str);
		return (NULL);
	}
	*(str + mal_len) = 0;
	return (str);
}

static void	ft_putnbr_base_write(unsigned long long nbr, char *base, char *str)
{
	unsigned long long	divider;
	int					i;

	i = 0;
	divider = 1;
	while (nbr / divider >= 16)
		divider *= 16;
	while (divider != 0)
	{
		*(str + i) = *(base + nbr / divider);
		nbr %= divider;
		divider /= 16;
		i++;
	}
}

char	*ft_ll_convert_base(unsigned long long nbr, char *base_to)
{
	char	*ret_str;

	ret_str = ft_putnbr_base_all_oc(nbr);
	if (ret_str == NULL)
	{
		free(ret_str);
		return (NULL);
	}
	ft_putnbr_base_write(nbr, base_to, ret_str);
	return (ret_str);
}
