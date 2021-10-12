#include "unit_tests.h"

static void	value_change(t_stack *stack, int64_t value, int index)
{
	stack->array[index].value = value;
}

static void unit_test_value_change()
{
	//Arrange
	t_stack	*stack = create_stack();
	int64_t	value = 10;
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

int main(void)
{
	unit_test_value_change();
}
