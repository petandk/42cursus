/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:30:39 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 21:27:49 by rmanzana         ###   ########.fr       */
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
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_move
{
	int	pos_a;
	int	pos_b;
	int	cost;
} t_move;

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
int	find_smallest(t_stack *stack);
void	process_args(int argc, char **argv);
int		is_sorted(t_stack *stack);
void	clean_stacks(t_stack **a, t_stack **b);
void	order_3(t_stack *stack);
void	order_4(t_stack *stack);
void	check_args(int args, char **argv);
void	turk(t_stack *stack);
#endif
