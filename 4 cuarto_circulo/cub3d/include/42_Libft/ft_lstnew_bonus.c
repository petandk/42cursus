/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:56:56 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/28 12:03:07 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*int	main(int argc, char **argv)
{
	t_list	*node;

	if (argc != 2)
	{
		write (1, "Error", 5);
		return (0);
	}
	node = ft_lstnew(argv[1]);
	if (node)
	{
		printf("Contenido del nodo: %s\n", (char *)(node->content));
		free(node);
	}
	return (0);
}*/
