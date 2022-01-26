/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:46:20 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 11:42:15 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*safe_malloc(size_t size)
{
	void	*malloced;

	malloced = malloc(size);
	if (malloced == NULL)
		finish_program(FALSE);
	push_to_rollback_context(malloced);
	return (malloced);
}
