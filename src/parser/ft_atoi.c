/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:51:17 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 19:14:04 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' \
	|| c == '\v' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_put_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

int	ft_isdigit(char *str)
{
	int	minus_counter;
	int	plus_counter;

	minus_counter = 0;
	plus_counter = 0;
	while (ft_is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_counter++;
		else if (*str == '+')
			plus_counter++;
		str++;
	}
	if (minus_counter > 1 || plus_counter > 1 || \
		(plus_counter == 1 && minus_counter == 1))
		return (0);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str && !(*str >= '0' && *str <= '9'))
		return (0);
	return (1);
}

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
			ft_put_error();
	}
	if (!(i * minus >= ELEM_MIN && i * minus <= ELEM_MAX))
		ft_put_error();
	return (i * minus);
}
