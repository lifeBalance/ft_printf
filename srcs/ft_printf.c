/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/16 12:11:28 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_parsing.h"

static int		convert(char **fmt, va_list args, t_spec *spec, t_disp *disp);
static int		parse_spec(char **fmt, t_spec *spec);
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
	spec = init_conv_spec(spec);
	if (parse_spec(fmt, spec) < 0)
		exit (EXIT_FAILURE);
	// print_spec(spec);
	// return (0);
	len = disp[spec->specifier](args, spec);
	return (len);
}

/*
**	Parses the Conversion Specification, filling up the 'spec' structure
**	with the flags, and stuff that appear in the format string after the '%',
**	up to, and including, the specifier. It receives the address of the format
**	string so that, while traversing the specification, it moves forward the
**	Format String pointer.
**	Returns an integer with the status code of the parsing operation (0 for
**	no errors and -1 for error).
*/
int	parse_spec(char **fmt, t_spec *spec)
{
	int	ret;

	ret = 0;
	(*fmt)++;
	if (ft_strchr("#0-+ ", **fmt))
		ret += parse_flags(fmt, spec);
	if (ft_strchr("0123456789*.", **fmt))
		ret = parse_width_prec(fmt, spec);
	if (ft_strchr("hlL", **fmt))
		ret += parse_length(fmt, spec);
	if (ft_strchr("cspdiouxX%", **fmt))
		ret += parse_specifier(fmt, spec);
	if (spec->specifier == NOT_SET)
		ret = -1;
	return (ret);
}

/*
**	Initializes the conversion specification structure (spec) with some
**	default values.
*/
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
	disp[ADDRESS] = to_address;
	disp[LOWHEX] = to_int;
	disp[UPPHEX] = to_int;
	disp[INT] = to_int;
	disp[UINT] = to_uint;
	disp[OCTAL] = to_octal;
	disp[FLOAT] = to_int;
}
