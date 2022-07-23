/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:36:19 by gasouza           #+#    #+#             */
/*   Updated: 2022/05/25 11:44:53 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	eval_operator(char c, va_list args)
{
	if (c == '%')
		return (ft_print_char('%'));
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int), SIGNED_INT));
	if (c == 'u')
		return (ft_print_nbr(va_arg(args, unsigned int), UNSIGNED_INT));
	if (c == 'x')
		return (ft_print_hex(va_arg(args, long int), LOWER));
	if (c == 'X')
		return (ft_print_hex(va_arg(args, long int), UPPER));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	return (0);
}

static int	is_operator(char c)
{
	char	*operators;
	size_t	i;

	operators = OPERATORS;
	i = 0;
	while (operators[i] && operators[i] != c)
		i++;
	return (operators[i] == c);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	pos;
	int		out_len;

	out_len = 0;
	pos = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[pos])
	{
		if (format[pos] == '%' && is_operator(format[pos + 1]))
			out_len += eval_operator(format[++pos], args);
		else
			out_len += ft_print_char(format[pos]);
		pos++;
	}
	va_end(args);
	return (out_len);
}
