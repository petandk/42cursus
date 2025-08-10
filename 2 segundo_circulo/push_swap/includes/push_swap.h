/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:30:39 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/08 21:00:04 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
	int				position;
	int				cost_a;
	int				cost_b;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

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
int		find_smallest(t_stack *stack);
void	process_args(int argc, char **argv);
int		is_sorted(t_stack *stack);
void	clean_stacks(t_stack **a, t_stack **b);
void	order_3(t_stack *stack);
void	order_4(t_stack *stack);
void	check_args(int args, char **argv);
void	find_b_targets(t_data *data);
void	find_a_targets(t_data *data);
void	get_position(t_stack *stack);
void	get_cost(t_data *data);
t_stack	*find_smallest_node(t_stack *stack);
t_stack	*find_cheapest(t_data *data);
void	turk_r_both(t_data *data, t_stack *cheapest);
void	turk_r_a(t_data *data, t_stack *cheapest);
void	turk_r_b(t_data *data, t_stack *cheapest);
void	turk_to_b(t_data *data, t_stack *cheapest);
void	turk_to_a(t_data *data);
void	turk(t_stack *stack);
void	final_sort(t_stack **a);
int		get_mid(int mid);
void	get_cost_returning(t_data *data);
int		total_cost(t_stack *node);
t_stack	*find_cheapest_back(t_data *data);

#endif
