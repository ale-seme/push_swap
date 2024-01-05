#include "push_swap.h"

static void	ft_swap(t_list	**stack)
{
	t_list	*tp;

	if((*stack == NULL || (*stack)->next == NULL))
		return ;
	tp = *stack;
	*stack = (*stack)->next;
	tp->next = (*stack)->next;
	(*stack)->next = tp;
}

void	sa(t_list **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}
void	sb(t_list	**stack_b)
{
	ft_swap(stack_b);
	write (1, "sb\n", 3);
}
void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write (1, "ss\n", 3);
}
