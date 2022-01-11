/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_string_converter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/11 22:37:13 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	putstr_repeat(char *s, int n);

/*
**	Prints a string. Returns its length.
**	Extracts conversion parameters directly from the format string.
*/
int	to_string(va_list data_args, t_spec *spec)
{
	char	*str;
	size_t	width;
	int		len;

	if (test_bit(WIDTH_ARG, spec->digits))
		width = va_arg(data_args, int);
	else if (test_bit(WIDTH, spec->digits))
		width = spec->width;
	else
		width = 0;
	len = 0;
	str = va_arg(data_args, char *);
	if (ft_strlen(str) < width && !test_bit(MINUS, spec->flags))
	{
		len += putstr_repeat(" ", width - ft_strlen(str));
		len += ft_putstr(str);
	}
	else if (ft_strlen(str) < width && test_bit(MINUS, spec->flags))
	{
		len += ft_putstr(str);
		len += putstr_repeat(" ", width - ft_strlen(str));
	}
	else if (ft_strlen(str) >= width)
		len += ft_putstr(str);
	return (len);
}

/*
**	Prints a string argument 'n' times.
**	Returns the amount of characters (bytes) written.
*/
static int	putstr_repeat(char *s, int n)
{
	int ret;

	ret = 0;
	while (n--)
		ret += ft_putstr(s);
	return (ret);
}
