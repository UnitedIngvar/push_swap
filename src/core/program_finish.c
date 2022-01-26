/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_finish.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:16:21 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 18:18:39 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish_on_error(void)
{
	execute_rollback();
	write(1, "Error\n", 6);
	exit(-1);
}

static void	finish_on_succes(void)
{
	execute_rollback();
	exit(0);
}

void	finish_program(t_bool success)
{
	if (success)
		finish_on_succes();
	else
		finish_on_error();
}
