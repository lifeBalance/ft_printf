/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/22 13:27:08 by rodrodri         ###   ########.fr       */
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
**	Macro for '.' (indicator of precision) flag:
*/
# define DOT	6
# define PREC	12

/*
**	Macros for length:
*/
# define H		7
# define HH		8
# define ELL	9
# define ELLELL	10
# define UPPELL	11

/*
**	Function prototypes:
*/
int	parse_flags(char **fmt, t_spec *spec);
int	parse_length(char **fmt, t_spec *spec);
int	parse_width_prec(char **fmt, va_list args, t_spec *spec);
int	parse_specifier(char **fmt, t_spec *spec);

#endif