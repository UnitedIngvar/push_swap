#include "sort.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top_index;
	while (i >= 0)
	{
		printf("%zi	", stack->array[i--].value);
	}
	printf("\n");
}

void	print_scores(t_stack *stack)
{
	int	i;

	i = stack->top_index;
	while (i >= 0)
	{
		printf("%zi	", stack->array[i--].score);
	}
	printf("\n");
}

void	print_b_scores(t_stack *stack)
{
	int	i;

	i = stack->top_index;
	while (i >= 0)
	{
		printf("%zi	", stack->array[i--].score_b);
	}
	printf("\n");
}

void	print_a_scores(t_stack *stack)
{
	int	i;

	i = stack->top_index;
	while (i >= 0)
	{
		printf("%zi	", stack->array[i--].score_a);
	}
	printf("\n");
}

void	print_a_rotations(t_stack *stack)
{
	int	i;

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

static void	add_a_score(t_stack *stack_a, t_scored *elem)
{
	ssize_t	index;
	ssize_t	score_add;

	score_add = 1;
	if (stack_a->head.value > elem->value && \
		stack_a->array[0].value < elem->value)
	{
		elem->is_reversed_a = FALSE;
		return ;
	}
	index = stack_a->top_index + 1;
	elem->is_reversed_a = FALSE;
	while (--index > 0)
	{
		elem->score_a += score_add;
		if (index == stack_a->top_index / 2)
		{
			score_add = -1;
			elem->is_reversed_a = TRUE;
			//continue is not needed?
		}
		if (stack_a->array[index].value < elem->value && \
			stack_a->array[index - 1].value > elem->value)
			return ;
	}
}

static void	add_b_score(t_stack *stack_b, ssize_t index, t_scored *elem)
{
	if (index >= stack_b->top_index / 2)
	{
		elem->is_reversed_b = FALSE;
		elem->score_b = stack_b->top_index - index;
	}
	else
	{
		elem->is_reversed_b = TRUE;
		elem->score_b = index + 1;
	}
}

void	assign_scores(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	el_index;

	el_index = stack_b->top_index;
	while (el_index >= 0)
	{
		add_a_score(stack_a, &(stack_b->array[el_index]));
		add_b_score(stack_b, el_index, &(stack_b->array[el_index]));
		stack_b->array[el_index].score = \
			stack_b->array[el_index].score_a + \
			stack_b->array[el_index].score_b;
		el_index--;
	}
}

int main(void)
{
	t_stack	*stack_a = malloc(sizeof(t_stack));
	t_stack *stack_b = malloc(sizeof(t_stack));
	int		arr_length = 10;

	stack_b->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->length = arr_length;
	stack_b->length = arr_length;
	stack_a->top_index = 1;
	stack_b->top_index = 7;

	stack_a->array[0].value = 2147483647;
	stack_a->array[1].value = -2147483648;
	stack_a->head = stack_a->array[1];

	stack_b->array[0].value = 6436;
	stack_b->array[1].value = 979;
	stack_b->array[2].value = 6447;
	stack_b->array[3].value = 10;
	stack_b->array[4].value = 77;
	stack_b->array[5].value = 4;
	stack_b->array[6].value = 8;
	stack_b->array[7].value = -47;
	stack_b->head = stack_b->array[7];

	ssize_t index = stack_a->top_index;

	assign_scores(stack_a, stack_b);
	printf("stack A:	");
	print_stack(stack_a);
	printf("stack B:	");
	print_stack(stack_b);
	printf("scores:		");
	print_scores(stack_b);
	printf("B scores:	");
	print_b_scores(stack_b);
	printf("is rev B:	");
	print_b_rotations(stack_b);
	printf("A scores:	");
	print_a_scores(stack_b);
	printf("is rev A:	");
	print_a_rotations(stack_b);
}
