/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:55:07 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/16 16:33:24 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(const	char *s)
{
	int	len;

	len = 0;
	while (*(s + len) != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (write(fd, s + i, 1) == -1)
			return (-1);
		i++;
	}
	return (1);
}
