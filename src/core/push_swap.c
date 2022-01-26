/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:54 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 18:25:57 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack_b(int64_t size)
{
	t_stack	*stack_b;
	int64_t	index;

	stack_b = safe_malloc(sizeof(*stack_b));
	stack_b->array = safe_malloc(sizeof(*(stack_b->array)) * size);
	stack_b->top_index = EMPTY;
	stack_b->length = size;
	index = 0;
	while (index < size)
	{
		stack_b->array[index].value = 0;
		stack_b->array[index].score_a = 0;
		stack_b->array[index].score_b = 0;
		stack_b->array[index].score = 0;
		stack_b->array[index].is_reversed_a = FALSE;
		stack_b->array[index].is_reversed_b = FALSE;
		index++;
	}
	return (stack_b);
}

static t_stack	*init_stack_a(int64_t *values, int64_t size)
{
	t_stack	*stack_a;
	int64_t	index;
	int64_t	stack_index;

	stack_a = safe_malloc(sizeof(*stack_a));
	stack_index = size - 1;
	stack_a->array = safe_malloc(sizeof(*(stack_a->array)) * size);
	index = 0;
	while (index < size)
	{
		stack_a->array[stack_index].value = values[index];
		stack_a->array[stack_index].score_a = 0;
		stack_a->array[stack_index].score_b = 0;
		stack_a->array[stack_index].score = 0;
		stack_a->array[stack_index].is_reversed_a = FALSE;
		stack_a->array[stack_index].is_reversed_b = FALSE;
		index++;
		stack_index--;
	}
	stack_a->top_index = size - 1;
	stack_a->length = size;
	stack_a->head = stack_a->array[size - 1];
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int64_t	*values;
	int64_t	stack_size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_size = argc - 1;
	init_rollback_context();
	values = parse_values(argv + 1, stack_size);
	stack_a = init_stack_a(values, stack_size);
	stack_b = init_stack_b(stack_size);
	sort_stack(stack_a, stack_b, stack_a->length);
	finish_program(TRUE);
}
