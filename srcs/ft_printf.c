/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/10 21:37:41 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"

static int		convert(char **fmt, va_list args, t_spec *spec, t_disp *disp);
static t_spec	*init_conv_spec(t_spec *spec);
static void		init_dispatcher(t_disp *disp);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	char	*fmt;
	t_spec	*spec;
	t_disp	disp[FUN];

	init_dispatcher(disp);
	spec = (t_spec *)malloc(sizeof(*spec));
	if (!spec)
		return (0);
	fmt = (char *)format;
	va_start(args, format);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			len += convert(&fmt, args, spec, disp);
		else
			len += ft_putchar(*fmt++);
	}
	va_end(args);
	free(spec);
	return (len);
}

/*
**	Initializes the 'conv_spec' structure to hold all the information
**	contained in the Conversion Specification. The struct is filled by
**	'parse_spec', which returns 0 if there was some error in the specification.
**	Calls the conversion function corresponding to the specifier using a
**	FUNCTION DISPATCHER.
**	Returns the amount of characters taken by the printed data argument.
*/
static int	convert(char **fmt, va_list args, t_spec *spec, t_disp *disp)
{
	int		len;

	len = 0;
	if ((*fmt)[1] && (*fmt)[1] == '%')
	{
		len = disp[PERCENT](args, spec);
		(*fmt) += 2;
		return (len);
	}
	spec = init_conv_spec(spec);
	// mb add 'spec' validation here? e.g. '#' or '0' flags with 's' specifier
	if (parse_spec(fmt, spec) < 0)
		exit (EXIT_FAILURE);
	len = disp[spec->specifier](args, spec);
	return (len);
}

static t_spec	*init_conv_spec(t_spec *spec)
{
	spec->flags = 0;
	spec->width = 0;
	spec->length = 0;
	spec->precision = 0;
	spec->specifier = NOT_SET;
	return (spec);
}

/*
**	Initializes the elements in the FUNCTION DISPATCHER, which is an array
**	of function pointers. Each index in the array is represented using a
**	descriptive macro. Updating the dispatcher is a matter of adding a
**	new element (function pointer) to the array (easily extensible code).
*/
static void	init_dispatcher(t_disp *disp)
{
	disp[PERCENT] = to_percent;
	disp[CHAR] = to_char;
	disp[STRING] = to_string;
	disp[ADDRESS] = to_int;
	disp[LOWHEX] = to_int;
	disp[UPPHEX] = to_int;
	disp[INT] = to_int;
	disp[UINT] = to_int;
	disp[FLOAT] = to_int;
}
