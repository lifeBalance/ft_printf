/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:38:52 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/13 11:17:55 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Prints to standard output the integer argument.
**	Returns the amount of characters (bytes) written.
*/
int	ft_putnbr(int n)
{
	return (ft_putnbr_fd(n, 1));
}
