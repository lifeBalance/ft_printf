/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/07 18:13:32 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int			convert(char **fmt_str, va_list data_args);
static t_conv_spec	*init_conv_spec(void);
static int			parse_spec(char *fmt_str, t_conv_spec *conv_spec);

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
**	Parses the Conversion Specification, filling up the 'conv_spec' structure
**	with the characters that appeared in the format string after the '%'.
**	Returns an integer which represents the amount of characters in the spec.
**  This returned value is used in the caller to advance the Format String
**	passed the Conversion Specification.
*/
static int	parse_spec(char *fmt_str, t_conv_spec *conv_spec)
{
	int			adv;

	adv = 0;
	conv_spec->specifier = fmt_str[1];
	adv += 2;
	return (adv);
}

/*
**	Allocates and initializes the 'conv_spec' structure to hold all the
**	information contained in the Conversion Specification. The struct is
**	filled by 'parse_spec', which returns an integer used to advance the
**	format string to the end of the specification.
**	Calls the function corresponding to the specifier.
**	Prints the converted data argument according to the specification.
**	Returns the amount of characters taken by the printed data argument.
*/
static int	convert(char **fmt_str, va_list data_args)
{
	int			len;
	t_conv_spec	*conv_spec;

	len = 0;
	conv_spec = init_conv_spec();
	if (!conv_spec)
		return (0);
	*fmt_str += parse_spec(*fmt_str, conv_spec);
	if (conv_spec->specifier == 's')
		len = to_string(conv_spec, va_arg(data_args, char *));
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
