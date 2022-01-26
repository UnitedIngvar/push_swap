/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rollback_context.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 22:49:04 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 17:19:50 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rollback_context.h"

static void	execute_rollback_internal(t_rollback_context **context)
{
	t_rollback_context	*temp;

	temp = *context;
	while (temp->enl_index > EMPTY)
	{
		free(temp->pointer_array[temp->enl_index]);
		temp->pointer_array[temp->enl_index] = NULL;
		temp->enl_index--;
	}
	free(temp->pointer_array);
	temp->pointer_array = NULL;
	free(temp);
	temp = NULL;
}

static void	action_on_rollback(enum e_rollback_action action, void *data)
{
	static t_rollback_context	*context;

	if (action == act_init)
	{
		context = malloc(sizeof(*context));
		context->pointer_array = malloc(sizeof(void *) * ROLLBACK_CONTEXT_SIZE);
		context->enl_index = EMPTY;
	}
	else if (action == act_push)
	{
		context->enl_index++;
		context->pointer_array[context->enl_index] = data;
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
