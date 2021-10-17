/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:47:59 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 11:20:50 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	printf("Starting pushing to A\n");
	int64_t	fastest_index;
	int64_t	index;

	fastest_index = 0;
	index = -1;
	while (++index <= stack_b->top_index)
	{
		if (stack_b->array[index].score <= stack_b->array[fastest_index].score)
			fastest_index = index;
	}
	printf("Fastet index: %lli\n", fastest_index);
	push_rotate(stack_a, stack_b, fastest_index);
	printf("finished pushing to A\n");
}

static void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	printf("Starting pushing to B\n");
	t_specs	specials;
	int64_t	*sorted_array;

	sorted_array = get_sorted_array(stack_a->array, stack_a->top_index + 1);
	printf("Found sorted array!");
	specials = find_special_values(sorted_array, stack_a->top_index + 1);
	printf("Found specials!");
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
		print_stack(stack_a, "Stack A:	");
		print_stack(stack_b, "Stack B:	");
	}
	printf("finished pushing to B\n");
}

int	full_sort(t_stack *stack_a, t_stack *stack_b)
{
	push_to_b(stack_a, stack_b);

	printf("Now trying to execute push to A!!!\n");
	while (stack_b->top_index > EMPTY)
	{
		printf("A top index:	%lli\n\n", stack_b->top_index);
		printf("Starting clearing scores!\n");
		clear_scores(stack_a, stack_b);
		printf("Cleared scores! Here they are\n");
		print_all(stack_a, stack_b);
		printf("\n\nStarting assigning scores!\n");
		assign_scores(stack_a, stack_b);
		printf("Assigned scores! Here they are:\n\n");
		print_all(stack_a, stack_b);
		push_to_a(stack_a, stack_b);
	}
	while (!is_sorted(stack_a))
		stack_ra(stack_a);
	return (1);
}
