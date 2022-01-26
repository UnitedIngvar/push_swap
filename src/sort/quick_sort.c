/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:17 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 15:35:10 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	swap(int64_t *a, int64_t *b)
{
	int64_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int64_t *arr, int64_t low, int64_t high)
{
	int64_t	pivot;
	int		i;

	pivot = arr[high];
	i = (low - 1);
	while (low <= high - 1)
	{
		if (arr[low] < pivot)
		{
			i++;
			swap(&arr[i], &arr[low]);
		}
		low++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int64_t *arr, int low, int high)
{
	int64_t	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}
