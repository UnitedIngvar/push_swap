/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_AB.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:47:21 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 14:47:28 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	stack_ss(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap(stack_a);
	stack_swap(stack_b);
	write(1, "ss\n", 3);
}

void	stack_rr(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate(stack_a);
	stack_rotate(stack_b);
	write(1, "rr\n", 3);
}

void	stack_rrr(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate_reverse(stack_a);
	stack_rotate_reverse(stack_b);
	write(1, "rrr\n", 4);
}
