/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:13 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 14:48:14 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static t_bool	try_double_rotation(t_stack *stack_a, \
	t_stack *stack_b, int64_t fstst_i)
{
	if (!stack_b->array[fstst_i].is_reversed_a && \
		!stack_b->array[fstst_i].is_reversed_b)
	{
		stack_rr(stack_a, stack_b);
		return (TRUE);
	}
	else if (stack_b->array[fstst_i].is_reversed_a && \
		stack_b->array[fstst_i].is_reversed_b)
	{
		stack_rrr(stack_a, stack_b);
		return (TRUE);
	}
	return (FALSE);
}

static int	single_a_rotation(t_stack *stack_a, \
	t_stack *stack_b, int64_t fstst_i)
{
	if (!stack_b->array[fstst_i].is_reversed_a)
		stack_ra(stack_a);
	else
		stack_rra(stack_a);
	stack_b->array[fstst_i].score_a--;
	stack_b->array[fstst_i].score--;
}

static int	single_b_rotation(t_stack *stack_a, \
	t_stack *stack_b, int64_t fstst_i)
{
	if (!stack_b->array[fstst_i].is_reversed_a)
		stack_ra(stack_a);
	else
		stack_rra(stack_a);
	stack_b->array[fstst_i].score_a--;
	stack_b->array[fstst_i].score--;
}

int	push_rotate(t_stack *stack_a, t_stack *stack_b, int64_t fstst_i)
{
	while (stack_b->array[fstst_i].score > 0)
	{
		if (stack_b->array[fstst_i].score_a > 0 && \
			stack_b->array[fstst_i].score_b > 0)
		{
			if (try_double_rotation(stack_a, stack_b, fstst_i))
			{
				stack_b->array[fstst_i].score_b--;
				stack_b->array[fstst_i].score_a--;
				stack_b->array[fstst_i].score -= 2;
				continue ;
			}
		}
		if (stack_b->array[fstst_i].score_a > 0)
			single_a_rotation(stack_a, stack_b, fstst_i);
		if (stack_a->array[fstst_i].score_b > 0)
			single_b_rotation(stack_a, stack_b, fstst_i);
	}
	stack_pa(stack_b, stack_a);
}
