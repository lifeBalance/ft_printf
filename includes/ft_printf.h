/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/09 20:02:32 by rodrodri         ###   ########.fr       */
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

/*
**	Data types:
*/
typedef struct s_spec
{
	uint16_t	flags;
	int			width;
	int			precision;
	uint16_t	length;
	int			specifier;
}	t_spec;

typedef int	(*t_disp)(va_list data_args, t_spec *spec);

/*
**	Functions in the dispatcher (one per specifier + the one for'%%'):
*/
# define FUN	3

/*
**	Macros for flags:
*/
# define SHARP	1
# define ZERO	2
# define MINUS	3
# define PLUS	4
# define SPACE	5

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
# define FLOAT		7

/*
**	Macros for length:
*/
# define H		1
# define HH		2
# define ELL	3
# define ELLELL	4
# define UPPELL	5
# define DOT	6

/*
**	Prototypes:
*/
int	ft_printf(const char *format, ...);
int	parse_spec(char **fmt_str, t_spec *spec);
int	to_percent(va_list data_args, t_spec *conv_spec);
int	to_char(va_list data_args, t_spec *conv_spec);
int	to_string(va_list data_args, t_spec *conv_spec);

#endif