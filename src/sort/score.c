/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:25 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 19:16:05 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	add_a_score(t_stack *stack_a, t_scored *elem)
{
	int64_t	index;
	int64_t	score_add;

	score_add = 1;
	if (stack_a->head.value > elem->value && \
		stack_a->array[0].value < elem->value)
		return ;
	index = stack_a->top_index + 1;
	elem->is_reversed_a = FALSE;
	while (--index > 0)
	{
		elem->score_a += score_add;
		if (index == stack_a->top_index / 2)
		{
			score_add = -1;
			elem->score_a += score_add;
			elem->is_reversed_a = TRUE;
		}
		if (stack_a->array[index].value < elem->value && \
			stack_a->array[index - 1].value > elem->value)
		{
			if (stack_a->top_index % 2 && elem->is_reversed_a == TRUE)
				elem->score_a--;
			return ;
		}
	}
}

static void	add_b_score(t_stack *stack_b, int64_t index, t_scored *elem)
{
	if (index >= stack_b->top_index / 2)
	{
		elem->is_reversed_b = FALSE;
		elem->score_b = stack_b->top_index - index;
	}
	else
	{
		elem->is_reversed_b = TRUE;
		elem->score_b = index + 1;
	}
}

void	assign_scores(t_stack *stack_a, t_stack *stack_b)
{
	int64_t	el_index;

	el_index = stack_b->top_index;
	while (el_index >= 0)
	{
		add_a_score(stack_a, &(stack_b->array[el_index]));
		add_b_score(stack_b, el_index, &(stack_b->array[el_index]));
		stack_b->array[el_index].score = \
			stack_b->array[el_index].score_a + \
			stack_b->array[el_index].score_b;
		el_index--;
	}
}

void	clear_scores(t_stack *stack_a, t_stack *stack_b)
{
	int64_t	index;

	index = stack_a->top_index;
	while (index >= 0)
	{
		stack_a->array[index].is_reversed_a = FALSE;
		stack_a->array[index].is_reversed_b = FALSE;
		stack_a->array[index].score_b = 0;
		stack_a->array[index].score_a = 0;
		stack_a->array[index].score = 0;
		index--;
	}
	index = stack_b->top_index;
	while (index >= 0)
	{
		stack_b->array[index].is_reversed_a = FALSE;
		stack_b->array[index].is_reversed_b = FALSE;
		stack_b->array[index].score_b = 0;
		stack_b->array[index].score_a = 0;
		stack_b->array[index].score = 0;
		index--;
	}
}
