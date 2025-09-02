/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:06:53 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 19:49:01 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_listsize_b(t_stack_b *head_b)
{
	int	count;

	count = 0;
	while (head_b != NULL)
	{
		count++;
		head_b = head_b->next;
	}
	return (count);
}

int	find_index_stack_b(t_stacks *stacks, int n)
{
	t_stack_b	*head_b;
	int			size;
	int			i;

	i = 0;
	head_b = stacks->head_b;
	size = ft_listsize_b(stacks->head_b);
	while (i < size)
	{
		if (head_b->content == n)
			break ;
		head_b = head_b->next;
		i++;
	}
	return (i);
}

void	ft_clearnodes_b(t_stack_b **lst)
{
	t_stack_b	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
}
