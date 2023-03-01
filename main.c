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

void	print_stack(t_stack *stack, int size)
{
	int	i;

	i = 0;
	printf("\n\n");
	while (i < size)
	{
		printf("%d:	%d		(prev: %d, next: %d)\n", i + 1, stack->nb, stack->prev->nb, stack->next->nb);
		stack = stack->next;
		i++;
	}
}

t_stack	*init_stack(int *nbs, int size)
{
	int	i;
	t_stack	*a;
	t_stack	*temp;
	t_stack	*temp_prev;
	//t_stack	*b;

	temp = (t_stack *)malloc(sizeof(t_stack));
	// if !malloc
	temp->nb = nbs[0];
	temp->next = temp;
	temp->prev = temp;
	a = temp;
	temp_prev = temp;
	i = 1;
	while (i < size)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		// if !malloc
		temp->nb = nbs[i];
		//temp->next = NULL;
		temp->prev = temp_prev;
		temp_prev->next = temp;
		temp_prev = temp;
		i++;
	}
	temp->next = a;
	a->prev = temp;
	return (a);
}

void	swap(t_stack **stack)
{
	// swap the first two elements of the stack
	t_stack	*head;
	t_stack	*el1;
	t_stack	*el2;
	t_stack	*temp;

	head = *stack;
	el1 = head;
	el2 = head->next;
	temp = el2->next;
	el1->prev->next = el2;
	el2->prev = el1->prev;
	el2->next->prev = el1;
	el2->next = el1;
	el1->prev =  el2;
	el1->next = temp;
	*stack = el2;
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rotate(t_stack **stack)
{
	// first element becomes last
	*stack = (*stack)->next;
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	r_rotate(t_stack **stack)
{
	// last element becomes first
	*stack = (*stack)->prev;
}

void	r_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	// pa: take first of stack_b and push to stack_a
	// what if b empty
	t_stack	*temp;
	t_stack	*head_a;

	if (!(*stack_a))
	{
		temp = *stack_b;
		(*stack_b) = temp->next;
		(*stack_b)->prev = temp->prev;
		temp->prev->next = *stack_b;

		(*stack_a) = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp = *stack_b;
		(*stack_b) = temp->next;
		(*stack_b)->prev = temp->prev;
		temp->prev->next = *stack_b;

		head_a = *stack_a;
		*stack_a = temp;
		temp->prev = head_a->prev;
		temp->next = head_a;
		head_a->prev = temp;
		temp->prev->next = temp;
	}
}

void	tests(int *nbs, int size)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = init_stack(nbs, size);
	print_stack(a, size);
	
	/*swap(&a);
	print_stack(a, size);
	rotate(&a);
	print_stack(a, size);
	r_rotate(&a);
	print_stack(a, size);*/

	push(&b, &a);
	print_stack(a, 9);
	print_stack(b, 1);

	push(&b, &a);
	print_stack(a, 8);
	print_stack(b, 2);

	push(&b, &a);
	print_stack(a, 7);
	print_stack(b, 3);

	push(&b, &a);
	print_stack(a, 6);
	print_stack(b, 4);

	rotate(&b);
	print_stack(b, 4);

	printf("\n\nswap both\n");
	swap_both(&a, &b);
	print_stack(a, 6);
	print_stack(b, 4);

	printf("\n\nrotate both\n");
	rotate_both(&a, &b);
	print_stack(a, 6);
	print_stack(b, 4);

	printf("\n\nrev rotate both\n");
	r_rotate_both(&a, &b);
	print_stack(a, 6);
	print_stack(b, 4);

	push(&a, &b);
	print_stack(a, 7);
	print_stack(b, 3);

	// free a and b lolilol
}

int	main(void)
{
	printf("heyoooo %d\n", test10_1[1]);

	//system("leaks push_swap");


	tests(test10_1, 10);

}



/*

TODOS

- read subject lol OK 
- make a function to generate test sets?
- make a validator function OK 
- decide and code the structures OK
- implement the different ops OK
- code the bubble sort for *fun* purposes


*/