/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:37:20 by dguillon          #+#    #+#             */
/*   Updated: 2024/01/18 14:40:12 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# define FALSE 0
# define TRUE 1

# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef int	t_bool;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_printf(const char *format, ...);
int		put_nbr(long u);
int		put_hexa(unsigned long long n, char x);
int		put_ptr(unsigned long long p);
int		ft_put_char(unsigned char c);
int		str(char *s);
int		ft_atoi(const char *str);
void	*ft_bzero(void *pointer, size_t size);
void	*ft_calloc(size_t elcnt, size_t elsize);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *memblck, int srchc, size_t size);
int		ft_memcmp(const void *p1, const void *p2, size_t size);
void	*ft_memcpy(void *dest, void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *pointer, int value, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *string, int srchc);
char	*ft_strdup(const char *src);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *tab);
char	*ft_strmapi(char const *s, char (*f)(unsigned in, char));
int		ft_strncmp(const char *first, const char *sec, size_t len);
char	*ft_strnstr(const char *big, const char *ltl, size_t size);
char	*ft_strrchr(const char *string, int srchc);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_lstadd_back(t_list **lst, t_list *_new);
void	ft_lstadd_front(t_list **lst, t_list *_new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
char	*get_next_line(int fd);

#endif
