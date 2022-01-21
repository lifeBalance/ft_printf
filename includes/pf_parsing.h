/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/21 12:24:38 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PARSING_H
# define PF_PARSING_H

/*
**	Macros for flags:
*/
# define SHARP	1
# define ZERO	2
# define MINUS	3
# define PLUS	4
# define SPACE	5

/*
**	Macros for digits flags:
*/
# define WIDTH_ARG	1
# define PREC_ARG	2
# define DOT		3
# define WIDTH		4
# define PREC		5

/*
**	Macros for length:
*/
# define H		1
# define HH		2
# define ELL	3
# define ELLELL	4
# define UPPELL	5

/*
**	Function prototypes:
*/
int	parse_flags(char **fmt, t_spec *spec);
int	parse_length(char **fmt, t_spec *spec);
int	parse_width_prec(char **fmt, va_list args, t_spec *spec);
int	parse_specifier(char **fmt, t_spec *spec);
// int	repeated_flag(char ch, t_spec *spec);
int	repeated_width_prec(char ch, t_spec *spec);
int	parse_digits(char **fmt_str, t_spec *spec);

#endif