/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:49:16 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 12:40:56 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct s_node
{
	int					content;
	struct s_node		*next;
}						t_node;

typedef t_node	t_stack_a;
typedef t_node	t_stack_b;

typedef struct s_value
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}						t_value;

typedef struct s_move
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_move;

typedef struct s_fast
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_fast;

typedef struct s_stacks
{
	t_node				*head_a;
	t_node				*head_b;
	t_value				*value;
	t_move				*move;
	t_fast				*fast;
}						t_stacks;

// check_input
void					check_input(int ac, char **av);
void					check_int(int ac, char **av);
void					check_int_size(int ac, char **av);

// list
int						check_list_order(t_stacks *stacks);

// list_a
t_stack_a				*create_list_a(int ac, char **av);
t_stack_a				*ft_newnode_a(int n);
void					ft_clearnodes_a(t_stack_a **lst);
int						ft_listsize_a(t_stack_a *head_a);
t_stack_a				*ft_listlast_a(t_stack_a *head_a);

// list_b
int						ft_listsize_b(t_stack_b *head_b);
int						find_index_stack_b(t_stacks *stacks, int n);
void					ft_clearnodes_b(t_stack_b **lst);

// check_double_int
void					check_double_int(t_stack_a *head_a);

// sort
void					sort(t_stacks *stacks);
int						check_list_order(t_stacks *stacks);
void					sort_two(t_stacks *stacks);
void					sort_three(t_stacks *stacks, int flag);
void					move_three(t_stacks *stacks, int n1, int n2, int n3);
void					sort_four(t_stacks *stacks);

// move
void					ft_push(t_stacks *stacks, char c);
void					ft_push_a(t_stacks *stacks);
void					ft_push_b(t_stacks *stacks);
void					ft_push_a_last(t_stacks *stacks);
void					ft_push_b_empty(t_stacks *stacks);
void					ft_swap(t_stacks *stacks, char c);
void					ft_swap_a(t_stack_a *head_a, int flag);
void					ft_swap_b(t_stack_b *head_b, int flag);
void					ft_rotate(t_stacks *stacks, char c);
void					ft_rotate_a(t_stacks *stacks, t_stack_a *head_a,
							int flag);
void					ft_rotate_b(t_stacks *stacks, t_stack_a *head_b,
							int flag);
void					ft_rev_rotate(t_stacks *stacks, char c);
void					ft_rev_rotate_a(t_stacks *stacks, t_stack_a *head_a,
							int flag);
void					ft_rev_rotate_b(t_stacks *stacks, t_stack_b *head_b,
							int flag);

// move_back_a
void					move_back_a(t_stacks *stacks);
void					put_in_order(t_stacks *stacks);
void					move_order(t_stacks *stacks);

// check_fast
void					check_fast_move(t_stacks *stacks);
void					get_top_stack_a(t_stacks *stacks, t_stack_a *head_a,
							int i);
void					check_double_move(t_stacks *stacks);
void					check_cost(t_stacks *stacks, int i);

// move_fast
void					move_fast(t_stacks *stacks);
void					do_move_fast(t_stacks *stacks);

// max_min
void					check_max_min_a(t_stacks *stacks);
void					check_max_a(t_stacks *stacks, t_stack_a *head_a);
void					check_min_a(t_stacks *stacks, t_stack_a *head_a);
void					check_max_min_b(t_stacks *stacks);
void					check_max_b(t_stacks *stacks, t_stack_b *head_b);
void					check_min_b(t_stacks *stacks, t_stack_b *head_b);
void					new_elem_a(t_stacks *stacks, t_stack_b *head_b);
void					move_elem_a(t_stacks *stacks);
int						search_a(t_stacks *stacks, int n);
void					new_elem_b(t_stacks *stacks, int num_a);
int						search_num_stack_b(t_stacks *stacks, int num_a);
void					new_max_a(t_stacks *stacks);
void					move_max_a(t_stacks *stacks);
int						find_index_stack_a(t_stacks *stacks, int n);
void					new_min_a(t_stacks *stacks);
void					move_min_a(t_stacks *stacks);
void					new_max_min_b(t_stacks *stacks);

// free
void					free_all(t_stacks *stacks);
void					error_exit(void);

#endif