/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:49:48 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/16 18:23:51 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** reverse rotate stacks elements
** shift down all elements of stacks by 1;
** the last element becomes the first one.
*/

void		ft_rra(t_vars *psv, int ps)
{
	t_stack	*first;
	t_stack	*tmp;
	t_stack	*last;

	if (!psv->stack_a->next)
		return ;
	first = psv->stack_a;
	last = psv->stack_a;
	while (last->next->next != NULL)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = first;
	psv->stack_a = tmp;
	psv->count += 1;
	if (ps)
		write(1, "rra\n", 4);
}

void		ft_rrb(t_vars *psv, int ps)
{
	t_stack	*first;
	t_stack	*tmp;
	t_stack	*last;

	if (!psv->stack_b || psv->stack_b->next == NULL)
		return ;
	first = psv->stack_b;
	last = psv->stack_b;
	while (last->next->next != NULL)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = first;
	psv->stack_b = tmp;
	psv->count += 1;
	if (ps)
		write(1, "rrb\n", 4);
}

void		ft_rrr(t_vars *psv, int ps)
{
	if (ps)
	{
		ft_rra(psv, 1);
		ft_rrb(psv, 1);
	}
	else
	{
		ft_rra(psv, 0);
		ft_rrb(psv, 0);
	}
	psv->count += 1;
	if (ps)
		write(1, "rrr\n", 4);
}
