/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 15:24:49 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 16:08:17 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(t_flags *flags, va_list lst)
{
	unsigned long i;

	i = va_arg(lst, unsigned long);
	i != 0 ? flags->large = 2 + ft_countptr(i) : 0;
	i == 0 ? flags->large = 2 : 0;
	flags->i += flags->large;
	ft_pointer_flags(flags, i);
}

void	ft_pointer_flags(t_flags *flags, unsigned long i)
{
	if (flags->point == false)
		ft_putpointer(flags, i);
	else if (flags->point == true && flags->minus == false && flags->nbr >= 0)
		ft_pointer_right_accurate(flags, i);
	else if (flags->point == true && (flags->minus == true || flags->nbr < 0))
		ft_pointer_left_accurate(flags, i);
}

void	ft_putpointer(t_flags *flags, unsigned long i)
{
	if ((flags->minus == true || flags->nbr < 0) && flags->zero == false)
	{
		write(1, "0x", 2);
		ft_putptr(i);
		i == 0 ? flags->nbr++ : 0;
		i == 0 ? flags->i++ : 0;
		flags->nbr < 0 ? flags->nbr *= -1 : 0;
		flags->i += ft_putnchar(0, flags->nbr - flags->large, ' ');
	}
	else if (flags->minus == false && flags->nbr > 0 && flags->zero == false)
	{
		i == 0 ? flags->nbr-- : 0;
		i == 0 ? flags->i++ : 0;
		flags->i += ft_putnchar(0, flags->nbr - flags->large, ' ');
		write(1, "0x", 2);
		ft_putptr(i);
	}
	else
	{
		write(1, "0x", 2);
		flags->i += ft_putnchar(flags->large, flags->nbr, '0');
		(i == 0 && flags->nbr == 0) ? flags->i++ : 0;
		ft_putptr(i);
	}
}

void	ft_pointer_left_accurate(t_flags *flags, unsigned long i)
{
	i == 0 ? flags->large = 0 : 0;
	write(1, "0x", 2);
	flags->i += ft_putnchar(flags->large, flags->aster, '0');
	i != 0 ? ft_putptr(i) : 0;
	if (flags->nbr != 0)
	{
		if (flags->nbr < 0)
			flags->nbr *= -1;
		if (flags->large > flags->aster && i != 0)
		{
			flags->nbr -= flags->large;
			flags->aster = 0;
		}
		if (flags->aster < 0)
			flags->nbr *= -1;
		flags->nbr -= 2;
		flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
	}
}

void	ft_pointer_right_accurate(t_flags *flags, unsigned long i)
{
	if (flags->nbr != 0)
	{
		if (flags->nbr < 0)
			flags->nbr *= -1;
		if (flags->large > flags->aster && i != 0)
		{
			flags->nbr -= flags->large;
			flags->aster = 0;
		}
		if (flags->aster < 0)
			flags->nbr *= -1;
		if (i == 0)
			flags->nbr -= 2;
		flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
	}
	write(1, "0x", 2);
	i == 0 ? flags->large = 0 : 0;
	i != 0 ? flags->large -= 2 : 0;
	flags->aster < 0 ? flags->aster = 1 : 0;
	flags->i += ft_putnchar(flags->large, flags->aster, '0');
	i != 0 ? ft_putptr(i) : 0;
}
