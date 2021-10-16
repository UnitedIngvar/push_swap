/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:06:04 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 19:12:34 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../push_swap.h"

t_bool	ft_is_space(char c);
t_bool	ft_is_digit(int c);
int		ft_atoi(char *str)

# define MAX_INT_DIGITS 10
# define ELEM_MIN −2 147 483 648
# define ELEM_MAX 2 147 483 647

#endif
