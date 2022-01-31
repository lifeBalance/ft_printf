/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 00:48:12 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/31 22:35:36 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitwise.h"

uint16_t	test_bit(uint8_t pos, uint16_t val)
{
	return ((val & (1 << pos)) > 0);
}

void	set_bit(uint8_t pos, uint16_t *val)
{
	*val |= (1 << pos);
}

void	clear_bit(uint8_t pos, uint16_t *val)
{
	*val &= ~(1 << pos);
}

void	toggle_bit(uint8_t pos, uint16_t *val)
{
	*val ^= (1 << pos);
}
