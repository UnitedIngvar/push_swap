/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:49:08 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 19:17:01 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || \
		c == '\r' || c == '\v' || c == '\f')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_is_digit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
