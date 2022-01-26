/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:13 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 16:29:09 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static t_bool	try_double_rotation(t_stack *stack_a, \
	t_stack *stack_b, t_scored *elem)
{
	if (!elem->is_reversed_a && \
		!elem->is_reversed_b)
	{
		stack_rr(stack_a, stack_b);
		return (TRUE);
	}
	else if (elem->is_reversed_a && \
		elem->is_reversed_b)
	{
		stack_rrr(stack_a, stack_b);
		return (TRUE);
	}
	return (FALSE);
}

static void	single_a_rotation(t_stack *stack_a, t_scored *elem)
{
	if (!elem->is_reversed_a)
		stack_ra(stack_a);
	else
		stack_rra(stack_a);
	elem->score_a--;
	elem->score--;
}

static void	single_b_rotation(t_stack *stack_b, t_scored *elem)
{
	elem->score_b--;
	elem->score--;
	if (!elem->is_reversed_b)
		stack_rb(stack_b);
	else
		stack_rrb(stack_b);
}

void	push_rotate(t_stack *stack_a, t_stack *stack_b, t_scored elem)
{
	while (elem.score > 0)
	{
		if (elem.score_a > 0 && \
			elem.score_b > 0)
		{
			if (try_double_rotation(stack_a, stack_b, &elem))
			{
				elem.score_b--;
				elem.score_a--;
				elem.score -= 2;
				continue ;
			}
		}
		if (elem.score_a > 0)
			single_a_rotation(stack_a, &elem);
		if (elem.score_b > 0)
			single_b_rotation(stack_b, &elem);
	}
	stack_pa(stack_b, stack_a);
}
