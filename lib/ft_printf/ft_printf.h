/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:58:38 by gasouza           #+#    #+#             */
/*   Updated: 2022/05/25 15:05:43 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

# define OPERATORS "csdiuxXp%"
# define BASE_HEX_UPP "0123456789ABCDEF"
# define BASE_HEX_LOW "0123456789abcdef"
# define BASE_DEC "0123456789"
# define UPPER 1
# define LOWER 0
# define SIGNED_INT 1
# define UNSIGNED_INT 0

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
char	*ft_num_base_str(long long int n, int signal, char *base);
int		ft_print_char(char c);
int		ft_print_nbr(long int n, int signal);
int		ft_print_hex(unsigned int n, int upper);
int		ft_print_num_base(long long int n, int signal, char *base);
int		ft_print_ptr(void *ptr);
int		ft_print_str(const char *str);

#endif