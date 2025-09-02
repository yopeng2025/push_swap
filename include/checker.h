/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:32:24 by yopeng            #+#    #+#             */
/*   Updated: 2025/09/01 12:58:53 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "push_swap.h"

# define INTMAX 2147483647
# define INRMIN -2147483648

int			main(int ac, char **av);

// check_input
void		check_input(int ac, char **av);
void		check_int(int ac, char **av);
void		check_int_size(int ac, char **av);
void		check_double_int(t_stack_a *head_a);

// list_a
t_stack_a	*create_list_a(int ac, char **av);
t_stack_a	*ft_newnode_a(int n);
t_stack_a	*ft_listlast_a(t_stack_a *head_a);
void		ft_clearnodes_a(t_stack_a **lst);
int			ft_listsize_a(t_stack_a *head_a);

// list_b
t_stack_b	*create_list_b(int argc, char **argv);
t_stack_b	*ft_newnode_b(int content);
void		ft_clearnodes_b(t_stack_b **lst);
int			ft_listsize_b(t_stack_b *head_b);

// execute
void		execute(t_stacks *stacks);
void		execute_cmd(t_stacks *stacks, char *cmd);

// push
void		ft_push(t_stacks *stacks, char c);
void		ft_push_a(t_stacks *stacks);
void		ft_push_b(t_stacks *stacks);
void		ft_push_a_last(t_stacks *stacks);
void		ft_push_b_empty(t_stacks *stacks);

// swap
void		ft_swap(t_stacks *stacks, char c);
void		ft_swap_a_bonus(t_stack_a *head_a);
void		ft_swap_b_bonus(t_stack_b *head_b);

// rotate
void		ft_rotate(t_stacks *stacks, char c);
void		ft_rotate_a_bonus(t_stacks *stacks, t_stack_a *head_a);
void		ft_rotate_b_bonus(t_stacks *stacks, t_stack_a *head_b);

//rev_rotate
void		ft_rev_rotate(t_stacks *stacks, char c);
void		ft_rev_rotate_a_bonus(t_stacks *stacks, t_stack_a *head_a);
void		ft_rev_rotate_b_bonus(t_stacks *stacks, t_stack_b *head_b);

// free
void		free_all_bonus(t_stacks *stacks);
void		error_exit_bonus(void);
void		free_and_exit(t_stacks *stacks, char *cmd);
int			check_list_order(t_stacks *stacks);

#endif