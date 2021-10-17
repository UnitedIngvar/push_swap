/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rollback_context.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 22:49:04 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 02:57:16 by hcrakeha         ###   ########.fr       */
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
		printf("index %lld \n", temp->enl_index);
		//write(1, "rolling back\n", 13);
		//printf("delisting: %p\n", temp->entity_array[temp->enl_index]);
		//sleep(1);
		free(temp->entity_array[temp->enl_index]);
		temp->entity_array[temp->enl_index] = NULL;
		temp->enl_index--;
		write(1, "after back\n", 12);
	}
	write(1, "free rollback\n", 14);
	free(temp);
	temp = NULL;
}

static void	action_on_rollback(enum e_rollback_action action, void *data)
{
	static t_rollback_context	*context;

	if (action == act_init)
	{
		printf("initing\n");
		context = malloc(sizeof(*context));
		context->entity_array = malloc(sizeof(void *) * ROLLBACK_CONTEXT_SIZE);
		context->enl_index = EMPTY;
		printf("index %lld\n", context->enl_index);
	}
	else if (action == act_push)
	{
		printf("enlisting: %p\n", data);
		printf("index before %lld\n", context->enl_index);
		context->enl_index++;
		context->entity_array[context->enl_index] = data;
		printf("index after %lld\n", context->enl_index);
		//sleep(1);
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
