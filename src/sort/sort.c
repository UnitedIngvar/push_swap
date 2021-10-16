/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:32 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 19:06:59 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	sort_stack(t_stack *stack_a, t_stack *stack_b, int64_t length)
{
	if (length <= MINISORT_MAX_STACK_SIZE)
		mini_sort(stack_a, stack_b);
	else
		full_sort(stack_a, stack_b);
}

int main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int64_t length = 10;

	stack_a = malloc(sizeof(t_stack));
	stack_a->array = malloc(sizeof(t_scored) * length);
	stack_a->array[0].value = 4636;
	stack_a->array[1].value = -346263;
	stack_a->array[2].value = -45634;
	stack_a->array[3].value = 5438;
	stack_a->array[4].value = 876;
	stack_a->array[5].value = 876586;
	stack_a->array[6].value = 7564;
	stack_a->array[7].value = -76595;
	stack_a->array[8].value = 858758;
	stack_a->array[9].value = 87956956;
	stack_a->top_index = length - 1;
	stack_a->length = length;
	stack_a->head = stack_a->array[9];

	stack_b = malloc(sizeof(t_stack));
	stack_b->array = malloc(sizeof(int64_t) * length);
	stack_b->top_index = -1;
	stack_b->length = length;
	sort_stack(stack_a, stack_b, length);
	print_stack(stack_a, "stack A at the end:	");
}
