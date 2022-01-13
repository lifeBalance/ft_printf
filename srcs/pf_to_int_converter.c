/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_int_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/13 11:46:37 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
**	Prints an integer. Returns the amount of bytes written.
*/
int	to_int(va_list data_args, t_spec *spec)
{
	int	n;
	int	ret;
(void)spec;
	ret = 0;
	n = va_arg(data_args, int);
	ret = ft_putnbr(n);
	return (ret);
}
