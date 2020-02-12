#include "../../includes/push_swap.h"


/*
 * ft_calc_step calculating how much steps
 * should be than to be at the top position
 * and set up rotation, which indicate which
 * rotation should be than to move by top
 * Rotation 1 mean ft_ra and -1 mean ft_rra
 * (shift up), (shift down);
*/

void        ft_calc_step(t_stack *tmp, int quan)
{
    int     i;
    int     mid;
    t_stack *list;

    list = tmp;
    i = 0;
    mid = quan / 2;
    while (mid >= i)
    {
        list->step = i;
        list->rotation = 1;
        list = list->next;
        i++;
    }
    if (quan % 2 == 0)
        i--;
    while (--i > 0)
    {
        list->step = i;
        list->rotation = -1;
        list = list->next;
    }
}

/*
 * Goal of function is double checking founded
 * place with other each other places.
 * if have more suitable place - returning 1;
 */

int         ft_search_small_element(t_vars *psv, int *data, int data_b)
{
	t_stack *tmp;
	int     res;

	tmp = psv->stack_a;
	res = 0;
	while (res == 0 && tmp)
	{
		if (tmp->data < *data && tmp->data > data_b)
			res = 1;
		tmp = tmp->next;
	}
	return (res);
}

/*
 * with first digit of stack_b we are looking for
 * position between digits of stack_a.
 * If digit of stack_b bigger than previos digit of stack_a
 * and less than next digit of stack - we found position
 * for this digit;
 * After it the second time we check suitable of founded
 * position;
 * And if it founded - adding +1 to actions;
 */

void        ft_search_position(t_vars *psv, int *tmp, int *actions)
{
	while (psv->stack_a)
	{
		*tmp = psv->stack_a->data;
		if (psv->stack_a->data < psv->stack_b->data)
		{
			*actions = *actions + 1;
			if (psv->stack_b->data < psv->stack_a->next->data)
				break;
			psv->stack_a = psv->stack_a->next;
		}
		else
			break;
	}
	if (ft_search_small_element(psv, tmp, psv->stack_b->data))
	{
		while (psv->stack_a) {
			if (psv->stack_a->data < *tmp && psv->stack_a->data > psv->stack_b->data)
				break;
			else
                *actions = *actions + 1;
			psv->stack_a = psv->stack_a->next;
		}
	}
}

/*
 * Goal of this function at first find position
 * for digit of stack_b in stack_a and return
 * count of actions.
 * After it checking is it a minimum action via
 * comparing result of addition of actions and steps of
 * current number;
 * If it's more than minimum (calc variable), it's mean
 * that position found.
 * we are recording results in pos structure of variables
 * than to perform this instruction in next func.
 * Recording count of rotate to a_turn for put current digit
 * of stack_b to top position. Digit which less than current number of
 * stack_b will be in down, digit of stack_b at the top and digit bigger than
 * current digit of stack_b will be next after top position.
 * b_turn counting how much rotation should be than to find current digit
 * at the top of stack_b than to put it to stack_a;
 * Else signaling via assigning value of min to rec and returning;
 */

int         ft__search_and_calc_position(t_vars *psv, t_pos *pos, int calc)
{
	int     tmp;
    int     actions;
    int     rec;

	tmp = 0;
	actions = 0;
	ft_search_position(psv, &tmp, &actions);
	if (psv->stack_a->rotation == -1)
		actions = psv->qa - actions;
	if (calc == -1 || (psv->stack_b->step + actions) < calc)
	{
		pos->a_turn = psv->stack_a->rotation;
		pos->b_turn = psv->stack_b->rotation;
		pos->a_quantity = actions;
		pos->b_quantity = psv->stack_b->step;
		rec = psv->stack_b->step + actions;
	}
	else
		rec = calc;
	return (rec);
}

/*
 * Goal of function to find digit which will take
 * minimum actions to move from stack_b to stack_a;
 * Calc have first value -1, because it's signal, that
 * it's first operation;
 * Than to save heads of stacks - saving head in pointers
 * save_!.
*/

void        ft_calc_place_for_insertion(t_vars *psv, t_pos *pos)
{
	int     calc;
	t_stack *save_a;
	t_stack *save_b;
	int     tmpqb;

	tmpqb = psv->qb;
	calc = -1;
	save_a = psv->stack_a;
	save_b = psv->stack_b;
	while (tmpqb)
	{
		calc = ft__search_and_calc_position(psv, pos, calc);
		psv->stack_a = save_a;
		psv->stack_b = psv->stack_b->next;
		tmpqb--;
	}
	psv->stack_b = save_b;
}

