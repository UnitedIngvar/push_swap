/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_common.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:47:44 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 11:42:22 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *stack_from, t_stack *stack_to)
{
	if (stack_from->top_index == EMPTY || stack_from->length == 0)
		return ;
	stack_to->top_index++;
	stack_to->head = stack_from->head;
	stack_to->array[stack_to->top_index] = \
		stack_from->array[stack_from->top_index];
	stack_from->top_index--;
	if (stack_from->top_index > EMPTY)
		stack_from->head = stack_from->array[stack_from->top_index];
}

void	stack_swap(t_stack *stack)
{
	t_scored	temp;

	if (stack->top_index == EMPTY || stack->length == 0)
		return ;
	temp = stack->head;
	stack->array[stack->top_index] = stack->array[stack->top_index - 1];
	stack->head = stack->array[stack->top_index - 1];
	stack->array[stack->top_index - 1] = temp;
}

void	stack_rotate(t_stack *stack)
{
	int			i_count;
	t_scored	top_num;

	i_count = stack->top_index;
	top_num = stack->array[i_count];
	while (i_count > 0)
	{
		stack->array[i_count] = stack->array[i_count - 1];
		i_count--;
	}
	stack->array[0] = top_num;
	stack->head = stack->array[stack->top_index];
}

void	stack_rotate_reverse(t_stack *stack)
{
	int			i_count;
	t_scored	bottom_num;

	if (stack->top_index <= 0 || stack->length == 0)
		return ;
	i_count = 0;
	bottom_num = stack->array[0];
	while (i_count < stack->top_index)
	{
		stack->array[i_count] = stack->array[i_count + 1];
		i_count++;
	}
	stack->array[stack->top_index] = bottom_num;
	stack->head = stack->array[stack->top_index];
}
