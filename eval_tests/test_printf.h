/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/19 12:43:22 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PRINTF_H
# define TEST_PRINTF_H

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

/*
** PROTOTYPES
*/
void	test_percent(void);
void	test_char(void);
void	test_string(void);
void	test_address(void);
void	test_integer(void);
void	test_octal(void);
void	test_unsigned_int(void);
void	test_hexadecimal(void);
void	test_upper_hex(void);
void	test_float(void);

#endif