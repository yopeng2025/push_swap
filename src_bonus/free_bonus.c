/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:09:57 by yopeng            #+#    #+#             */
/*   Updated: 2025/09/02 15:57:03 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_all_bonus(t_stacks *stacks)
{
	ft_clearnodes_a(&stacks->head_a);
	if (stacks->head_b != NULL)
		ft_clearnodes_b(&stacks->head_b);
}

void	error_exit_bonus(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_and_exit(t_stacks *stacks, char *cmd)
{
	free_all_bonus(stacks);
	get_next_line(-1);
	free(cmd);
	error_exit_bonus();
}

int	check_list_order(t_stacks *stacks)
{
	t_stack_a	*head_a;
	int			n;
	int			i;

	i = 1;
	head_a = stacks->head_a;
	n = head_a->content;
	while (i < ft_listsize_a(stacks->head_a))
	{
		head_a = head_a->next;
		if (n > head_a->content)
			return (0);
		n = head_a->content;
		i++;
	}
	return (1);
}
