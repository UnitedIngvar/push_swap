/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:49:00 by hcrakeha          #+#    #+#             */
/*   Updated: 2021/10/16 19:02:02 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <inttypes.h>

/*Predifine section*/

//Boolean
typedef int	t_bool;
# define TRUE 1
# define FALSE 0

//Structure that encapsulates data regarding elements of stack
//Value - represents the numerical value
//Score - represents the number of rotations needed to put an element
//on its sorted position
//Score_a - number of rotations for stack A
//Score_b - number of rotations for satck B
//is_reversed_a / is_reversed_b - indicates if we should use reverse rotations
typedef struct s_scored
{
	int64_t	value;
	int64_t	score_a;
	int64_t	score_b;
	int64_t	score;
	t_bool	is_reversed_a;
	t_bool	is_reversed_b;
}	t_scored;

//Structure that represents data regarding stack
//length - represents the maximum number of elements that stack can accept.
//Can't be overwritten
//top_index - represents the index of the last element added to the stack.
//Also, indicates the head. -1 means empty stack
//head - value of the last element in the stack
//array - internal collection of values
typedef struct s_stack
{
	int64_t		length;
	int64_t		top_index;
	t_scored	head;
	t_scored	*array;
}	t_stack;

//If applied to top_index, indicates that the stack is empty
# define EMPTY -1

//*End of predifine section*/

/*Operations section */

//Functions responsible for operations on stakc B

void	stack_sb(t_stack *stack);
void	stack_pb(t_stack *stack_a, t_stack *stack_b);
void	stack_rb(t_stack *stack_b);
void	stack_rrb(t_stack *stack);

//Functions responsible for operations on stakc A

void	stack_sa(t_stack *stack);
void	stack_pa(t_stack *stack_b, t_stack *stack_a);
void	stack_ra(t_stack *stack);
void	stack_rra(t_stack *stack);

//Functions responsible for simultanious operations on both stacks

void	stack_ss(t_stack *stack_a, t_stack *stack_b);
void	stack_rr(t_stack *stack_a, t_stack *stack_b);
void	stack_rrr(t_stack *stack_a, t_stack *stack_b);

/*End of operation section */

void	print_stack(t_stack *stack, char *stack_str);
void	print_b_rotations(t_stack *stack);
void	print_a_rotations(t_stack *stack);
void	print_a_scores(t_stack *stack);
void	print_b_scores(t_stack *stack);
void	print_scores(t_stack *stack);
void	print_all(t_stack *stack_a, t_stack *stack_b);

/*Parser section*/

//Accepts an array of strings and processes it into an
//array of ints if every element pass the game rules.
//Returns NULL on error
int64_t	*parse_values(char **values, int64_t size);

/*End of parser section*/

//*Sort section */
//Function responsible for sorting stack A
int		sort_stack(t_stack *stack_a, t_stack *stack_b, int64_t length);

/*End of sort section */

/*Core section */

t_stack	*init_stack_a(int64_t *values, int64_t length);
t_stack	*init_stack_b(int64_t length);

/*End of core section */
#endif
