/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_a_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:55:14 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/29 16:56:53 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack_a	*create_list_a(int ac, char **av)
{
	t_stack_a	*head_a;
	t_stack_a	*tmp;
	int			i;

	i = 1;
	head_a = ft_newnode_a(ft_atoi(av[i]));
	tmp = head_a;
	while (++i < ac)
	{
		tmp->next = ft_newnode_a(ft_atoi(av[i]));
		tmp = tmp->next;
	}
	return (head_a);
}

t_stack_a	*ft_newnode_a(int n)
{
	t_stack_a	*tmp;

	tmp = malloc(sizeof(t_stack_a));
	if (!tmp)
		return (NULL);
	tmp->content = n;
	tmp->next = NULL;
	return (tmp);
}

void	ft_clearnodes_a(t_stack_a **lst)
{
	t_stack_a	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
}

int	ft_listsize_a(t_stack_a *head_a)
{
	int	count;

	count = 0;
	while (head_a != NULL)
	{
		count++;
		head_a = head_a->next;
	}
	return (count);
}

t_stack_a	*ft_listlast_a(t_stack_a *head_a)
{
	if (head_a == NULL)
		return (NULL);
	while (head_a->next != NULL)
		head_a = head_a->next;
	return (head_a);
}
