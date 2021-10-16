#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <inttypes.h>

typedef int	t_bool;
# define TRUE 1
# define FALSE 0

typedef struct s_scored
{
	int64_t	value;
	int64_t	score_a;
	int64_t	score_b;
	int64_t	score;
	t_bool	is_reversed_a;
	t_bool	is_reversed_b;
}	t_scored;

typedef struct s_stack
{
	int64_t		length;
	int64_t		top_index;
	t_scored	head;
	t_scored	*array;
}	t_stack;

# define EMPTY_STACK_INDEX -1

void	stack_sb(t_stack *stack);
void	stack_pb(t_stack *stack_a, t_stack *stack_b);
void	stack_rb(t_stack *stack_b);
void	stack_rrb(t_stack *stack);

void	stack_sa(t_stack *stack);
void	stack_pa(t_stack *stack_b, t_stack *stack_a);
void	stack_ra(t_stack *stack);
void	stack_rra(t_stack *stack);

void	stack_ss(t_stack *stack_a, t_stack *stack_b);
void	stack_rr(t_stack *stack_a, t_stack *stack_b);
void	stack_rrr(t_stack *stack_a, t_stack *stack_b);

//int		sort_stack(t_stack *stack_a, t_stack *stack_b, int64_t length);
void	print_stack(t_stack *stack, char *stack_str);
void	print_b_rotations(t_stack *stack);
void	print_a_rotations(t_stack *stack);
void	print_a_scores(t_stack *stack);
void	print_b_scores(t_stack *stack);
void	print_scores(t_stack *stack);
void	print_all(t_stack *stack_a, t_stack *stack_b);

char	**ft_split(char const *s, char c);
int64_t	*parse_values(char **values, int64_t counter);
t_bool	is_space(char c);


#endif
