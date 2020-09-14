/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:24:41 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 14:23:00 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(t_flags *flags, va_list lst)
{
	char	*s;

	s = va_arg(lst, char *);
	if (!(s))
		ft_string_flags(flags, "(null)");
	else
		ft_string_flags(flags, s);
}

void	ft_string_flags(t_flags *flags, char *s)
{
	if (flags->point == false && flags->zero == false)
		ft_putstring(flags, s);
	else if (flags->point == true && flags->zero == false)
		ft_putstring_accurate(flags, s);
	else if (flags->zero == true)
		ft_putstring_zero_accurate(flags, s);
}

void	ft_putstring(t_flags *flags, char *s)
{
	if (flags->minus == true || flags->nbr < 0)
	{
		flags->i += ft_putnstr(s, (ft_strlen(s)));
		if (flags->nbr < 0)
			flags->nbr *= -1;
		flags->i += ft_putnchar(0, (flags->nbr - (ft_strlen(s))), ' ');
	}
	else
	{
		flags->i += ft_putnchar(0, (flags->nbr - (ft_strlen(s))), ' ');
		flags->i += ft_putnstr(s, (ft_strlen(s)));
	}
}

void	ft_putstring_accurate(t_flags *flags, char *s)
{
	int i;

	i = ft_strlen(s);
	if (flags->minus == false && flags->nbr >= 0)
	{
		if (flags->aster >= i || flags->aster < 0)
			flags->aster = i;
		flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
		flags->i += ft_putnstr(s, flags->aster);
	}
	else
	{
		if (flags->aster >= i || flags->aster < 0)
			flags->aster = i;
		if (flags->nbr < 0)
			flags->nbr *= -1;
		flags->i += ft_putnstr(s, flags->aster);
		flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
	}
}

void	ft_putstring_zero_accurate(t_flags *flags, char *s)
{
	int i;

	i = ft_strlen(s);
	if (flags->nbr <= i)
		flags->i += ft_putnstr(s, i);
	else if (flags->aster != 0)
	{
		if (flags->aster >= i || flags->aster < 0)
			flags->aster = i;
		flags->i += ft_putnchar(flags->aster, flags->nbr, '0');
		flags->aster == 0 ? flags->aster = i : 0;
		flags->i += ft_putnstr(s, flags->aster);
	}
	else
	{
		flags->i += ft_putnchar(i, flags->nbr, '0');
		flags->i += ft_putnstr(s, i);
	}
}
