#include "unit_tests.h"

t_stack *create_stack()
{
	t_stack	*stack = malloc(sizeof(t_stack));
	int		arr_length = 10;

	stack->array = malloc(sizeof(t_scored) * arr_length);
	stack->length = arr_length;
	stack->top_index = arr_length - 1;

	stack->array[0].value = 0;
	stack->array[1].value = 1;
	stack->array[2].value = 2;
	stack->array[3].value = 3;
	stack->array[4].value = 4;
	stack->array[5].value = 5;
	stack->array[6].value = 6;
	stack->array[7].value = 7;
	stack->array[8].value = 8;
	stack->array[9].value = 9;
	stack->head.value = 9;
	return (stack);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top_index;
	while (i >= 0)
	{
		printf("%zi	", stack->array[i--].value);
	}
	printf("\n");
	sleep(2);
}
