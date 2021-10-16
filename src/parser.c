#include "push_swap.h"
static

int parse_values(char **values, int64_t size)
{
	int64_t	*value_matrix;
	int64_t	count;

	value_matrix = malloc(sizeof(int64_t*));
	count = 0;
	while (count < size)
	{
		value_matrix[count] = ft_atoi(values[count]);
		count++;
	}
}
