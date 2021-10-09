#include <stdio.h>
#include "../src/push_swap.h"

t_stack *create_stack()
{
	t_stack *stack = malloc(sizeof(t_stack));
	int arr_length = 10;

	stack->array = malloc(sizeof(int) * arr_length);
	stack->length = arr_length;
	stack->top_index = arr_length - 1;

	stack->array[0] = 0;
	stack->array[1] = 1;
	stack->array[2] = 2;
	stack->array[3] = 3;
	stack->array[4] = 4;
	stack->array[5] = 5;
	stack->array[6] = 6;
	stack->array[7] = 7;
	stack->array[8] = 8;
	stack->array[9] = 9;
	stack->head = 9;
	return stack;
}

int unit_test_rb()
{
	//Arrange
	t_stack *stack = create_stack();
	t_stack *old_stack = create_stack();

	//Act
	printf("\n");
	printf("testing ");
	stack_rb(stack);
	printf("\n");

	//Assert
	printf("%i\n", old_stack->array[9] == stack->array[0]);
	printf("%i\n", old_stack->array[0] == stack->array[1]);
	printf("%i\n", old_stack->array[1] == stack->array[2]);
	printf("%i\n", old_stack->array[2] == stack->array[3]);
	printf("%i\n", old_stack->array[3] == stack->array[4]);
	printf("%i\n", old_stack->array[4] == stack->array[5]);
	printf("%i\n", old_stack->array[5] == stack->array[6]);
	printf("%i\n", old_stack->array[6] == stack->array[7]);
	printf("%i\n", old_stack->array[7] == stack->array[8]);
	printf("%i\n", old_stack->array[8] == stack->array[9]);
	printf("%i\n", old_stack->head == stack->array[0]);
	printf("%i\n", old_stack->array[8] == stack->head);
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
	printf("%i\n", stack->array[stack->top_index] == old_stack->array[old_stack->top_index - 1]);
	printf("%i\n", stack->head == old_stack->array[old_stack->top_index - 1]);
	printf("%i\n", stack->array[stack->top_index - 1] == old_stack->array[old_stack->top_index]);
	printf("%i\n", stack->array[stack->top_index - 1] == old_stack->head);
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
	printf("%i\n", old_stack->array[0] == stack->array[9]);
	printf("%i\n", old_stack->array[0] == stack->head);
	printf("%i\n", old_stack->array[9] == stack->array[8]);
	printf("%i\n", old_stack->head == stack->array[8]);
	printf("%i\n", old_stack->array[8] == stack->array[7]);
	printf("%i\n", old_stack->array[7] == stack->array[6]);
	printf("%i\n", old_stack->array[6] == stack->array[5]);
	printf("%i\n", old_stack->array[5] == stack->array[4]);
	printf("%i\n", old_stack->array[4] == stack->array[3]);
	printf("%i\n", old_stack->array[3] == stack->array[2]);
	printf("%i\n", old_stack->array[2] == stack->array[1]);
	printf("%i\n", old_stack->array[1] == stack->array[0]);
}

int unit_test_pb()
{
	//Arrange
	t_stack *old_stack_a = create_stack();
	t_stack *stack_a = create_stack();
	t_stack *old_stack_b = create_stack();
	t_stack *stack_b = create_stack();

	stack_b->array[stack_b->top_index] = 0;
	stack_b->top_index--;
	old_stack_b->array[old_stack_b->top_index] = 0;
	old_stack_b->top_index--;

	//Act
	printf("\n");
	printf("testing ");
	stack_pb(stack_a, stack_b);
	printf("\n");

	//Assert
	printf("%i\n", stack_a->top_index == old_stack_a->top_index - 1);
	printf("%i\n", stack_a->array[stack_a->top_index] == old_stack_a->array[old_stack_a->top_index - 1]);
	printf("%i\n", stack_a->head == old_stack_a->array[old_stack_a->top_index - 1]);
	printf("%i\n", stack_b->array[stack_b->top_index] == old_stack_a->array[old_stack_a->top_index]);
	printf("%i\n", stack_b->head == old_stack_a->array[old_stack_a->top_index]);
	printf("%i\n", stack_b->top_index == old_stack_b->top_index + 1);
}

int main(void)
{
	unit_test_sb();
	unit_test_pb();
	unit_test_rb();
	unit_test_rrb();
}
