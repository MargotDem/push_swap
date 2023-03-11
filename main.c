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

int	stack_in_order(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	stack = stack->next;
	while (stack != head)
	{
		if (stack->prev->nb >= stack->nb)
			return (0);
		stack = stack->next;
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

void	print_stack2(t_stack *stack)
{
	t_stack	*head;
	int		i;

	i = 1;
	head = stack;
	printf("\n\n");
	printf("%d:	%d		(prev: %d, next: %d)\n", i, stack->nb, stack->prev->nb, stack->next->nb);
	stack = stack->next;
	while (stack != head)
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


	printf("\n\nnew printing fonction\n");
	print_stack2(a);
	print_stack2(b);

	// free a and b lolilol
}

void	tests_inorder(int *nbs, int size)
{
	t_stack	*a;

	a = init_stack(nbs, size);
	if (stack_in_order(a))
		printf("\nyes in order\n");
	else
		printf("\nnot in order\n");
}

/*void	bbl_sort(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	stack = stack->next;
	while (stack != head)
	{
		stack = stack->next;
	}
	
}*/

void	bbl_sort(t_stack **stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if ((*stack)->nb > (*stack)->next->nb)
			swap(stack);
		rotate(stack);
		i++;
	}
	rotate(stack);
}

void	test_bbl_sort(int *nbs, int size)
{
	t_stack	*a;
	int	i = 0;

	a = init_stack(nbs, size);
	print_stack2(a);
	while(!stack_in_order(a))
	{
		bbl_sort(&a, size);
		i++;
	}
	print_stack2(a);
	printf("\n\n bbl sort took %d moves\n\n", i);
}

void	go_through(t_stack **stack_1, t_stack **stack_2, int flip)
{
	t_stack	*a;
	t_stack	*head;

	a = *stack_1;
	head = a;
	a = a->next;
	while (a != head)
	{
		if (flip % 2)
		{
			if (a->nb > (*stack_2)->nb)
				push(stack_2, &a);
		}
		else
		{
			if (a->nb < (*stack_2)->nb)
				push(stack_2, &a);
		}
		a = a->next;
	}
}

void	test_bad_algo(int *nbs, int size)
{
	t_stack	*a;
	t_stack	*b;
	int	i;
	i = 0;

	b = NULL;
	a = init_stack(nbs, size);
	
	
	push(&b, &a);
	
	
	/*print_stack2(b);
	push(&b, &a);
	push(&b, &a);

	print_stack2(b);
*/


	print_stack2(b);
	while(i < 20)
	{
		go_through(&a, &b, i);
		i++;
	}
	printf("\ntadaaaaa (i is %d)\n", i);
	//print_stack2(a);
	print_stack2(b);
}

int	main(void)
{

	//system("leaks push_swap");


	//tests(test10_1, 10);
	
	//tests_inorder(test10_1, 10);

	//test_bbl_sort(test500_3, 500);

	test_bad_algo(test30_1 , 30);


}

/*

TODOS

- read subject lol OK 
- make a function to generate test sets? // make own
- make a validator function OK 
- decide and code the structures OK
- implement the different ops OK
- code the bubble sort for *fun* purposes OK

mkayy so c quoi les bails donc

parcourir a
mettre le premier de a sur b
puis le 2e, check si asc or des
ensuite parcourir a
mettre le 






*/