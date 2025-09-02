/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:40:52 by yopeng            #+#    #+#             */
/*   Updated: 2025/09/01 13:00:44 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute(t_stacks *stacks)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		execute_cmd(stacks, cmd);
		free(cmd);
	}
	if (check_list_order(stacks) && ft_listsize_b(stacks->head_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	execute_cmd(t_stacks *stacks, char *cmd)
{
	(void) stacks;
	if (!ft_strncmp(cmd, "ra\n", 3))
		ft_rotate(stacks, 'a');
	else if (!ft_strncmp(cmd, "rb\n", 3))
		ft_rotate(stacks, 'b');
	else if (!ft_strncmp(cmd, "rr\n", 3))
		ft_rotate(stacks, 'r');
	else if (!ft_strncmp(cmd, "rra\n", 4))
		ft_rev_rotate(stacks, 'a');
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		ft_rev_rotate(stacks, 'b');
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		ft_rev_rotate(stacks, 'r');
	else if (!ft_strncmp(cmd, "sa\n", 3))
		ft_swap(stacks, 'a');
	else if (!ft_strncmp(cmd, "sb\n", 3))
		ft_swap(stacks, 'b');
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ft_swap(stacks, 's');
	else if (!ft_strncmp(cmd, "pa\n", 3))
		ft_push(stacks, 'a');
	else if (!ft_strncmp(cmd, "pb\n", 3))
		ft_push(stacks, 'b');
	else
		free_and_exit(stacks, cmd);
}
