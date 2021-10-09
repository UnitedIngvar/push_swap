#include <stdio.h>
#include "../src/push_swap.h"

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


int unit_test_rb()
{
	//Arrange
	t_stack *stack = create_stack();
	t_stack *old_stack = create_stack();

	//Act
	printf("\n");
	write(1, "testing ", 8);
	stack_rb(stack);
	printf("\n");

	//Assert
	printf("%i\n", old_stack->array[9].value == stack->array[0].value);
	printf("%i\n", old_stack->array[0].value == stack->array[1].value);
	printf("%i\n", old_stack->array[1].value == stack->array[2].value);
	printf("%i\n", old_stack->array[2].value == stack->array[3].value);
	printf("%i\n", old_stack->array[3].value == stack->array[4].value);
	printf("%i\n", old_stack->array[4].value == stack->array[5].value);
	printf("%i\n", old_stack->array[5].value == stack->array[6].value);
	printf("%i\n", old_stack->array[6].value == stack->array[7].value);
	printf("%i\n", old_stack->array[7].value == stack->array[8].value);
	printf("%i\n", old_stack->array[8].value == stack->array[9].value);
	printf("%i\n", old_stack->head.value == stack->array[0].value);
	printf("%i\n", old_stack->array[8].value == stack->head.value);
}

int unit_test_sb()
{
	//Arrange
	t_stack *stack = create_stack();
	t_stack *old_stack = create_stack();

	//Act
	printf("\n");
	printf("testing ");
	stack_sb(stack);
	printf("\n");

	//Assert
	printf("%i\n", stack->array[stack->top_index].value == old_stack->array[old_stack->top_index - 1].value);
	printf("%i\n", stack->head.value == old_stack->array[old_stack->top_index - 1].value);
	printf("%i\n", stack->array[stack->top_index - 1].value == old_stack->array[old_stack->top_index].value);
	printf("%i\n", stack->array[stack->top_index - 1].value == old_stack->head.value);
}

int unit_test_rrb()
{
	//Arrange
	t_stack *stack = create_stack();
	t_stack *old_stack = create_stack();

	//Act
	printf("\n");
	printf("testing ");
	stack_rrb(stack);
	printf("\n");

	//Assert
	printf("%i\n", old_stack->array[0].value == stack->array[9].value);
	printf("%i\n", old_stack->array[9].value == stack->array[8].value);
	printf("%i\n", old_stack->array[8].value == stack->array[7].value);
	printf("%i\n", old_stack->array[7].value == stack->array[6].value);
	printf("%i\n", old_stack->array[6].value == stack->array[5].value);
	printf("%i\n", old_stack->array[5].value == stack->array[4].value);
	printf("%i\n", old_stack->array[4].value == stack->array[3].value);
	printf("%i\n", old_stack->array[3].value == stack->array[2].value);
	printf("%i\n", old_stack->array[2].value == stack->array[1].value);
	printf("%i\n", old_stack->array[1].value == stack->array[0].value);
	printf("%i\n", old_stack->array[0].value == stack->head.value);
	printf("%i\n", old_stack->head.value == stack->array[8].value);
}

int unit_test_pb()
{
	//Arrange
	t_stack *old_stack_a = create_stack();
	t_stack *stack_a = create_stack();
	t_stack *old_stack_b = create_stack();
	t_stack *stack_b = create_stack();

	stack_b->array[stack_b->top_index].value = 0;
	stack_b->top_index--;
	old_stack_b->array[old_stack_b->top_index].value = 0;
	old_stack_b->top_index--;

	//Act
	printf("\n");
	printf("testing ");
	stack_pb(stack_a, stack_b);
	printf("\n");

	//Assert
	printf("%i\n", stack_a->top_index == old_stack_a->top_index - 1);
	printf("%i\n", stack_a->array[stack_a->top_index].value == old_stack_a->array[old_stack_a->top_index - 1].value);
	printf("%i\n", stack_a->head.value == old_stack_a->array[old_stack_a->top_index - 1].value);
	printf("%i\n", stack_b->array[stack_b->top_index].value == old_stack_a->array[old_stack_a->top_index].value);
	printf("%i\n", stack_b->head.value == old_stack_a->head.value);
	printf("%i\n", stack_b->top_index == old_stack_b->top_index + 1);
}

void	value_change(t_stack *stack, ssize_t value, int index)
{
	stack->array[index].value = value;
}

unit_test_value_change()
{
	//Arrange
	t_stack	*stack = create_stack();
	ssize_t	value = 10;
	int		index = 5;

	//Act
	printf("\ntesting value change: \n");
	value_change(stack, value, index);
	printf("%i\n", stack->array[index].value == value);
	value = 6;
	index = 8;
	value_change(stack, value, index);
	printf("%i\n", stack->array[index].value == value);
}

int	main(void)
{
	unit_test_sb();
	unit_test_pb();
	unit_test_rb();
	unit_test_rrb();
	unit_test_value_change();
}
