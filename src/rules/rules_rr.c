/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:49:38 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/16 18:24:33 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** taking first list with first element to tmp variable
** Finding last element through cycle;
** Zeroing next element of tmp;
** last list will indicate to tmp;
** first element take address of second element;
*/

void		ft_ra(t_vars *psv, int ps)
{
	t_stack	*first;
	t_stack	*tmp;
	t_stack	*last;

	if ((!psv->stack_a) || !(psv->stack_a->next))
		return ;
	tmp = psv->stack_a;
	last = psv->stack_a;
	first = psv->stack_a->next;
	while (last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	psv->stack_a = first;
	psv->count += 1;
	if (ps)
		write(1, "ra\n", 3);
}

void		ft_rb(t_vars *psv, int ps)
{
	t_stack	*first;
	t_stack	*tmp;
	t_stack	*last;

	if ((!psv->stack_b) || !(psv->stack_b->next))
		return ;
	tmp = psv->stack_b;
	last = psv->stack_b;
	first = psv->stack_b->next;
	while (last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	psv->count += 1;
	psv->stack_b = first;
	if (ps)
		write(1, "rb\n", 3);
}

/*
** doing ra and rb together;
*/

void		ft_rr(t_vars *psv, int ps)
{
	if (ps)
	{
		ft_ra(psv, 1);
		ft_rb(psv, 1);
	}
	else
	{
		ft_ra(psv, 0);
		ft_rb(psv, 0);
	}
	psv->count += 1;
	if (ps)
		write(1, "rr\n", 3);
}
