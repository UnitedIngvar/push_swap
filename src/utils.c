#include "push_swap.h"

t_bool	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' /
		c == '\r' || c == '\v' || c == '\f')
		return (TRUE);
	return (FALSE);
}

