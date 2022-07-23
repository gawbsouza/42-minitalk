/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:49:31 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/28 12:19:48 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	digit = (n % 10);
	n /= 10;
	if (n < 0 || digit < 0)
	{
		ft_putchar_fd('-', fd);
		digit *= -1;
		n *= -1;
	}
	if (n > 0)
		ft_putnbr_fd(n, fd);
	ft_putchar_fd(digit + '0', fd);
}
