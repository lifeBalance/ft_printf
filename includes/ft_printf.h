/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/07 16:08:17 by rodrodri         ###   ########.fr       */
=======
/*   Updated: 2022/01/07 16:05:16 by rodrodri         ###   ########.fr       */
>>>>>>> 86089ad303569df9b23bb568a780b8acad0fc2b4
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
<<<<<<< HEAD
**	Data types:
*/
=======
**	Nested headers:
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

/*
**	Data types:
*/
>>>>>>> 86089ad303569df9b23bb568a780b8acad0fc2b4
typedef struct s_conv_spec
{
	uint8_t		flags;
	int			width;
	int			precision;
	int			length;
	int			specifier;
}	t_conv_spec;

/*
**	Prototypes:
*/
int ft_printf(const char *format, ...);

#endif