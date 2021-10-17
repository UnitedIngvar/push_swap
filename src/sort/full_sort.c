/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:47:59 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 16:20:02 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int64_t	fastest_index;
	int64_t	index;

	fastest_index = 0;
	index = -1;
	while (++index <= stack_b->top_index)
	{
		if (stack_b->array[index].score <= stack_b->array[fastest_index].score)
			fastest_index = index;
	}
	printf("Pusing to A! Fastest index = %lli\n", fastest_index);
	push_rotate(stack_a, stack_b, stack_b->array[fastest_index]);
}

static void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_specs	specials;
	int64_t	*sorted_array;

	sorted_array = get_sorted_array(stack_a->array, stack_a->top_index + 1);
	specials = find_special_values(sorted_array, stack_a->top_index + 1);
	while (stack_a->top_index > 1)
	{
		if (stack_a->head.value != specials.min && \
		stack_a->head.value != specials.max)
		{
			stack_pb(stack_a, stack_b);
			if (stack_b->head.value > specials.mid)
				stack_rb(stack_b);
		}
		else
			stack_ra(stack_a);
	}
}

int	full_sort(t_stack *stack_a, t_stack *stack_b)
{
	int64_t topindex;
	push_to_b(stack_a, stack_b);

	while (stack_b->top_index > EMPTY)
	{
		printf("\nClearring scores, here they are!\n\n");
		clear_scores(stack_a, stack_b);
		print_all(stack_a, stack_b);
		printf("\nAssigning scores, here they are!\n\n");
		assign_scores(stack_a, stack_b);
		print_all(stack_a, stack_b);
		push_to_a(stack_a, stack_b);
	}

	while (!is_sorted(stack_a))
	{
		topindex = stack_a->top_index;
		printf("Stack A: ");
		while (topindex >= 0)
		{
			printf("%lld ", stack_a->array[topindex--].value);
		}
		printf("\n");
		stack_ra(stack_a);
	}
	topindex = stack_a->top_index;
	printf("Stack A: ");
	while (topindex >= 0)
	{
		printf("%lld ", stack_a->array[topindex--].value);
	}
	return (1);
}
