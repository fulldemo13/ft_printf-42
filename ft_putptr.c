/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:04:27 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 16:09:00 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long n)
{
	char	a;

	if (n > 15)
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
	else if (n == 10)
		write(1, "a", 1);
	else if (n == 11)
		write(1, "b", 1);
	else if (n == 12)
		write(1, "c", 1);
	else if (n == 13)
		write(1, "d", 1);
	else if (n == 14)
		write(1, "e", 1);
	else if (n == 15)
		write(1, "f", 1);
	else
	{
		a = (char)(n + 48);
		write(1, &a, 1);
	}
}

int		ft_countptr(unsigned long n)
{
	if (n >= 16)
		return (1 + ft_countptr(n / 16));
	else
		return (1);
}
