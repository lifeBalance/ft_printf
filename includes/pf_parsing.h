/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/11 17:54:52 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PARSING_H
# define PF_PARSING_H

int	parse_flags(char **fmt, t_spec *spec);
int	parse_length(char **fmt, t_spec *spec);
int	parse_width_prec(char **fmt, t_spec *spec);
int	parse_specifier(char **fmt, t_spec *spec);
int	repeated_flag(char ch, t_spec *spec);
int	repeated_width_prec(char ch, t_spec *spec);
int	parse_digits(char **fmt_str, t_spec *spec);

#endif