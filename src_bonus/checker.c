/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:35:23 by yopeng            #+#    #+#             */
/*   Updated: 2025/09/01 12:59:30 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	check_input(ac, av);
	stacks.head_a = create_list_a(ac, av);
	stacks.head_b = NULL;
	check_double_int(stacks.head_a);
	execute(&stacks);
	free_all_bonus(&stacks);
}
