/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:11:42 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 16:02:59 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	check_input(ac, av);
	stacks.head_a = create_list_a(ac, av);
	stacks.head_b = NULL;
	check_double_int(stacks.head_a);
	sort(&stacks);
	free_all(&stacks);
	return (0);
}
