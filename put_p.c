/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junng <junng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:29:37 by junng             #+#    #+#             */
/*   Updated: 2023/05/17 19:48:44 by junng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_hex_len(unsigned long nb)
{
	int	l;

	l = 1;
	while (nb / 16)
	{
		nb /= 16;
		++l;
	}
	return (l);
}

static int	ft_puthex_rc(unsigned long nb)
{
	int		l;
	char	c;

	l = 0;
	if (nb > 15)
	{
		l += ft_puthex_rc(nb / 16);
		l += ft_puthex_rc(nb % 16);
	}
	else if (nb > 9)
	{
		c = nb + 87;
		l += write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		l += write(1, &c, 1);
	}
	return (l);
}

int	ft_puthex(unsigned long nb)
{
	int	l;

	l = 0;
	l += write(1, "0x", 2);
	l += ft_puthex_rc(nb);
	return (l);
}

/*
	For %p

	v_len = number length in hexadecimal form + 2 for "0x"

	if lstart = start from the left and padding on the right
	
	for %p specifier there isn't many flags, only min width.
*/

int	put_p(t_flags *f, unsigned long n)
{
	int		l;
	int		v_len;
	int		t;

	l = 0;
	t = n;
	v_len = count_hex_len(n) + 2;
	if (f->lstart)
	{
		l += ft_puthex(n);
		while (f->min_w > l)
			l += write(1, " ", 1);
	}
	else
	{
		while (f->min_w > v_len + l)
			l += write(1, " ", 1);
		l += ft_puthex(n);
	}
	return (l);
}
