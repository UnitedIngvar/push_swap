#include "../push_swap.h"

void stack_push(t_stack *stack_from, t_stack *stack_to)
{
	if (stack_from->top_index == -1 || stack_from->length == 0)
		return;
	stack_to->top_index++;
	stack_to->array[stack_to->top_index] = stack_from->array[stack_from->top_index];
	stack_from->top_index--;
}

void stack_swap(t_stack *stack)
{
	int temp;

	if (stack->top_index == -1 || stack->length == 0)
		return;
	temp = stack->array[stack->top_index];
	stack->array[stack->top_index] = stack->array[stack->top_index - 1];
	stack->array[stack->top_index - 1] = temp;
}

void stack_rotate(t_stack *stack_b)
{
	int i_count;
	int top_num;

	i_count = stack_b->top_index;
	top_num = stack_b->array[i_count];
	while (i_count > 0)
	{
		stack_b->array[i_count] = stack_b->array[i_count - 1];
		i_count--;
	}
	stack_b->array[0] = top_num;
}

void stack_rotate_reverse(t_stack *stack)
{
	int	i_count;
	int	bottom_num;

	if (stack->top_index <= 0 || stack->length == 0)
		return ;
	i_count = 0;
	bottom_num = stack->array[0];
	while (i_count < stack->top_index)
	{
		stack->array[i_count] = stack->array[i_count + 1];
		i_count++;
	}
	stack->array[stack->top_index] = bottom_num;
}
