/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:36 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/17 17:26:14 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

//Data structure that represents the values gotten from the pre-sorted array.
typedef struct s_specs
{
	int64_t	min;
	int64_t	max;
	int64_t	mid;
}	t_specs;

//Checks if internal collection of stack is sorted
t_bool		is_sorted(const t_stack *stack);

//Sorts an array of simple numerical values
void		sort_array(int64_t array);

//Quick sort implementation
void		quick_sort(int64_t *arr, int low, int high);

//Gets sorted array
int64_t		*get_sorted_array(t_scored *array, long len);

//Find min, max and med in sorted array
t_specs		find_special_values(const int64_t *sorted_array, int64_t len);

//Assigns scores to elems in stack B
void		assign_scores(t_stack *stack_a, t_stack *stack_b);

//Clears scores of elems in stack
void		clear_scores(t_stack *stack_a, t_stack *stack_b);

//Sort stack consisting of more than MINISORT_MAX_STACK_SIZE.
int			full_sort(t_stack *stack_a, t_stack *stack_b);

//Sort stack consisting of less than MINISORT_MAX_STACK_SIZE.
int			mini_sort(t_stack *stack_a, t_stack *stack_b);

//Rotates both stacks based on scores assigned to the element passed in
void		push_rotate(t_stack *stack_a, t_stack *stack_b, t_scored elem);

# define MINISORT_MAX_STACK_SIZE 5

#endif
