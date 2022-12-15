/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:24:50 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/15 22:43:53 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_strlen(const	char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_convert_base(unsigned int nbr, char *base_to);
char	*ft_ll_convert_base(unsigned long long nbr, char *base_to);
int		get_n_len(long long n);
int		ft_putnbr_fd(int n, int fd);
int		ft_put_u_nbr_fd(unsigned int n, int fd);
void	print_d(va_list *ap_p, int *len_addr);
void	print_u(va_list *ap_p, int *len_addr);
void	print_x(va_list *ap_p, int *len_addr);
void	print_big_x(va_list *ap_p, int *len_addr);
void	print_num(const char c, va_list *ap_p, int *len_addr);
void	print_s(va_list *ap_p, int *len_addr);
void	print_p(va_list *ap_p, int *len_addr);
void	check_ts(const	char c, va_list *ap_p, int *len_p);
int		ft_printf(const char *str, ...);

#endif
