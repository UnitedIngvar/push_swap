#include <unistd.h>
#include <stdlib.h>

typedef struct s_scored
{
	ssize_t value;
}	t_scored;

typedef struct s_stack
{
	ssize_t	length;
	ssize_t	head;
	ssize_t	top_index;
	ssize_t	*array;
}	t_stack;

void stack_sb(t_stack *stack);
void stack_pb(t_stack *stack_a, t_stack *stack_b);
void stack_rb(t_stack *stack_b);
void stack_rrb(t_stack *stack);

void stack_sa(t_stack *stack);
void stack_pa(t_stack *stack_b, t_stack *stack_a);
void stack_ra(t_stack *stack);
void stack_rra(t_stack *stack);

typedef int bool;
#define true 1
#define false 0
