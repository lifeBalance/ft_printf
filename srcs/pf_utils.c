/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/07 18:10:18 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
**	Prints a string. Returns its length.
**	Extracts conversion parameters directly from the format string.
*/
int	to_string(t_conv_spec *conv_spec, char *str)
{
	(void)conv_spec; // here we would extract the relevant info from the struct
	ft_putstr(str);
	return (ft_strlen(str));
}
