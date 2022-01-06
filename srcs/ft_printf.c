/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/06 14:02:57 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	parse_fmt_str(const char *fmt_str, va_list data_args, int *len);
static int	convert_s(char *str);

int	ft_printf(const char *fmt_str, ...)
{
	va_list	data_args;
	int		len;

	va_start(data_args, fmt_str);
	len = 0;
	len = parse_fmt_str(fmt_str, data_args, &len);
	va_end(data_args);
	return (len);
}

/*
**	To get the ball rolling, let's assume we only have to deal with
**	the '%s' conversion specification ;-)
*/
static int	parse_fmt_str(const char *fmt_str, va_list data_args, int *len)
{
	int	i;

	i = 0;
	while (fmt_str[i])
	{
		if (fmt_str[i] == '%' && fmt_str[i + 1] == 's')
		{
			*len += convert_s(va_arg(data_args, char *));
			i += 2;
		}
		else
		{
			ft_putchar(fmt_str[i]);
			i++;
			(*len)++;
		}
	}
	return (*len);
}

/*
**	Prints a string. Returns its length.
*/
static int	convert_s(char *str)
{
	ft_putstr(str);
	return (ft_strlen(str));
}
