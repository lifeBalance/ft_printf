/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converting.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/13 17:34:33 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_CONVERTING_H
# define PF_CONVERTING_H

void	set_width(t_spec *spec, va_list data_args, int *width);
void	set_precision(t_spec *spec, va_list data_args, int *prec);
int		putstr_repeat(char *s, int n);
void	cancel_flags(t_spec *spec);

#endif