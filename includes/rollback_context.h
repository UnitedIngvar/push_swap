/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rollback_context.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:03:58 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 01:41:21 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROLLBACK_CONTEXT_H
# define ROLLBACK_CONTEXT_H
# include <inttypes.h>
# include <stdlib.h>

typedef struct s_rollback_context
{
	void	**entity_array;
	int64_t	enl_index;
}	t_rollback_context;

enum e_rollback_action
{
	act_init = 0,
	act_push = 1,
	act_rollback = 2
};

# define ROLLBACK_CONTEXT_SIZE 50

# ifndef EMMPTY
#  define EMPTY -1
# endif

//Frees and sets all the pointers to NULL
void	execute_rollback(void);

//Push a pointer to allocated memory section into the context
void	push_to_rollback_context(void *entity);

//Initialize rollback context
void	init_rollback_context(void);

#endif
