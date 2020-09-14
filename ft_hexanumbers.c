/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexanumbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:24:17 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 16:05:09 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexanumbers(t_flags *flags, va_list lst)
{
	unsigned int	i;

	i = va_arg(lst, unsigned int);
	flags->large = ft_counthexa(i);
	i != 0 ? flags->i += flags->large : 0;
	ft_hexanumbers_flags(flags, i);
}

void	ft_hexanumbers_flags(t_flags *flags, unsigned int i)
{
	if (flags->point == false)
		ft_hexanumber(flags, i);
	else if (flags->point == true && flags->minus == false && flags->nbr >= 0)
		ft_hexanumber_right_accurate(flags, i);
	else if (flags->point == true && (flags->minus == true || flags->nbr < 0))
		ft_hexanumber_left_accurate(flags, i);
}

void	ft_hexanumber(t_flags *flags, unsigned int i)
{
	i == 0 ? flags->i += 1 : 0;
	if ((flags->minus == true || flags->nbr < 0) && flags->zero == false)
	{
		*flags->ftm == 'x' ? ft_putlohexa(i) : 0;
		*flags->ftm == 'X' ? ft_putuphexa(i) : 0;
		flags->nbr < 0 ? flags->nbr *= -1 : 0;
		flags->i += ft_putnchar(0, flags->nbr - flags->large, ' ');
	}
	else if (flags->minus == false && flags->nbr > 0 && flags->zero == false)
	{
		flags->i += ft_putnchar(0, flags->nbr - flags->large, ' ');
		*flags->ftm == 'x' ? ft_putlohexa(i) : 0;
		*flags->ftm == 'X' ? ft_putuphexa(i) : 0;
	}
	else
	{
		flags->i += ft_putnchar(flags->large, flags->nbr, '0');
		*flags->ftm == 'x' ? ft_putlohexa(i) : 0;
		*flags->ftm == 'X' ? ft_putuphexa(i) : 0;
	}
}

void	ft_hexanumber_left_accurate(t_flags *flags, unsigned int i)
{
	i == 0 ? flags->large = 0 : 0;
	flags->i += ft_putnchar(flags->large, flags->aster, '0');
	if (i != 0)
	{
		*flags->ftm == 'x' ? ft_putlohexa(i) : 0;
		*flags->ftm == 'X' ? ft_putuphexa(i) : 0;
	}
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
		flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
	}
}

void	ft_hexanumber_right_accurate(t_flags *flags, unsigned int i)
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
		flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
	}
	if (i == 0)
		flags->large = 0;
	flags->i += ft_putnchar(flags->large, flags->aster, '0');
	if (i != 0)
	{
		*flags->ftm == 'x' ? ft_putlohexa(i) : 0;
		*flags->ftm == 'X' ? ft_putuphexa(i) : 0;
	}
}
