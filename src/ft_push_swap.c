/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:40:39 by dpenney           #+#    #+#             */
/*   Updated: 2019/12/23 15:40:42 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_general_parser(int argc, char **argv, t_vars *psv)
{
	if (argc == 2)
	{
<<<<<<< HEAD:src/ft_push_swap.c
		if (ft_args_in_1_string(argv[1], psv) == 1)
		{
			return(1);
		}
	}
	else if (argc == 1)
		return(1);
	else
	if ((ft_args_in_other_strings(argv, argc, psv) == 1))
		error_print(psv);
=======
		vars->a[i] = ft_atoips(vars, split[i]);
		i++;
//		printf("%d\n", vars->a[j]);
//		j++;
	}
    printf("In several argc %d count\n", res);
	ft_check_duplicates(vars, res);
>>>>>>> e936345e93acf2f22995d40e7270d306cea3aa17:ft_push_swap.c
	return (0);
}

void        ft_print_array_ps(int *array, int quant)
{
	int     i;

	i = 0;
	printf("\nAfter rules aplly\n");
	while (quant >= i)
	{
<<<<<<< HEAD:src/ft_push_swap.c
		printf("%d\n", array[i]);
		i++;
	}
=======
			if(!(vars->a[i - 1] = ft_atoips(vars ,argv[i])))
				return(1);
			++i;
//			printf("%d\n", vars->a[j]);
//			j++;
	}
	printf("In several argc %d count\n", argc - 1);
	ft_check_duplicates(vars, argc);
	return (0);
>>>>>>> e936345e93acf2f22995d40e7270d306cea3aa17:ft_push_swap.c
}

/*
 ** Program getting argument and checking.
 ** if 2 argument - dividing string to separate array strings,
 ** check all string that it's all numbers and after it converting to
 ** integer type and recording to stack a;
 ** if argument just 1 or less - finishing work;
 ** else every argument getting separate - checking that all arguments are digits and
 ** recording to array

** code which split our string to separate string with numbers
** after it check array and confident that every symbols are digits,
** without any other.
** after it through ft_atoi will convert to numbers and record to stack.
** and free result of ft_strsplit
*/

int		main(int argc, char **argv)
{
//	t_vars	*psv;
//	psv = (t_vars *)malloc(sizeof(t_vars));
	t_vars  psv;

	if (((ft_general_parser(argc, argv, &psv)) == 1))
		return (1);
	printf("It's quantity %d\n", psv.qa);
	ft_rule_swap_a(&psv);
	ft_print_array_ps(psv.a, psv.qa);
	return(0);
}