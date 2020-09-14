/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:50:24 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 18:03:12 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_numbers(t_flags *flags, va_list lst)
{
	int		i;
	int		j;

	i = va_arg(lst, int);
	j = i;
	if (i <= 0)
	{
		flags->large++;
	}
	while (j != 0)
	{
		j = j / 10;
		flags->large++;
	}
	flags->i += flags->large;
	ft_numbers_flags(flags, i);
}

void	ft_numbers_flags(t_flags *flags, int i)
{
	if (flags->point == false)
		ft_putnumber(flags, i);
	else if (flags->point == true && flags->minus == false && flags->nbr >= 0)
		ft_number_right_accurate(flags, i);
	else if (flags->point == true && (flags->minus == true || flags->nbr < 0))
		ft_number_left_accurate(flags, i);
}

void	ft_putnumber(t_flags *flags, int i)
{
	if ((flags->minus == true || flags->nbr < 0) && flags->zero == false)
	{
		i < 0 ? write(1, "-", 1) : 0;
		ft_putnbr(i);
		flags->nbr < 0 ? flags->nbr *= -1 : 0;
		flags->i += ft_putnchar(0, flags->nbr - flags->large, ' ');
	}
	else if (flags->minus == false && flags->nbr > 0 && flags->zero == false)
	{
		flags->i += ft_putnchar(0, flags->nbr - flags->large, ' ');
		i < 0 ? write(1, "-", 1) : 0;
		ft_putnbr(i);
	}
	else if (flags->nbr < 0 || flags->minus == true)
	{
		flags->aster = 1;
		ft_number_left_accurate(flags, i);
	}
	else
	{
		i < 0 ? write(1, "-", 1) : 0;
		flags->i += ft_putnchar(flags->large, flags->nbr, '0');
		ft_putnbr(i);
	}
}

void	ft_number_left_accurate(t_flags *flags, int i)
{
	i < 0 ? write(1, "-", 1) : 0;
	i < 0 ? flags->aster++ : 0;
	i == 0 ? flags->i-- : 0;
	i == 0 ? flags->large = 0 : 0;
	flags->i += ft_putnchar(flags->large, flags->aster, '0');
	i != 0 ? ft_putnbr(i) : 0;
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

void	ft_number_right_accurate(t_flags *flags, int i)
{
	if (flags->nbr != 0)
	{
		flags->nbr < 0 ? flags->nbr *= -1 : 0;
		i < 0 && flags->large <= flags->aster ? flags->nbr-- : 0;
		if (flags->large > flags->aster && i != 0)
		{
			flags->nbr -= flags->large;
			flags->aster = 0;
		}
		flags->aster < 0 ? flags->nbr *= -1 : 0;
		flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
	}
	i < 0 ? write(1, "-", 1) : 0;
	i < 0 ? flags->aster++ : 0;
	i == 0 ? flags->i-- : 0;
	i == 0 ? flags->large = 0 : 0;
	flags->aster < 0 ? flags->aster = 1 : 0;
	flags->i += ft_putnchar(flags->large, flags->aster, '0');
	i != 0 ? ft_putnbr(i) : 0;
}
