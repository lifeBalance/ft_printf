/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/07 14:37:58 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	convert(char **fmt_str, va_list data_args);
static int	to_string(char *fmt_str, char *str);

int	ft_printf(const char *format, ...)
{
	va_list	data_args;
	int		len;
	char	*fmt_str;

	fmt_str = (char *)format;
	va_start(data_args, format);
	len = 0;
	while (*fmt_str)
	{
		if (*fmt_str == '%')
			len += convert(&fmt_str, data_args);
		else
		{
			ft_putchar(*fmt_str);
			fmt_str++;
			len++;
		}
	}
	va_end(data_args);
	return (len);
}

/*
**	Parse the Conversion Specification.
**	Maybe here I should be parsing the spec. to find the proper specifier?
**	Advance the format string to the end of the specification.
**	Calls the function corresponding to the specifier.
*/
static int	convert(char **fmt_str, va_list data_args)
{
	int		len;
	int		adv;
	char	specifier;

	len = 0; // the proper "converter" would return the value for 'len'
	// find_specifier: parses the specification, finding the specifier at
	// the end. It also sets how many characters we have to advance 
	// the format string to pass the specification.
	specifier = (*fmt_str)[1];
	adv = 2;
	if (specifier == 's')
	{
		(*fmt_str) += adv;
		len = to_string(*fmt_str, va_arg(data_args, char *));
	}
	return (len);
}

/*
**	Prints a string. Returns its length.
**	Extracts conversion parameters directly from the format string.
*/
static int	to_string(char *fmt_str, char *str)
{
	(void)fmt_str; // here we would parse the fmt_str to extract intel
	ft_putstr(str);
	return (ft_strlen(str));
}
