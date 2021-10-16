/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:54 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 19:16:57 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*init_stack_b(int64_t size)
{
	t_stack	*stack_b;
	int64_t	index;

	stack_b = malloc(sizeof(stack_b));
	if (stack_b == NULL)
		return (NULL);
	stack_b->array = malloc(sizeof(stack_b->array) * size);
	if (stack_b->array == NULL)
		return (NULL);
	stack_b->top_index = EMPTY;
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
}

static t_stack	*init_stack_a(int64_t *values, int64_t size)
{
	t_stack	*stack_a;
	int64_t	index;

	stack_a = malloc(sizeof(t_stack));
	if (stack_a == NULL)
		return (NULL);
	stack_a->array = malloc(sizeof(t_scored) * size);
	if (stack_a->array == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		stack_a->array[index].value = values[index];
		stack_a->array[index].score_a = 0;
		stack_a->array[index].score_b = 0;
		stack_a->array[index].score = 0;
		stack_a->array[index].is_reversed_a = FALSE;
		stack_a->array[index].is_reversed_b = FALSE;
		index++;
	}
	stack_a->top_index = size - 1;
	stack_a->length = size;
	stack_a->head = stack_a->array[size - 1];
}

int	main(int argc, char **argv)
{
	int64_t	*values;
	int64_t	stack_size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 3)
		return (0);
	stack_size = argc - 2;
	values = parse_values(argv + 2, stack_size);
	stack_a = init_stack_a(values, stack_size);
	stack_b = init_stack_b(stack_size);
	sort_stack_a(stack_a, stack_b);
}
