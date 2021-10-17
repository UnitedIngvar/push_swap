/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:13 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 12:10:48 by ftassada         ###   ########.fr       */
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

static void	single_a_rotation(t_stack *stack_a, \
	t_stack *stack_b, int64_t fstst_i)
{
	printf("Rotate A\n");
	if (!stack_b->array[fstst_i].is_reversed_a)
		stack_ra(stack_a);
	else
		stack_rra(stack_a);
	stack_b->array[fstst_i].score_a--;
	stack_b->array[fstst_i].score--;
}

static void	single_b_rotation(t_stack *stack_a, \
	t_stack *stack_b, int64_t fstst_i)
{
	printf("Rotate B\n");
	if (!stack_b->array[fstst_i].is_reversed_b)
		stack_rb(stack_a);
	else
		stack_rrb(stack_a);
	stack_b->array[fstst_i].score_b--;
	stack_b->array[fstst_i].score--;
}

void	push_rotate(t_stack *stack_a, t_stack *stack_b, int64_t fstst_i)
{
	while (stack_b->array[fstst_i].score > 0)
	{

		printf("%lld Score\n", stack_b->array[fstst_i].score);
		printf("%lld Score A\n", stack_b->array[fstst_i].score_a);
		printf("%lld Score B\n", stack_b->array[fstst_i].score_b);
		if (stack_b->array[fstst_i].score_a > 0 && \
			stack_b->array[fstst_i].score_b > 0)
		{
			if (try_double_rotation(stack_a, stack_b, fstst_i))
			{
				printf("lil nax X\n");
				stack_b->array[fstst_i].score_b--;
				stack_b->array[fstst_i].score_a--;
				stack_b->array[fstst_i].score -= 2;
				continue ;
			}
		}
		if (stack_b->array[fstst_i].score_a > 0)
		{
			printf("chacaron\n");
			single_a_rotation(stack_a, stack_b, fstst_i);
		}
		if (stack_b->array[fstst_i].score_b > 0)
		{
			printf("macaroon\n");
			single_b_rotation(stack_a, stack_b, fstst_i);
		}
		usleep(10000);
	}
	stack_pa(stack_b, stack_a);
}
