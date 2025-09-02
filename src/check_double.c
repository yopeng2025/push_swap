/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:11:27 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 13:06:11 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double_int(t_stack_a *head_a)
{
	t_stack_a	*tmp1;
	t_stack_a	*tmp2;
	int			n;

	tmp1 = head_a;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1;
		n = tmp2->content;
		tmp2 = tmp2->next;
		while (tmp2 != NULL)
		{
			if (tmp2->content == n)
			{
				ft_putstr_fd("Error\n", 2);
				ft_clearnodes_a(&head_a);
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
