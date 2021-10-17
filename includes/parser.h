/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:06:04 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 21:29:18 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "push_swap.h"

t_bool	ft_is_space(char c);
t_bool	ft_is_digit(int c);
int		ft_validating_atoi(char *str);

# define MAX_INT_DIGITS 10
# define ELEM_MIN -2147483648
# define ELEM_MAX 2147483647

#endif
