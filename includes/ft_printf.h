/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/14 22:25:59 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	Nested headers:
*/
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
#include "debug.h" // <================== DELETE BEFORE SUBMITING!!!
/*
**	Data types:
*/
typedef struct s_spec
{
	uint16_t	flags;
	uint16_t	digits;
	int			width;
	int			precision;
	uint16_t	length;
	int			specifier;
}	t_spec;

typedef int	(*t_disp)(va_list data_args, t_spec *spec);

/*
**	Functions in the dispatcher (one per specifier + the one for'%%'):
*/
# define FUN	9

/*
**	Macros for specifiers:
*/
# define NOT_SET	-1
# define PERCENT	0
# define CHAR		1
# define STRING		2
# define ADDRESS	3
# define LOWHEX		4
# define UPPHEX		5
# define INT		6
# define UINT		7
# define FLOAT		8

/*
**	Function prototypes:
*/
int	ft_printf(const char *format, ...);
int	to_percent(va_list data_args, t_spec *conv_spec);
int	to_char(va_list data_args, t_spec *conv_spec);
int	to_string(va_list data_args, t_spec *conv_spec);
int	to_address(va_list data_args, t_spec *spec);
int	to_int(va_list data_args, t_spec *conv_spec);

#endif