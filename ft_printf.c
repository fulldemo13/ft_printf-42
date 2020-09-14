/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:53:18 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/13 17:45:17 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *ftm, ...)
{
	va_list	lst;
	t_flags	*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	*flags = ft_initialize(flags);
	flags->ftm = ftm;
	flags->i = 0;
	va_start(lst, ftm);
	while (*flags->ftm)
	{
		if (*flags->ftm == '%')
		{
			*flags = ft_initialize(flags);
			ft_checkflags(flags, lst);
			if (*flags->ftm == '\0')
				break ;
			ft_conversors(flags, lst);
		}
		else
			flags->i += write(1, flags->ftm, 1);
		flags->ftm++;
	}
	va_end(lst);
	free(flags);
	return (flags->i);
}
