/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:07:55 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/08 21:43:09 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"

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
	while ((*fmt_str)[i])
	{
		if (i > 0 && ft_strchr("cspdiuxX%", (*fmt_str)[i]))
		{
			if ((*fmt_str)[i] == '%')
				set_bit(PERCENT, &spec->specifier);
			if ((*fmt_str)[i] == 's')
				set_bit(STRING, &spec->specifier);
			// if (ft_isdigit((*fmt_str)[i]))
			// parse_digits(fmt_str, &i, spec);
			i++;
			break ;
		}
		i++;
	}
	(*fmt_str) += i;
	return (1);
}

// static void	parse_digits(char ch, int *i, t_spec *spec)
// {
// 	while (ft_isdigit((*fmt_str)[*i]))
// {
// }
// }