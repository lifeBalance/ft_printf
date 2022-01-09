/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:07:55 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/09 14:56:26 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"

static int	parse_specifier(char ch, t_spec *spec);
// static void	parse_digits(char **fmt_str, int *i, t_spec *spec);

/*
**	Parses the Conversion Specification, filling up the 'conv_spec' structure
**	with the characters that appeared in the format string after the '%'.
**	Also, while traversing the specification, it moves forward the Format
**	String pointer.
**	Returns an integer with the status code of the parsing operation.
*/
int	parse_spec(char **fmt_str, t_spec *spec)
{
	int	i;

	i = 0;
	while (spec->specifier == NOT_SET)
	{
		if (i > 0 && ft_strchr("cspdiuxX%", (*fmt_str)[i]))
			i += parse_specifier((*fmt_str)[i], spec);
		// else if (i > 0 && ft_strchr("#0-+ ", (*fmt_str)[i]))
		// 	(*fmt_str) += parse_flags();
		// else if (i > 0 && ft_strchr("hlL", (*fmt_str)[i]))
		// 	(*fmt_str) += parse_length();
		// else if (i > 0 && ft_strchr("0123456789", (*fmt_str)[i]))
		// 	(*fmt_str) += parse_digits(fmt_str, &i, spec);
		else
			i++;
	}
	(*fmt_str) += i;
	return (1);
}

/*
**	Receives a specifier character and set the specifier field in the 'spec'
**	structure. Returns 1 (length of the specifier), that the caller can use
**	to advance the format string.
*/
static int	parse_specifier(char ch, t_spec *spec)
{
	if (ch == '%')
		spec->specifier = PERCENT;
	else if (ch == 'c')
		spec->specifier = CHAR;
	else if (ch == 's')
		spec->specifier = STRING;
	return (1);
}
// static int	parse_digits(char ch, int *i, t_spec *spec)
// {
// 	while (ft_isdigit((*fmt_str)[*i]))
// {
// }
// }