/*
 * Performing actions, which calculated from
 * ft_calc_place_for_insertion
 * If have action to turn - turn;
 * a_turn is rotation. If it is - turning ft_ra;
 * else ft_rra because value of turn is 1 or -1
 * (rotating with shift down);
 *
 */

void        ft_performance_actions(t_vars *psv, t_pos *pos)
{
	while (pos->a_quantity)
	{
		if (pos->a_turn)
			ft_ra(psv, 1);
		else
			ft_rra(psv, 1);
		pos->a_quantity--;
	}
	while (pos->b_quantity) {
		if (pos->b_turn)
			ft_rb(psv, 1);
		else
			ft_rrb(psv, 1);
		pos->b_quantity--;
	}
	ft_pa(psv, 1);
}

/*
 * this function aligning all digits by order
 * if min digit close by start - doing ft_ra
 * else ft_rra
 * Doing it than to econom count of actions to align
 * by order.
 */

void        ft_align_in_order(t_vars *psv)
{
	int     i;
	int     j;
    t_stack *tmp;

    tmp = psv->stack_a;
	j = psv->qa / 2;
	i = 1;
	while (tmp->data != psv->mass[0])
	{
        tmp = tmp->next;
        i++;
    }
	if (i > j)
		while (psv->stack_a->data != psv->mass[0])
			ft_rra(psv, 1);
	else
		while (psv->stack_a->data != psv->mass[0])
			ft_ra(psv, 1);
}

/*
 * Initializing positions variable than to keep
 * there information about calculation of steps for
 * every digit to move values from stack b to stack a.
 * Allocating memory than to spend less memory for
 * performance of program.
 * start value of ?_quantity is -1 than to
 * save of mistakes of calc steps;
 * When all digits pushed to stack_a - we should to sort
 * stack_a by order;
 */

void        ft_general_sort(t_vars *psv)
{
	t_pos   *pos;
	if (!(pos = (t_pos *)malloc(sizeof(t_pos))))
		exit(1);
    while (psv->qb > 0)
    {
    	pos->a_quantity = -1;
    	pos->b_quantity = -1;
    	pos->a_turn = 0;
    	pos->b_turn = 0;
        ft_calc_step(psv->stack_a, psv->qa);
        ft_calc_step(psv->stack_b, psv->qb);
        ft_calc_place_for_insertion(psv, pos);
        ft_performance_actions(psv, pos);
    }
	free(pos);
    ft_align_in_order(psv);
}

/*
 * All digitals with the exception of min and max values
 * pushing to stack_b;
 * if digit less than medium value - pushing by begining;
 * if digit bigger than medium value - pushing by begining and shifting down with ft_rb;
 * pushing from stack_b to stack_a random number for comparing of next algorithm;
 */

void        ft_general_solution(t_vars *psv)
{
    while (psv->qa > 2)
    {
        if (psv->stack_a->data != psv->mass[0] && psv->stack_a->data != psv->mass[2])
        {
            if (psv->stack_a->data > psv->mass[1])
            {
                ft_pb(psv, 1);
                ft_rb(psv, 1);
            }
            else
                ft_pb(psv, 1);
        }
        else
            ft_ra(psv, 1);
    }
    if (psv->stack_a->data < psv->stack_a->next->data)
        ft_sa(psv, 1);
    ft_pa(psv, 1);
    ft_general_sort(psv);
}

/*
 ** psv->mass[0] saving minimum, [1] saving medium, [2] saving maximum value;
 */


/*
 * in array all digits, in start a zero and in end the count of
 * digits;
 * At first assigning values of first, last and middle;
 * in cycle checking if first number is less than middle,
 * we are remaining and taking next number for comparison;
 * in cycle checking last number. If it's bigger than
 * middle number - taking next number for comparison;
 * in next general cycle sorting swaping left and right
 * numbers;
 */

void        ft_quick_sort(int *s_arr, int first, int last) {
    int left;
    int right;
    int middle;
    int tmp;

    left = first;
    right = last - 1;
    middle = s_arr[(left + right) / 2];
    if (first < last) {
        while (s_arr[left] < middle)
            left++;
        while (s_arr[right] > middle)
            right--;
        while (left <= right) {
            if (left <= right) {
                tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
            ft_quick_sort(s_arr, first, right);
            ft_quick_sort(s_arr, left, last);
        }
    }
}

void     ft_find_bones(t_vars *psv)
{
    int     i;

    i = 0;
	ft_quick_sort(psv->arr, i, psv->qa);
	psv->mass[0] = psv->arr[0];
	psv->mass[1] = psv->arr[psv->qa / 2];
	psv->mass[2] = psv->arr[psv->qa - 1];
}









