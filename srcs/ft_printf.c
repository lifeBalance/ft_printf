/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/24 22:23:42 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"

static int		convert(char **fmt, va_list args, t_spec *spec, t_disp *disp);
static void		init_conv_spec(t_spec *spec);
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
	ft_memset(spec, 0, sizeof(*spec));
	ft_memdel((void *)&spec);
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
	char	*cpy;

	len = 0;
	cpy = *fmt;
	ft_memset(spec, 0, sizeof(*spec));
	init_conv_spec(spec);
	if (parse_spec(fmt, args, spec) < 0)
	{
		*fmt = ++cpy;
		while (**fmt && ft_strchr("#0-+ ", **fmt))
			(*fmt)++;
		while (**fmt && ft_strchr("0123456789*.", **fmt))
			(*fmt)++;
		while (**fmt && ft_strchr("hlL", **fmt))
			(*fmt)++;
		return (0);
	}
	len = disp[spec->specifier](args, spec);
	return (len);
}

/*
**	Initializes the conversion specification structure (spec) with some
**	default values.
*/
static void	init_conv_spec(t_spec *spec)
{
	spec->flags = 0;
	spec->width = NOT_SET;
	spec->prec = NOT_SET;
	spec->specifier = NOT_SET;
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
	disp[LOWHEX] = to_hex;
	disp[UPPHEX] = to_upphex;
	disp[INT] = to_int;
	disp[UINT] = to_uint;
	disp[OCTAL] = to_octal;
	disp[FLOAT] = to_float;
	disp[BIN] = to_bin;
}
