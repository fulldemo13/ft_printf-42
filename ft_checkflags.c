/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:03:56 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 16:52:59 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	*ft_checkflags_continue(t_flags *flags)
{
	if (flags->nbr == 0 && *flags->ftm == '0' &&
		flags->minus == false && flags->point == false)
	{
		flags->zero = true;
		flags->nbr = ft_atoi((char *)flags->ftm);
	}
	else if (flags->point == true)
		flags->aster = ft_atoi((char *)flags->ftm);
	else
		flags->nbr = ft_atoi((char *)flags->ftm);
	while (*flags->ftm >= '0' && *flags->ftm <= '9')
		flags->ftm++;
	flags->ftm--;
	return (flags);
}

void			ft_checkflags(t_flags *flags, va_list lst)
{
	int i;

	i = 0;
	flags->ftm++;
	while (*flags->ftm == '-' || *flags->ftm == '0' || *flags->ftm == '.' ||
			*flags->ftm == '*' || (*flags->ftm >= '0' && *flags->ftm <= '9'))
	{
		*flags->ftm == '-' ? flags->minus = true : 0;
		*flags->ftm == '.' ? flags->point = true : 0;
		if (*flags->ftm == '*')
		{
			if (flags->point == true)
				flags->aster = va_arg(lst, int);
			else
				flags->nbr = va_arg(lst, int);
		}
		if (*flags->ftm >= '0' && *flags->ftm <= '9')
			*flags = *ft_checkflags_continue(flags);
		flags->ftm++;
	}
}
