#include "unit_tests.h"
#include "../src/sort/sort.h"
#include <stdio.h>

void	print_stack(t_stack *stack, char *stack_str)
{
	int	i;

	printf(stack_str);
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

	printf("Scores:			");
	i = stack->top_index;
	while (i >= 0)
	{
		printf("%zi	", stack->array[i--].score);
	}
	printf("\n");
}

void	print_b_scores(t_stack *stack, char *str)
{
	int	i;

	printf("B scores:		");
	i = stack->top_index;
	while (i >= 0)
	{
		printf("%zi	", stack->array[i--].score_b);
	}
	printf("\n");
}

void	print_a_scores(t_stack *stack, char *str)
{
	int	i;

	printf("A scores:		");
	i = stack->top_index;
	while (i >= 0)
	{
		printf("%zi	", stack->array[i--].score_a);
	}
	printf("\n");
}

void	print_a_rotations(t_stack *stack, char *str)
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

void	print_array(int64_t array, int64_t length)
{
	int	i;

	printf("Scores:		");
	i = length;
	while (i >= 0)
	{
		printf("%zi	", length);
	}
	printf("\n");
}


void unit_test_scores_acami_advanced()
{
	t_stack	*stack_a = malloc(sizeof(t_stack));
	t_stack *stack_b = malloc(sizeof(t_stack));
	int		arr_length = 9;

	stack_b->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->length = arr_length;
	stack_b->length = arr_length;
	stack_a->top_index = 3;
	stack_b->top_index = 4;

	stack_a->array[0].value = 1;
	stack_a->array[1].value = 9;
	stack_a->array[2].value = 3;
	stack_a->array[3].value = 2;
	stack_a->head = stack_a->array[3];

	stack_b->array[0].value = 4;
	stack_b->array[1].value = 6;
	stack_b->array[2].value = 7;
	stack_b->array[3].value = 8;
	stack_b->array[4].value = 5;
	stack_b->head = stack_b->array[4];

	printf("	__________SCORES___ACAMI_ADV________");
	printf("\n\n");
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


void unit_test_scores_acami()
{
	t_stack	*stack_a = malloc(sizeof(t_stack));
	t_stack *stack_b = malloc(sizeof(t_stack));
	int		arr_length = 9;

	stack_b->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->length = arr_length;
	stack_b->length = arr_length;
	stack_a->top_index = 1;
	stack_b->top_index = 6;

	stack_a->array[0].value = 9;
	stack_a->array[1].value = 1;
	stack_a->head = stack_a->array[1];

	stack_b->array[0].value = 6;
	stack_b->array[1].value = 7;
	stack_b->array[2].value = 8;
	stack_b->array[3].value = 5;
	stack_b->array[4].value = 2;
	stack_b->array[5].value = 4;
	stack_b->array[6].value = 3;
	stack_b->head = stack_b->array[6];

	int64_t index = stack_a->top_index;

	printf("	__________SCORES___ACAMI_________");
	printf("\n\n");
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

void unit_test_scores_many()
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

	printf("	__________SCORES___MANY__________");
	printf("\n\n");
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

void unit_test_scores_six()
{
	t_stack	*stack_a = malloc(sizeof(t_stack));
	t_stack *stack_b = malloc(sizeof(t_stack));
	int		arr_length = 6;

	stack_b->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->length = arr_length;
	stack_b->length = arr_length;
	stack_a->top_index = 1;
	stack_b->top_index = 3;

	stack_a->array[0].value = 475755858;
	stack_a->array[1].value = -8585859;
	stack_a->head = stack_a->array[1];

	stack_b->array[0].value = 6436;
	stack_b->array[1].value = 979;
	stack_b->array[2].value = 6447;
	stack_b->array[3].value = 10;
	stack_b->head = stack_b->array[3];

	printf("	__________SCORES___SIX___________");
	printf("\n\n");
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

int main(void)
{
	printf("********************************TESTING SCORES*********************************************");
	printf("\n\n");
	unit_test_scores_many();
	printf("\n\n");
	unit_test_scores_acami();
	printf("\n\n");
	unit_test_scores_six();
	printf("\n\n");
	unit_test_scores_acami_advanced();
}
