/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:19:51 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 16:10:16 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_simple(t_flags *flags)
{
	if (flags->point == false)
		ft_putsimple(flags);
	else if (flags->point == true && flags->minus == false && flags->nbr >= 0)
		ft_putright_accurate(flags);
	else if (flags->point == true && (flags->minus == true || flags->nbr < 0))
		ft_putleft_accurate(flags);
}

void	ft_putsimple(t_flags *flags)
{
	if ((flags->minus == true || flags->nbr < 0) && flags->zero == false)
	{
		flags->i += write(1, flags->ftm, 1);
		flags->nbr < 0 ? flags->nbr *= -1 : 0;
		flags->i += ft_putnchar(0, (flags->nbr - 1), ' ');
	}
	else if (flags->minus == false && flags->nbr > 0 && flags->zero == false)
	{
		flags->i += ft_putnchar(0, (flags->nbr - 1), ' ');
		flags->i += write(1, flags->ftm, 1);
	}
	else
	{
		if (flags->nbr <= 1)
			flags->i += write(1, flags->ftm, 1);
		else
		{
			flags->i += ft_putnchar(1, flags->nbr, '0');
			flags->i += write(1, flags->ftm, 1);
		}
	}
}

void	ft_putleft_accurate(t_flags *flags)
{
	if (flags->aster >= 1 || flags->aster <= 0)
		flags->aster = 1;
	if (flags->nbr < 0)
		flags->nbr *= -1;
	flags->i += write(1, flags->ftm, 1);
	flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
}

void	ft_putright_accurate(t_flags *flags)
{
	if (flags->aster >= 1 || flags->aster <= 0)
		flags->aster = 1;
	flags->i += ft_putnchar(flags->aster, flags->nbr, ' ');
	flags->i += write(1, flags->ftm, 1);
}
