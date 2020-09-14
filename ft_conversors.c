/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:40:00 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 16:01:19 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversors(t_flags *flags, va_list lst)
{
	if (*flags->ftm == 's')
		ft_string(flags, lst);
	else if (*flags->ftm == 'c')
		ft_char(flags, lst);
	else if (*flags->ftm == 'i' || *flags->ftm == 'd')
		ft_numbers(flags, lst);
	else if (*flags->ftm == 'u')
		ft_unsigned_number(flags, lst);
	else if (*flags->ftm == 'x' || *flags->ftm == 'X')
		ft_hexanumbers(flags, lst);
	else if (*flags->ftm == 'p')
		ft_pointer(flags, lst);
	else
		ft_simple(flags);
}

t_flags	ft_initialize(t_flags *flags)
{
	flags->nbr = 0;
	flags->aster = 0;
	flags->large = 0;
	flags->minus = false;
	flags->point = false;
	flags->zero = false;
	return (*flags);
}
