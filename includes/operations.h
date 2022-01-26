/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:47:50 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 19:58:18 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "push_swap.h"

void	stack_push(t_stack *stack_from, t_stack *stack_to);
void	stack_swap(t_stack *stack);
void	stack_rotate(t_stack *stack);
void	stack_rotate_reverse(t_stack *stack);

#endif
