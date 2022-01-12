/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_percent_converter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/12 21:22:04 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
**	Prints a percent sign. Returns the amount of bytes written.
**	(Ignores all the flags and directives, hence the casting to void).
*/
int	to_percent(va_list data_args, t_spec *conv_spec)
{
	(void)data_args;
	(void)conv_spec;
	return (ft_putchar('%'));
}
