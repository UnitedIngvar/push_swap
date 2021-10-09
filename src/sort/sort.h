#include "../push_swap.h"

typedef struct s_specs
{
	ssize_t min;
	ssize_t max;
	ssize_t mid;
}	t_specs;

bool is_sorted(t_stack *stack);
void sort_array(ssize_t array);
void quick_sort(ssize_t *arr, int low, int high);
ssize_t *get_sorted_array(ssize_t *array, long len);
