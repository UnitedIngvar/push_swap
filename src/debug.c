#include "push_swap.h"

void	print_stack(t_stack *stack, char *stack_str)
{
	int	i;

	printf("%s\n", stack_str);
	printf("\ntop index - %lld\n", stack->top_index);
	printf("%s", stack_str);
	i = stack->top_index;
	while (i >= 0)
	{
		printf("%lli	", stack->array[i--].value);
	}
	printf("\n");
}

void	print_scores(t_stack *stack)
{
	int	i;

	printf("Scores:			");
	i = stack->top_index;
	while (i >= 0)
	{
		printf("%lli	", stack->array[i--].score);
	}
	printf("\n");
}

void	print_b_scores(t_stack *stack)
{
	int	i;

	printf("B scores:		");
	i = stack->top_index;
	while (i >= 0)
	{
		printf("%lli	", stack->array[i--].score_b);
	}
	printf("\n");
}

void	print_a_scores(t_stack *stack)
{
	int	i;

	printf("A scores:		");
	i = stack->top_index;
	while (i >= 0)
	{
		printf("%lli	", stack->array[i--].score_a);
	}
	printf("\n");
}

void	print_a_rotations(t_stack *stack)
{
	int	i;

	printf("A rotations:		");
	i = stack->top_index;
	while (i >= 0)
	{
		if (!stack->array[i--].is_reversed_a)
			printf("s	");
		else
			printf("r	");
	}
	printf("\n");
}

void	print_b_rotations(t_stack *stack)
{
	int	i;

	printf("B rotations:		");
	i = stack->top_index;
	while (i >= 0)
	{
		if (!stack->array[i--].is_reversed_b)
			printf("s	");
		else
			printf("r	");
	}
	printf("\n");
}

void	print_all(t_stack *stack_a, t_stack *stack_b)
{
	print_stack(stack_a, "stack A:		");
	print_stack(stack_b, "stack B:		");
	print_scores(stack_b);
	print_b_scores(stack_b);
	print_b_rotations(stack_b);
	print_a_scores(stack_b);
	print_a_rotations(stack_b);
	usleep(100000);
}
