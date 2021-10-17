/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:50 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 02:56:50 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_bool	validate_input(char **input, int64_t size)
{
	int64_t	counter;
	int64_t	c_counter;

	counter = 0;
	while (counter < size)
	{
		c_counter = -1;
		if (input[counter][c_counter + 1] == '\0')
			return (FALSE);
		while (input[counter][++c_counter] != '\0')
		{
			if (ft_is_space(input[counter][c_counter]) || \
				input[counter][c_counter] == '+' || \
				input[counter][c_counter] == '-')
			{
				if (input[counter][c_counter + 1] == '\0')
					return (FALSE);
				continue ;
			}
			if (!(ft_is_digit(input[counter][c_counter])))
				return (FALSE);
		}
		counter++;
	}
	return (TRUE);
}

static t_bool	validate_result(int64_t *result, int64_t size)
{
	int64_t	counter;
	int64_t	d_counter;

	counter = 0;
	while (counter < size)
	{
		if (result[counter] > ELEM_MAX \
			|| result[counter] < ELEM_MIN)
			return (FALSE);
		d_counter = counter;
		while (++d_counter < size)
			if (result[counter] == result[d_counter])
				return (FALSE);
		counter++;
	}
	return (TRUE);
}

int64_t	*parse_values(char **values, int64_t size)
{
	int64_t	*value_matrix;
	int64_t	count;

	if (validate_input(values, size) == FALSE)
		finish_program(FALSE);
	value_matrix = safe_malloc(sizeof(*value_matrix) * size);
	count = 0;
	while (count < size)
	{
		value_matrix[count] = ft_validating_atoi(values[count]);
		count++;
	}
	if (validate_result(value_matrix, size) == FALSE)
		finish_program(FALSE);
	return (value_matrix);
}
