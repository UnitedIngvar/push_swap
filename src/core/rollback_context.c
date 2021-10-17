/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rollback_context.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 22:49:04 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 11:42:11 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rollback_context.h"
#include <unistd.h>
#include <stdio.h>

static void	execute_rollback_internal(t_rollback_context **context)
{
	t_rollback_context	*temp;

	temp = *context;
	while (temp->enl_index > EMPTY)
	{
		free(temp->entity_array[temp->enl_index]);
		temp->entity_array[temp->enl_index] = NULL;
		temp->enl_index--;
	}
	free(temp);
	temp = NULL;
}

static void	action_on_rollback(enum e_rollback_action action, void *data)
{
	static t_rollback_context	*context;

	if (action == act_init)
	{
		context = malloc(sizeof(*context));
		context->entity_array = malloc(sizeof(void *) * ROLLBACK_CONTEXT_SIZE);
		context->enl_index = EMPTY;
	}
	else if (action == act_push)
	{
		context->enl_index++;
		context->entity_array[context->enl_index] = data;
	}
	else if (action == act_rollback)
		execute_rollback_internal(&context);
}

void	init_rollback_context(void)
{
	action_on_rollback(act_init, NULL);
}

void	push_to_rollback_context(void *entity)
{
	action_on_rollback(act_push, entity);
}

void	execute_rollback(void)
{
	action_on_rollback(act_rollback, NULL);
}
