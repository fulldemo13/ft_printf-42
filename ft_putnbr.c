/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:48:05 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 16:02:44 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	char a;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "2", 1);
			n = 147483648;
		}
		else
			n = (n * -1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		a = n % 10 + 48;
		write(1, &a, 1);
	}
}

void	ft_putunbr(unsigned int n)
{
	char	a;

	if (n > 9)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else
	{
		a = n + '0';
		write(1, &a, 1);
	}
}
