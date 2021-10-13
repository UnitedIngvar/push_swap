#ifndef SORT_H
# define SORT_H

# include "../push_swap.h"

typedef struct s_specs
{
	int64_t	min;
	int64_t	max;
	int64_t	mid;
}	t_specs;

t_bool		is_sorted(const t_stack *stack);
void		sort_array(int64_t array);
void		quick_sort(int64_t *arr, int low, int high);
int64_t		*get_sorted_array(t_scored *array, long len);
t_specs		find_special_values(const int64_t *sorted_array, int64_t len);

void		assign_scores(t_stack *stack_a, t_stack *stack_b);
void		clear_scores(t_stack *stack_a, t_stack *stack_b);

int			full_sort(t_stack *stack_a, t_stack *stack_b);
int			mini_sort(t_stack *stack_a, t_stack *stack_b);

int			push_rotate(t_stack *stack_a, t_stack *stack_b, int64_t fstst_i);

# define MINISORT_MAX_STACK_SIZE 5

#endif
