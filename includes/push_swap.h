/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:26:21 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/16 22:53:10 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct			s_stacks
{
	int					data;
	int					step;
	int					rotation;
	struct s_stacks		*next;
}						t_stack;

/*
** t_pos keeping information of calculation
** than to find minimum value to actions for
** put values in order;
*/

typedef struct			s_pos
{
	int					a_shift;
	int					b_shift;
	int					a_rote;
	int					b_rote;
}						t_pos;

/*
** mass variable keeping max digit[2], middle digit[1] and min digit[0]
*/

typedef struct			s_variables
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	int					*arr;
	int					count;
	int					mass[3];
	int					qa;
	int					qb;
}						t_vars;

int						ft_general_parser(int argc, char **argv, t_vars *psv);
void					error_print(t_vars *psv, int a);
int						ft_atoips(t_vars *psv, const char *str);
int						ft_check_sym(char *str);
int						ft_init_array(t_vars *psv, int argc);
int						ft_args_in_1_string(char *str, t_vars *psv);
int						ft_args_in_other_strings(char **argv, \
							int argc, t_vars *psv);

/*
** How to check duplicate?
*/

void					ft_check_dupl(t_vars *psv);

/*
** Functions for record from array to list
*/

void					ft_init_lists(t_vars *psv, int mem);
t_stack					*ft_malloc_list(t_vars *psv, int mem);
void					ft_free_list(t_vars *psv);
int						ft_check_sort_ch(t_vars *psv);
int						ft_check_sort(t_vars *psv);

/*
** Performing rule swap two first elements;
*/

void					ft_sa(t_vars *psv, int ps);
void					ft_sb(t_vars *psv, int ps);
void					ft_ss(t_vars *psv, int ps);

/*
** Performing rule pp of take on element of one stack and
**put to the top of other one stack
*/

void					ft_pb(t_vars *psv, int ps);
void					ft_pa(t_vars *psv, int ps);

/*
** Performing functions rr
*/

void					ft_ra(t_vars *psv, int ps);
void					ft_rb(t_vars *psv, int ps);
void					ft_rr(t_vars *psv, int ps);

/*
** Performing functions rrr
*/

void					ft_rra(t_vars *psv, int ps);
void					ft_rrb(t_vars *psv, int ps);
void					ft_rrr(t_vars *psv, int ps);

/*
** Finding max, med, min;
*/

void					ft_find_bones(t_vars *psv);
void					ft_quick_sort(int *arr, int start, int end);
void					ft_calc_step(t_stack *tmp, int quan);

/*
** Solution of push_swap
*/

void					ft_3args_solution(t_vars *psv);
void					ft_5args_solution(t_vars *psv);

void					ft_solver_ps(t_vars *psv);
void					ft_general_solution(t_vars *psv);
void					ft_general_sort(t_vars *psv);
void					ft_find_bones(t_vars *psv);

void					ft_calc_step(t_stack *tmp, int quan);
void					ft_calc_place_for_insertion(t_vars *psv, t_pos *pos);
int						ft__search_and_calc_position(t_vars *psv, \
							t_pos *pos, int calc);
void					ft_search_position(t_vars *psv, int *tmp, int *actions);
int						ft_search_small_element(t_vars *psv, int *data, \
							int data_b);
void					ft_calculate_small_element(t_vars *psv, \
							int *tmp, int *actions);
void					ft_performance_actions(t_vars *psv, t_pos *pos);
void					ft_align_in_order(t_vars *psv);

#endif
