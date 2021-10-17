/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:46:20 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 02:16:29 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*safe_malloc(size_t size)
{
	void	*malloced;

	printf("Safe malloc\n");
	malloced = malloc(size);
	if (malloced == NULL)
		finish_program(FALSE);
	push_to_rollback_context(malloced);
	return (malloced);
}
