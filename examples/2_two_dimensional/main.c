/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 10:31:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/20 10:49:34 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "main.h"

////////////////////////////////////////////////////////////////////////////////

int	main(void)
{
	int	**ints_2d;
	int	*row_0;
	// int	*row_1;
	// int	v;

	ints_2d = vector_new(sizeof(int *));

	row_0 = vector_new(sizeof(int));
	vector_push(&ints_2d, row_0);

	// v = 1;
	// vector_push(&row_0, &v);
	// v = 2;
	// vector_push(&row_0, &v);
	// v = 3;
	// vector_push(&row_0, &v);

	// row_1 = vector_new(sizeof(int));
	// v = 4;
	// vector_push(&row_1, &v);
	// v = 5;
	// vector_push(&row_1, &v);
	// v = 6;
	// vector_push(&row_1, &v);
	// vector_push(&ints_2d, row_1);

	// printf("%d%d%d\n", ints_2d[0][0], ints_2d[0][1], ints_2d[0][2]);
	// printf("%d%d%d\n", ints_2d[1][0], ints_2d[1][1], ints_2d[1][2]);

	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
