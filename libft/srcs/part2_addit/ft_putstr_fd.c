/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:38:52 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/11 21:46:50 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Writes the argument string to the argument file descriptor.
**	Returns the amount of bytes written.
*/
int	ft_putstr_fd(char const *c, int fd)
{
	int	ret;

	ret = 0;
	if (c)
		ret = write(fd, c, ft_strlen(c));
	return (ret);
}
/*
** Old loopy ways...
**{
**	if (c)
**		while (*c)
**			ft_putchar_fd(*c++, fd);
**}
*/
