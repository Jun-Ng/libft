/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junng <junng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:08:57 by junng             #+#    #+#             */
/*   Updated: 2023/05/17 19:48:41 by junng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr(int n)
{
	char	c;
	int		l;
	int		temp;
	int		len;

	l = 1;
	len = 0;
	temp = n;
	while (temp > 9 || temp < -9)
	{
		temp /= 10;
		l *= 10;
	}
	while (l)
	{
		c = (n / l) + 48;
		if (n < 0)
			c = ((n / l) * -1) + 48;
		len += write(1, &c, 1);
		n %= l;
		l /= 10;
	}
	return (len);
}

static int	count_expected_len(t_flags *f, int d, int *v_lenp)
{
	int	temp;
	int	v_len;
	int	e_len;

	if (!d && f->p_used && !f->precision)
	{
		*v_lenp = 0;
		return (0);
	}
	e_len = 0;
	temp = d;
	v_len = 1;
	while (temp / 10)
	{
		v_len += 1;
		temp /= 10;
	}
	e_len = v_len;
	if (e_len < f->precision)
		e_len = f->precision;
	*v_lenp = v_len;
	return (e_len);
}

static int	p_flags(t_flags *f, int d, int e_len, int v_len)
{
	int	l;

	l = 0;
	if (f->show_sign && d > -1)
		l += write(1, "+", 1);
	else if (d < 0)
		l += write(1, "-", 1);
	else if (f->space)
		l += write(1, " ", 1);
	while (v_len && f->pad_zeros && f->min_w > e_len + l)
		l += write(1, "0", 1);
	while (v_len && e_len-- > v_len)
		l += write(1, "0", 1);
	if (v_len)
		l += ft_putnbr(d);
	return (l);
}

/*
	l = the amount wrote. will be added with every write
	e_len = expected length after minimum precision padding
	v_len = number's length without + - sign

	if lstart = start from the left and padding on the right

	print_flags
		prints the paddings & plus minus signs if needed, and precision as well

	I will not go into the specific about the 
	flag's different format & combinations,
	since its tedious and I didn't memorize it.

*/

int	put_d(t_flags *f, int d)
{
	int	l;
	int	v_len;
	int	e_len;

	l = 0;
	e_len = count_expected_len(f, d, &v_len);
	if (f->lstart)
	{
		l += p_flags(f, d, e_len, v_len);
		while (!f->pad_zeros && f->min_w > l)
			l += write(1, " ", 1);
	}
	else
	{
		while (!f->pad_zeros && f->min_w > e_len + l + (d < 0 || f->show_sign))
			l += write(1, " ", 1);
		l += p_flags(f, d, e_len, v_len);
	}
	return (l);
}
