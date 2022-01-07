/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/07 19:43:37 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	Nested headers:
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

/*
**	Data types:
*/
typedef struct s_spec
{
	uint8_t		flags;
	int			width;
	int			precision;
	int			length;
	int			specifier;
}	t_spec;

/*
**	Prototypes:
*/
int		ft_printf(const char *format, ...);
int		to_string(t_spec *spec, char *str);

#endif