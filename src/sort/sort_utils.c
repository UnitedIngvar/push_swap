/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:29 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 17:20:25 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int64_t	*copy_array(t_scored *arr, long len)
{
	int64_t	*new_arr;
	int		i;

	new_arr = safe_malloc(sizeof(*new_arr) * len);
	i = -1;
	while (++i < len)
		new_arr[i] = arr[i].value;
	return (new_arr);
}

int64_t	*get_sorted_array(t_scored *array, long len)
{
	int64_t	*sorted_array;

	sorted_array = copy_array(array, len);
	quick_sort(sorted_array, 0, len - 1);
	return (sorted_array);
}

t_bool	is_sorted(const t_stack *stack)
{
	int	i;

	i = stack->top_index;
	while (i > 0)
	{
		if (stack->array[i].value > stack->array[i - 1].value)
			return (FALSE);
		i--;
	}
	return (TRUE);
}

t_specs	find_special_values(const int64_t *sorted_array, int64_t len)
{
	t_specs	specs;

	specs.min = sorted_array[0];
	specs.max = sorted_array[len - 1];
	specs.mid = sorted_array[len / 2];
	return (specs);
}
