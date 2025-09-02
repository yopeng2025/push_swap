/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:55:45 by yopeng            #+#    #+#             */
/*   Updated: 2025/09/01 12:45:37 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rev_rotate(t_stacks *stacks, char c)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (c == 'a')
		ft_rev_rotate_a_bonus(stacks, stacks->head_a);
	else if (c == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_rev_rotate_b_bonus(stacks, stacks->head_b);
	}
	else
	{
		if (stacks->head_a == NULL || stacks->head_a->next == NULL
			|| head_b == NULL || head_b->next == NULL)
			return ;
		ft_rev_rotate_a_bonus(stacks, stacks->head_a);
		ft_rev_rotate_b_bonus(stacks, stacks->head_b);
	}
}

void	ft_rev_rotate_a_bonus(t_stacks *stacks, t_stack_a *head_a)
{
	t_stack_a	*tmp;
	int			i;
	int			size;

	size = ft_listsize_a(stacks->head_a);
	tmp = head_a;
	while (head_a->next != NULL)
		head_a = head_a->next;
	head_a->next = tmp;
	stacks->head_a = head_a;
	tmp = stacks->head_a;
	i = 0;
	while (i < size - 1)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
}

void	ft_rev_rotate_b_bonus(t_stacks *stacks, t_stack_b *head_b)
{
	t_stack_b	*tmp;
	int			i;
	int			size;

	size = ft_listsize_b(stacks->head_b);
	tmp = head_b;
	while (head_b->next != NULL)
		head_b = head_b->next;
	head_b->next = tmp;
	stacks->head_b = head_b;
	tmp = stacks->head_b;
	i = 0;
	while (i < size - 1)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
}
