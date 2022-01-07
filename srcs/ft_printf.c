/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/07 16:04:43 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int			convert(char **fmt_str, va_list data_args);
static t_conv_spec	*init_conv_spec(void);
static int			to_string(char *fmt_str, char *str);

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
	int			len;
	int			adv;
	t_conv_spec	*conv_spec;

	conv_spec = init_conv_spec();
	if (!conv_spec)
		return (0);
	len = 0; // the proper "converter" would return the value for 'len'
	// find_specifier: parses the specification, finding the specifier at
	// the end. It also sets how many characters we have to advance 
	// the format string to pass the specification.
	conv_spec->specifier = (*fmt_str)[1];
	adv = 2;
	if (conv_spec->specifier == 's')
	{
		(*fmt_str) += adv;
		len = to_string(*fmt_str, va_arg(data_args, char *));
	}
	return (len);
}

static t_conv_spec	*init_conv_spec(void)
{
	t_conv_spec	*conv_spec;

	conv_spec = (t_conv_spec *)malloc(sizeof(*conv_spec));
	if (!conv_spec)
		return (NULL);
	conv_spec->flags = 0;
	conv_spec->length = 0;
	conv_spec->precision = 0;
	conv_spec->specifier = 0;
	conv_spec->width = 0;
	return (conv_spec);
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
