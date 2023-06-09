/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junng <junng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:45:17 by junng             #+#    #+#             */
/*   Updated: 2023/05/17 19:48:04 by junng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ----- Chars ----- */

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/* ----- Strings ----- */

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** ----- Alphabets / Int Conversions -----
*/

char		*ft_itoa(int n);
int			ft_atoi(const char *str);

/*
** ----- Memory -----
*/

int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);

/*
** ----- File Descriptors -----
*/

void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);

/*
** ----- Structs -----
*/

int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
** ----- Printf -----
*/

typedef struct s_flags
{
	int	p0x;
	int	lstart;
	int	show_sign;
	int	pad_zeros;
	int	space;
	int	min_w;
	int	precision;
	int	p_used;
}	t_flags;

int		ft_printf(const char *fmt, ...);

void	assign_other(t_flags *f, const char **fmt);
void	assign_f(t_flags *f, const char **fmt);
void	init_f(t_flags *f);

/* --- PUTS --- */

int		put_d(t_flags *f, int d);
int		put_c(t_flags *f, int d);
int		put_s(t_flags *f, char *s);
int		put_p(t_flags *f, unsigned long n);
int		put_u(t_flags *f, unsigned int n);
int		put_x(t_flags *f, unsigned int nb, int cap);

#endif