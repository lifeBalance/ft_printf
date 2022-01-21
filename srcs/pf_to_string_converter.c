/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_string_converter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/21 12:30:58 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

static int	putstr_upto_n(char *s, int n);
static int	putstr_aligned(char *str, t_spec *spec);

/*
**	Prints a string. Returns its length.
**	Extracts conversion parameters directly from the 'spec' structure.
*/
int	to_string(va_list data_args, t_spec *spec)
{
	char	*str;
	int		ret;
	int		null_str;

	// set_width_arg(spec, data_args);
	// set_prec_arg(spec, data_args);
	str = va_arg(data_args, char *);
	null_str = 0;
	if (str == NULL)
	{
		str = ft_strsub("(null)", 0, ft_strlen("(null)"));
		if (!str)
			exit (EXIT_FAILURE);
		null_str = 1;
	}
	ret = 0;
	ret += putstr_aligned(str, spec);
	if (null_str)
		ft_strdel(&str);
	return (ret);
}

static int	putstr_aligned(char *str, t_spec *spec)
{
	int		ret;

	ret = 0;
	if (spec->prec == NOT_SET || spec->prec > (int)ft_strlen(str))
		spec->prec = ft_strlen(str);
	if (spec->width > 0 && spec->prec < spec->width && \
		!test_bit(MINUS, spec->flags))
		ret += putstr_repeat(" ", spec->width - spec->prec);
	ret += putstr_upto_n(str, spec->prec);
	if (spec->width > 0 && spec->prec < spec->width && \
		test_bit(MINUS, spec->flags))
		ret += putstr_repeat(" ", spec->width - spec->prec);
	return (ret);
}

/*
**	It prints up to 'n' characters from a string argument. It returns the
**	amount of written characters (bytes). 
*/
static int	putstr_upto_n(char *s, int n)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (i < n)
	{
		ret += ft_putchar(s[i]);
		i++;
	}
	return (ret);
}
