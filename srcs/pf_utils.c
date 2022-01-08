/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/08 20:34:54 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
**	Prints a string. Returns its length.
**	Extracts conversion parameters directly from the format string.
*/
int	to_string(t_spec *conv_spec, va_list data_args)
{
	char *str;
	(void)conv_spec; // here we would extract the relevant info from the struct

	str = va_arg(data_args, char *);
	ft_putstr(str);
	return (ft_strlen(str));
}

/*
**	Prints a percent sign. Returns its length, 1.
*/
int	to_percent(void)
{
	ft_putchar('%');
	return (1);
}
