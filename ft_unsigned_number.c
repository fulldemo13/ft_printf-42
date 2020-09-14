/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:08:38 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 18:31:05 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_number(t_flags *flags, va_list lst)
{
	unsigned int	i;
	unsigned int	j;

	i = va_arg(lst, unsigned int);
	j = i;
	while (j >= 10)
	{
		j = j / 10;
		flags->large++;
	}
	flags->large++;
	flags->i += flags->large;
	ft_unsigned_numbers_flags(flags, i);
}

void	ft_unsigned_numbers_flags(t_flags *flags, unsigned int i)
{
	if (flags->point == false)
		ft_putunsigned_numbers(flags, i);
	else if (flags->point == true && flags->minus == false && flags->nbr >= 0)
		ft_unsigned_number_right_accurate(flags, i);
	else if (flags->point == true && (flags->minus == true || flags->nbr < 0))
		ft_unsigned_number_left_accurate(flags, i);
}

void	ft_putunsigned_numbers(t_flags *flags, unsigned int i)
{
	if ((flags->minus == true || flags->nbr < 0) && flags->zero == false)
	{
		ft_putunbr(i);
		flags->nbr < 0 ? flags->nbr *= -1 : 0;
		flags->i += ft_putnchar(0, flags->nbr - flags->large, ' ');
	}
	else if (flags->minus == false && flags->nbr > 0 && flags->zero == false)
	{
		flags->i += ft_putnchar(0, flags->nbr - flags->large, ' ');
		ft_putunbr(i);
	}
	else
	{
		flags->i += ft_putnchar(flags->large, flags->nbr, '0');
		ft_putunbr(i);
	}
}

void	ft_unsigned_number_left_accurate(t_flags *flags, unsigned int i)
{
	i == 0 ? flags->i-- : 0;
	i == 0 ? flags->large = 0 : 0;
	flags->i += ft_putnchar(flags->large, flags->aster, '0');
	i != 0 ? ft_putunbr(i) : 0;
	if (flags->nbr != 0)
	{
		flags->nbr < 0 ? flags->nbr *= -1 : 0;
		if (flags->large > flags->aster && i != 0)
		{
			flags->nbr -= flags->large;
			flags->aster = 0;
		}
		flags->aster < 0 ? flags->nbr *= -1 : 0;
		flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
	}
}

void	ft_unsigned_number_right_accurate(t_flags *flags, unsigned int i)
{
	if (flags->nbr != 0)
	{
		flags->nbr < 0 ? flags->nbr *= -1 : 0;
		if (flags->large > flags->aster && i != 0)
		{
			flags->nbr -= flags->large;
			flags->aster = 0;
		}
		flags->aster < 0 ? flags->nbr *= -1 : 0;
		flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
	}
	i == 0 ? flags->i-- : 0;
	i == 0 ? flags->large = 0 : 0;
	flags->i += ft_putnchar(flags->large, flags->aster, '0');
	i != 0 ? ft_putunbr(i) : 0;
}
