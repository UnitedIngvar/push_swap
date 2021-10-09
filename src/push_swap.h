#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_scored
{
	ssize_t	value;
	ssize_t	score;
}	t_scored;

typedef struct s_stack
{
	ssize_t		length;
	t_scored	head;
	ssize_t		top_index;
	t_scored	*array;
}	t_stack;

void	stack_sb(t_stack *stack);
void	stack_pb(t_stack *stack_a, t_stack *stack_b);
void	stack_rb(t_stack *stack_b);
void	stack_rrb(t_stack *stack);

void	stack_sa(t_stack *stack);
void	stack_pa(t_stack *stack_b, t_stack *stack_a);
void	stack_ra(t_stack *stack);
void	stack_rra(t_stack *stack);

typedef int	t_bool;
# define TRUE 1
# define FALSE 0

#endif
