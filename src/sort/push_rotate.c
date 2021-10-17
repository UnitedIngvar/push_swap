/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:13 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 16:15:46 by hcrakeha         ###   ########.fr       */
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
	printf("Rotate A\n");
	if (!elem->is_reversed_a)
		stack_ra(stack_a);
	else
		stack_rra(stack_a);
	elem->score_a--;
	elem->score--;
}

static void	single_b_rotation(t_stack *stack_b, t_scored *elem)
{
	printf("Rotate B\n");
	elem->score_b--;
	elem->score--;
	if (!elem->is_reversed_b)
		stack_rb(stack_b);
	else
		stack_rrb(stack_b);
}

void	push_rotate(t_stack *stack_a, t_stack *stack_b, t_scored elem)
{
	// int sleep_time = 0;

	while (elem.score > 0)
	{
		// printf("%lld Score\n", stack_b->array[fstst_i].score);
		// printf("%lld Score A\n", stack_b->array[fstst_i].score_a);
		// printf("%lld Score B\n", stack_b->array[fstst_i].score_b);
		// if (elem->value == 3636)
		// {
		// 	printf("ALARM! Edge value!!!\n");
		// 	printf("B scores: %lli\n", elem->score_b);
		// 	printf("A scores: %lli\n", elem->score_a);
		// 	printf("is reversed b? : %i\n", elem->is_reversed_b);
		// 	printf("is reversed a? : %i\n", elem->is_reversed_a);
		// 	sleep_time = 4;
		// 	sleep(4);
		// }
		if (elem.score_a > 0 && \
			elem.score_b > 0)
		{
			if (try_double_rotation(stack_a, stack_b, &elem))
			{
				// printf("lil nax X\n");
				elem.score_b--;
				elem.score_a--;
				elem.score -= 2;
				continue ;
				sleep(0);
			}
		}
		if (elem.score_a > 0)
		{
			// if (sleep_time > 0)
			// 	printf("Single a rotations\n");
			single_a_rotation(stack_a, &elem);
			// sleep(sleep_time);
		}
		if (elem.score_b > 0)
		{
			// if (sleep_time > 0)
			// 	printf("single b rotations\n");
			single_b_rotation(stack_b, &elem);
			// printf("B scores: %lli\n", elem->score_b);
			// printf("A scores: %lli\n", elem->score_a);
			// sleep(sleep_time);
		}
	}
	stack_pa(stack_b, stack_a);
}
