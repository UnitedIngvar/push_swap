int main(void)
{
	t_stack	*stack_a = malloc(sizeof(t_stack));
	t_stack *stack_b = malloc(sizeof(t_stack));
	int		arr_length = 10;

	stack_b->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->length = arr_length;
	stack_b->length = arr_length;
	stack_a->top_index = arr_length - 1;
	stack_b->top_index = -1;

	stack_a->array[0].value = INT_MIN;
	stack_a->array[1].value = 6436;
	stack_a->array[2].value = -47;
	stack_a->array[3].value = 8;
	stack_a->array[4].value = 4;
	stack_a->array[5].value = INT_MAX;
	stack_a->array[6].value = 979;
	stack_a->array[7].value = 77;
	stack_a->array[8].value = 10;
	stack_a->array[9].value = 6447;
	stack_a->head = stack_a->array[9];
	push_to_b(stack_a, stack_b);
}
