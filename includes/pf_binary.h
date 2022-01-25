/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_binary.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/25 11:22:38 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_BINARY_H
# define PF_BINARY_H

/*
**	Prototypes:
*/
int	to_bin_char(va_list args, t_spec *spec);
int	to_bin_int(va_list args, t_spec *spec);
int	to_bin_long(va_list args, t_spec *spec);
int	to_bin_llong(va_list args, t_spec *spec);

#endif