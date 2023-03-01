#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
// delete
# include <stdio.h>

typedef struct s_stack
{
	int		nb;
	struct s_stack *prev;
	struct s_stack *next;
}				t_stack;

#endif
