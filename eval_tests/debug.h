/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/18 20:44:38 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "libft.h"
# include "ft_printf.h"
# include "pf_converting.h"
# include "pf_parsing.h"
# include "bitwise.h"
# include <stdio.h>

/*
** Forward declaration
*/
typedef struct s_spec t_spec;

void	print_spec(t_spec *spec);

#endif