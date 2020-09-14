/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:55:02 by fulldemo          #+#    #+#             */
/*   Updated: 2019/12/14 09:00:13 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int			i;
	const char	*ftm;
	int			nbr;
	int			aster;
	int			large;
	bool		minus;
	bool		point;
	bool		zero;
}				t_flags;

int				ft_printf(const char *ftm, ...);
t_flags			ft_initialize(t_flags *flags);
void			ft_checkflags(t_flags *flags, va_list lst);
void			ft_conversors(t_flags *flags, va_list lst);

int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
int				ft_putnchar(int i, int j, char a);
int				ft_putnstr(char *s, int i);
void			ft_putnbr(int n);

void			ft_string(t_flags *flags, va_list lst);
void			ft_string_flags(t_flags *flags, char *s);
void			ft_putstring(t_flags *flags, char *s);
void			ft_putstring_accurate(t_flags *flags, char *s);
void			ft_putstring_zero_accurate(t_flags *flags, char *s);

void			ft_char(t_flags *flags, va_list lst);
void			ft_char_flags(t_flags *flags, char a);
void			ft_putchar(t_flags *flags, char a);
void			ft_putchar_accurate(t_flags *flags, char a);
void			ft_putchar_zero_accurate(t_flags *flags, char a);

void			ft_numbers(t_flags *flags, va_list lst);
void			ft_numbers_flags(t_flags *flags, int i);
void			ft_putnumber(t_flags *flags, int i);
void			ft_number_left_accurate(t_flags *flags, int i);
void			ft_number_right_accurate(t_flags *flags, int i);

void			ft_pointer(t_flags *flags, va_list lst);
void			ft_pointer_flags(t_flags *flags, unsigned long i);
void			ft_putpointer(t_flags *flags, unsigned long i);
void			ft_pointer_left_accurate(t_flags *flags, unsigned long i);
void			ft_pointer_right_accurate(t_flags *flags, unsigned long i);
int				ft_countptr(unsigned long n);
void			ft_putptr(unsigned long n);

void			ft_unsigned_number(t_flags *flags, va_list lst);
void			ft_unsigned_numbers_flags(t_flags *flags, unsigned int i);
void			ft_putunsigned_numbers(t_flags *flags, unsigned int i);
void			ft_unsigned_number_left_accurate(t_flags *flags,
				unsigned int i);
void			ft_unsigned_number_right_accurate(t_flags *flags,
				unsigned int i);
void			ft_putunbr(unsigned int n);

void			ft_hexanumbers(t_flags *flags, va_list lst);
void			ft_hexanumbers_flags(t_flags *flags, unsigned int i);
void			ft_hexanumber(t_flags *flags, unsigned int i);
void			ft_hexanumber_left_accurate(t_flags *flags, unsigned int i);
void			ft_hexanumber_right_accurate(t_flags *flags, unsigned int i);
void			ft_putlohexa(unsigned int n);
void			ft_putuphexa(unsigned int n);
int				ft_counthexa(unsigned int n);

void			ft_simple(t_flags *flags);
void			ft_putsimple(t_flags *flags);
void			ft_putleft_accurate(t_flags *flags);
void			ft_putright_accurate(t_flags *flags);
#endif
