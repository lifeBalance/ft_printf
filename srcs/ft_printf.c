/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/09 12:41:21 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"

static int		convert(char **fmt_str, va_list data_args, t_spec *spec);
static t_spec	*init_conv_spec(t_spec *spec);
static void		init_dispatcher(t_disp *dispatcher);

int	ft_printf(const char *format, ...)
{
	va_list	data_args;
	int		len;
	char	*fmt_str;
	t_spec	*spec;

	spec = (t_spec *)malloc(sizeof(*spec));
	if (!spec)
		return (0);
	fmt_str = (char *)format;
	va_start(data_args, format);
	len = 0;
	while (*fmt_str)
	{
		if (*fmt_str == '%')
			len += convert(&fmt_str, data_args, spec);
		else
			len += ft_putchar(*fmt_str++);
	}
	va_end(data_args);
	free(spec);
	return (len);
}

/*
**	Initializes the 'conv_spec' structure to hold all the information
**	contained in the Conversion Specification. The struct is filled by
**	'parse_spec', which returns 0 if there was some error in the specification.
**	Calls the function corresponding to the specifier.
**	Prints the converted data argument according to the specification.
**	Returns the amount of characters taken by the printed data argument.
*/
static int	convert(char **fmt_str, va_list data_args, t_spec *spec)
{
	int		len;
	t_disp	dispatcher[FUN];

	len = 0;
	spec = init_conv_spec(spec);
	init_dispatcher(dispatcher);
	if (!parse_spec(fmt_str, spec))
		return(0);
	if (spec->specifier < 0)
		return(0);
	// The awesome function dispatcher!!
	len = dispatcher[spec->specifier](data_args, spec);
	return (len);
}

static t_spec	*init_conv_spec(t_spec *spec)
{
	spec->flags = 0;
	spec->width = 0;
	spec->length = 0;
	spec->precision = 0;
	spec->specifier = -1;
	return (spec);
}

static void	init_dispatcher(t_disp *dispatcher)
{
	dispatcher[PERCENT] = to_percent;
	dispatcher[CHAR] = to_char;
	dispatcher[STRING] = to_string;
}
