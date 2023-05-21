/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junng <junng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:15:47 by junng             #+#    #+#             */
/*   Updated: 2023/05/17 19:48:51 by junng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	put_x_rc(unsigned int nb, int cap)
{
	int		l;
	char	c;

	l = 0;
	if (nb > 15)
	{
		l += put_x_rc(nb / 16, cap);
		l += put_x_rc(nb % 16, cap);
	}
	else if (nb > 9)
	{
		c = nb + 87;
		if (cap)
			c = nb + 87 - 32;
		l += write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		l += write(1, &c, 1);
	}
	return (l);
}

static int	count_hex_len(unsigned int nb)
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

int	put_x_flags(t_flags *f, unsigned int nb, int cap, int v_len)
{
	int	l;
	int	p_len;

	l = 0;
	p_len = v_len;
	if (p_len < f->precision)
		p_len = f->precision;
	if (cap == 1 && nb != 0 && f->p0x)
		l += write(1, "0X", 2);
	else if (cap == 0 && nb != 0 && f->p0x)
		l += write(1, "0x", 2);
	while (p_len > v_len++)
		l += write(1, "0", 1);
	if (nb != 0 || !f->p_used || f->precision)
		l += put_x_rc(nb, cap);
	return (l);
}

/*

	%x	%X

	x = lowercase
	X = uppercase

	put_x 

	for put_x you have to write the value in hexadecimal form
	"#" flag means that you have to add a "0x" at the start of the hex value.
	if "#" is not provided you just have to write the value in hexadecimal form


*/

int	put_x(t_flags *f, unsigned int nb, int cap)
{
	int	l;
	int	v_len;
	int	p_len;

	l = 0;
	v_len = count_hex_len(nb);
	p_len = 0;
	if (nb != 0 || !f->p_used || f->precision)
		p_len = v_len;
	if (p_len < f->precision)
		p_len = f->precision;
	if (f->lstart)
		l += put_x_flags(f, nb, cap, v_len);
	while (f->lstart && f->pad_zeros && f->min_w > l)
		l += write(1, "0", 1);
	while (f->lstart && f->min_w > l)
		l += write(1, " ", 1);
	while (!f->lstart && f->pad_zeros && f->min_w > p_len + l + (f->p0x * 2))
		l += write(1, "0", 1);
	while (!f->lstart && !f->pad_zeros && f->min_w > p_len + l + (f->p0x * 2))
		l += write(1, " ", 1);
	if (!f->lstart)
		l += put_x_flags(f, nb, cap, v_len);
	return (l);
}
