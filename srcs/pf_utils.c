/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/10 20:35:06 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
**	Prints a string. Returns its length.
**	Extracts conversion parameters directly from the format string.
*/
int	to_string(va_list data_args, t_spec *conv_spec)
{
	char *str;
	(void)conv_spec; // here we would extract the relevant info from the struct

	str = va_arg(data_args, char *);
	ft_putstr(str);
	return (ft_strlen(str));
}

/*
**	Prints a percent sign. Returns the amount of bytes written.
*/
int	to_percent(va_list data_args, t_spec *conv_spec)
{
	(void)data_args;
	(void)conv_spec;
	ft_putchar('%');
	return (1);
}

/*
**	Prints a character sign. Returns the amount of bytes written.
*/
int	to_char(va_list data_args, t_spec *conv_spec)
{
	(void)data_args;
	(void)conv_spec;
	ft_putchar('%');
	return (1);
}

/*
**	Prints an integer. Returns the amount of bytes written.
*/
int	to_int(va_list data_args, t_spec *conv_spec)
{
	(void)data_args;
	print_spec(conv_spec);
	return (1);
}
