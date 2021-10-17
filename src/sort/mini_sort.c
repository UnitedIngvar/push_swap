/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:10 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 20:01:04 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>
#include <limits.h>

static int	sort_two_nums(t_stack *stack)
{
	if (stack->top_index == 0)
		return (1);
	if (stack->top_index != 1)
		return (1);
	if (stack->array[0].value < stack->array[1].value)
		stack_rb(stack);
	return (1);
}

static int	sort_three_nums_asc(t_stack *stack)
{
	int64_t	*sorted_array;

	if (stack->top_index != 2)
		return (-1);
	sorted_array = get_sorted_array(stack->array, 3);
	if (stack->array[2].value == sorted_array[0])
		if (stack->array[1].value == sorted_array[2])
			stack_sa(stack);
	if (stack->array[2].value == sorted_array[2])
	{
		if (stack->array[1].value == sorted_array[0])
			stack_ra(stack);
		else
			stack_sa(stack);
	}
	if (stack->array[2].value == sorted_array[1])
	{
		if (stack->array[1].value == sorted_array[2])
			stack_rra(stack);
		else
			stack_sa(stack);
	}
	return (1);
}

static void	push_rotate_local(t_stack *stack_b, t_stack *stack_a)
{
	stack_pa(stack_b, stack_a);
	stack_ra(stack_a);
}

static int	merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int64_t	beginning;
	t_bool	itered;

	itered = FALSE;
	beginning = stack_a->head.value;
	while (stack_b->top_index >= 0)
	{
		if (stack_b->head.value < stack_a->head.value)
		{
			if (stack_b->head.value < beginning)
				beginning = stack_b->head.value;
			push_rotate_local(stack_b, stack_a);
		}
		else
			stack_ra(stack_a);
		if (beginning == stack_a->head.value && itered)
			break ;
		itered = TRUE;
	}
	while (stack_b->top_index > -1)
		push_rotate_local(stack_b, stack_a);
	while (!is_sorted(stack_a))
		stack_ra(stack_a);
	return (1);
}

int	mini_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top_index < 2)
		return (sort_two_nums(stack_a));
	if (stack_a->top_index == 2)
		return (sort_three_nums_asc(stack_a));
	while (stack_a->top_index > 2)
		stack_pb(stack_a, stack_b);
	sort_two_nums(stack_b);
	sort_three_nums_asc(stack_a);
	return (merge_stacks(stack_a, stack_b));
}
