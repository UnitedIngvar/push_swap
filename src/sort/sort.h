#ifndef SORT_H
# define SORT_H

# include "../push_swap.h"

typedef struct s_specs
{
	ssize_t	min;
	ssize_t	max;
	ssize_t	mid;
}	t_specs;

t_bool	is_sorted(const t_stack *stack);
void	sort_array(ssize_t array);
void	quick_sort(ssize_t *arr, int low, int high);
ssize_t	*get_sorted_array(t_scored *array, long len);
t_specs	find_special_values(const ssize_t *sorted_array, ssize_t len);
void	assign_scores(t_stack *stack_a, t_stack *stack_b);
void	clear_scores(t_stack *stack_a, t_stack *stack_b);

#endif
