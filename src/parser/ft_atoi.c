/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:51:17 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 18:09:31 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_validating_atoi(char *str)
{
	long	i;
	int		minus;
	int		digits;

	digits = 0;
	i = 0;
	minus = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str++ - '0');
		if (++digits > MAX_INT_DIGITS)
			finish_program(FALSE);
	}
	if (!(i * minus >= ELEM_MIN && i * minus <= ELEM_MAX))
		finish_program(FALSE);
	return (i * minus);
}
