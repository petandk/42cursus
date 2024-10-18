/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:30:39 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/14 19:55:41 by rmanzana         ###   ########.fr       */
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
void	ft_swap(t_stack **lst);
void	ft_swap_both(t_stack **a, t_stack **b);
void	ft_rotate(t_stack **lst);
void	ft_rotate_both(t_stack **a, t_stack **b);
void	ft_reverse(t_stack **lst);
void	ft_reverse_both(t_stack **a, t_stack **b);
void	ft_push(t_stack **src, t_stack **dest);
int		*divide_string(const char *input);
int		*get_numbers(char *argv[], int argc);
int		check_repeated(int *numbers, int argc);

#endif
