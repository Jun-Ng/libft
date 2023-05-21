/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junng <junng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:13:32 by junng             #+#    #+#             */
/*   Updated: 2023/05/17 19:48:24 by junng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	put_c

	writes a character and then its minimum widths

	example
		printf("%5c", 'a'); = "    a";

	as far as I can tell there isn't any other flags that I have to take care of

*/

int	put_c(t_flags *f, int c)
{
	int	l;
	int	v_len;

	l = 0;
	v_len = 0;
	if (f->lstart)
	{
		l += write(1, &c, 1);
		while (f->min_w > l)
			l += write(1, " ", 1);
	}
	else
	{
		while (f->min_w > 1 + l)
			l += write(1, " ", 1);
		l += write(1, &c, 1);
	}
	return (l);
}
