/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/08 20:35:11 by rodrodri         ###   ########.fr       */
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
# include <stdio.h>// DELETE BEFORE SUBMITTING!!!

/*
**	Data types:
*/
typedef struct s_spec
{
	uint16_t	flags;
	int			width;
	int			precision;
	int			length;
	uint16_t	specifier;
}	t_spec;

/*
**	Macros for flags:
*/
# define PERCENT	1
# define SHARP	2
# define ZERO	3
# define MINUS	4
# define PLUS	5
# define SPACE	6
# define DOT	7

/*
**	Macros for specifiers:
*/
# define CHAR	1
# define STRING	2
# define SINT	3
# define UINT	4
# define SSHORT	5
# define USHORT	6

/*
**	Prototypes:
*/
int	ft_printf(const char *format, ...);
int	parse_spec(char **fmt_str, t_spec *spec);
int	to_string(t_spec *spec, va_list data_args);
int	to_percent(void);

#endif