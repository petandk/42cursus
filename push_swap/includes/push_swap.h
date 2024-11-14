/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:30:39 by rmanzana          #+#    #+#             */
/*   Updated: 2024/11/14 17:25:18 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	//int				cost;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_lstnewnode(int value);
t_stack	*ft_lstlastnode(t_stack *lst);
t_stack	*ft_lstfirstnode(t_stack *lst);
void	ft_lstadd_backnode(t_stack **lst, t_stack *new);
int		ft_countnodes(t_stack *lst);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	free_stack(t_stack *stack);
t_stack	*find_biggest(t_stack *stack);
void	process_args(int argc, char **argv);
int		is_sorted(t_stack *stack);
void	order_3(t_stack *stack);
void	order_4(t_stack *stack);
void	check_args(int args, char **argv);
//void	turk(t_stack *stack);
void	print_lists(t_stack *a, t_stack *b);
void	print_single(t_stack *stack);
#endif
