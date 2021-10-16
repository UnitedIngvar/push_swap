/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_B.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:47:35 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 14:47:39 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	stack_sb(t_stack *stack)
{
	stack_swap(stack);
	write(1, "sb\n", 3);
}

void	stack_pb(t_stack *stack_a, t_stack *stack_b)
{
	stack_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	stack_rb(t_stack *stack)
{
	stack_rotate(stack);
	write(1, "rb\n", 3);
}

void	stack_rrb(t_stack *stack)
{
	stack_rotate_reverse(stack);
	write(1, "rrb\n", 4);
}
