#include "push_swap.h"
#include "test_sets.h"

int	in_order(int *nbs, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (nbs[i - 1] >= nbs[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("heyoooo %d\n", test10_1[1]);

	//system("leaks push_swap");

}



/*
TODOS

- read subject lol OK 
- make a function to generate test sets?
- make a validator function OK 
- decide and code the structures
- implement the different ops
- code the bubble sort for *fun* purposes


*/