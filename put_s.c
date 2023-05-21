/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junng <junng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:22:10 by junng             #+#    #+#             */
/*   Updated: 2023/05/17 19:48:46 by junng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_s_flags(char *s, int v_len)
{
	int	l;

	l = 0;
	if (!s)
		l += write(1, "(null)", v_len);
	else
		l += write(1, s, v_len);
	return (l);
}

/*
	%s specifier

	v_len = the maximum it can write

	if string is not provided
		v_len = f->precision = maximum amount of char you can print for the value
	
	if lstart = start from the left and padding on the right

	function put_s_flags
		if the string is null, like literally no address
			>	it'll write the string "(null)" cause thats what printf does,
				with v_len as its size
		else
			just write the string, with v_len as its size
*/

int	put_s(t_flags *f, char *s)
{
	int	l;
	int	v_len;

	l = 0;
	v_len = 6;
	if (s)
		v_len = ft_strlen(s);
	if (f->p_used && v_len > f->precision)
		v_len = f->precision;
	if (f->lstart)
	{
		l += put_s_flags(s, v_len);
		while (f->min_w > v_len++)
			l += write(1, " ", 1);
	}
	else
	{
		while (f->min_w > v_len + l)
			l += write(1, " ", 1);
		l += put_s_flags(s, v_len);
	}
	return (l);
}
