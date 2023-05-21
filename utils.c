/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junng <junng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:46:38 by junng             #+#    #+#             */
/*   Updated: 2023/05/17 19:48:54 by junng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	init_f = initialize all the values to 0;

	1.	Assigning flags
	2.		

*/

void	assign_f(t_flags *f, const char **fmt)
{
	while (*(*fmt))
	{
		if (*(*fmt) == '#')
			f->p0x = 1;
		else if (*(*fmt) == '-')
			f->lstart = 1;
		else if (*(*fmt) == '+')
			f->show_sign = 1;
		else if (*(*fmt) == ' ')
			f->space = 1;
		else
			break ;
		++(*fmt);
	}
	if (*(*fmt) == '0' && ++(*fmt))
		f->pad_zeros = 1;
	while (ft_isdigit(*(*fmt)))
		f->min_w = f->min_w * 10 + (*((*fmt)++) - '0');
	if (*(*fmt) == '.' && ++(*fmt))
	{
		f->pad_zeros = 0;
		f->p_used = 1;
		while (ft_isdigit(*(*fmt)))
			f->precision = f->precision * 10 + (*((*fmt)++) - '0');
	}
}
