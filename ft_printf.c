/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junng <junng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:49:12 by junng             #+#    #+#             */
/*   Updated: 2023/05/17 19:49:01 by junng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	I will not go into the specific about the 
	flag's different format & combinations,
	since its tedious and I didn't memorize it.

	I decide to isolate each specifier into its own function since
	I find it easier to debug, rather than trying to inherit multiple values.

	It'll definitely be more efficient if you are able to structure it cleanly,
	but Im too lazy for that, if it works it works.

	variable arguments is what allows you to take in multiple arguments
	#include <stdarg.h>
	va_list is the type to store it.
	va_start initializes the va_list;
	va_arg accesses the item in va_list 1 by 1 each call.
	va_end to clean up the memory assigned to va_list.

	t_flags is a struct that stores all the format information
	
	ft_bzero t_flags struct each time before I use it to make sure its empty.
	
	do_print assigns the specifier to the correct funtion.

	Some things to keep in mind

	%[flags][width][.precision][length]specifier

	1.	. is the Precision, it's the maximum length you can print for the VALUE
		example
			>	printf("%.1d", 1000) =  "1000"
			>	printf("%.s", "hello") = write nothing;
			>	printf("%.d", 0) = write nothing;
			>	printf("%.d", 1) = "1";
			>	printf("%.d", 12345) = "12345";

	2.	Width is the minimum you have to print
		example
			>	printf("%5.1d", 1000) =  " 1000"
			>	printf("%20.s", "hello") = "(space * 20)";
			>	printf("%10.d", 0) = "(space * 10)";
		
	Return value
		the length of the string you printed,
		so everytime you write you have to add it to a value.
*/

int	do_print(t_flags *f, const char **fmt, va_list *ap)
{
	int	l;

	l = 0;
	if (*(*fmt) == 'd' || *(*fmt) == 'i')
		l += put_d(f, va_arg(*ap, int));
	else if (*(*fmt) == 'c')
		l += put_c(f, va_arg(*ap, int));
	else if (*(*fmt) == 's')
		l += put_s(f, va_arg(*ap, char *));
	else if (*(*fmt) == 'p')
		l += put_p(f, va_arg(*ap, unsigned long));
	else if (*(*fmt) == 'u')
		l += put_u(f, va_arg(*ap, unsigned int));
	else if (*(*fmt) == 'x')
		l += put_x(f, va_arg(*ap, unsigned int), 0);
	else if (*(*fmt) == 'X')
		l += put_x(f, va_arg(*ap, unsigned int), 1);
	else if (*(*fmt) == '%')
		l += write(1, "%", 1);
	++(*fmt);
	return (l);
}

int	ft_printf(const char *fmt, ...)
{
	int		l;
	t_flags	f;
	va_list	ap;

	l = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			l += write(1, fmt++, 1);
			continue ;
		}
		++fmt;
		ft_bzero(&f, sizeof(t_flags));
		assign_f(&f, &fmt);
		l += do_print(&f, &fmt, &ap);
	}
	va_end(ap);
	return (l);
}
