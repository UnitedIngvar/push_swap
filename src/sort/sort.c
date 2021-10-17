/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:32 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 17:53:55 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	sort_stack(t_stack *stack_a, t_stack *stack_b, int64_t length)
{
	if (is_sorted(stack_a))
		return (1);
	if (length <= MINISORT_MAX_STACK_SIZE)
		return (mini_sort(stack_a, stack_b));
	else
		return (full_sort(stack_a, stack_b));
}
