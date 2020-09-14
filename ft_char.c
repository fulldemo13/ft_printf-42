/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:53:23 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 16:02:15 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_flags *flags, va_list lst)
{
	char	a;

	a = va_arg(lst, unsigned int);
	ft_char_flags(flags, a);
}

void	ft_char_flags(t_flags *flags, char a)
{
	if (flags->zero == false && flags->point == false)
		ft_putchar(flags, a);
	else if (flags->point == true && flags->zero == false)
		ft_putchar_accurate(flags, a);
	else if (flags->zero == true)
		ft_putchar_zero_accurate(flags, a);
}

void	ft_putchar(t_flags *flags, char a)
{
	if (flags->minus == true || flags->nbr < 0)
	{
		flags->i += ft_putnstr(&a, 1);
		if (flags->nbr < 0)
			flags->nbr *= -1;
		flags->i += ft_putnchar(0, flags->nbr - 1, ' ');
	}
	else
	{
		flags->i += ft_putnchar(0, flags->nbr - 1, ' ');
		flags->i += ft_putnstr(&a, 1);
	}
}

void	ft_putchar_accurate(t_flags *flags, char a)
{
	if (flags->minus == false && flags->nbr >= 0)
	{
		if (flags->aster < 0)
			flags->aster *= -1;
		if (flags->aster >= 1)
			flags->aster = 1;
		flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
		flags->i += ft_putnstr(&a, flags->aster);
	}
	else
	{
		if (flags->aster >= 1)
			flags->aster = 1;
		if (flags->nbr < 0)
			flags->nbr *= -1;
		flags->i += ft_putnstr(&a, flags->aster);
		flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
	}
}

void	ft_putchar_zero_accurate(t_flags *flags, char a)
{
	if (flags->nbr <= 1)
		flags->i += ft_putnstr(&a, 1);
	else
	{
		flags->i += ft_putnchar(1, flags->nbr, '0');
		flags->i += ft_putnstr(&a, 1);
	}
}
