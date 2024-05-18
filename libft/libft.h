/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:04:55 by iniska            #+#    #+#             */
/*   Updated: 2024/05/11 12:38:10 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 9
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	char			*s_line;
}					t_list;

// listaa kaikki functiot:
int		ft_isalpha(int a);
int		ft_isdigit(int n);
int		ft_isalnum(int d);
int		ft_isascii(int a);
int		ft_isprint(int p);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char*s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t len);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t loc);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const*s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *dst, const char *src);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t n);

void	*ft_memset(void *m, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd( char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//bonus
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_lstsize(t_list *lst);

//printf

int		ft_printf(const char *format, ...);
int		printchar(char c);
int		printstr(char *s);
int		print_digit(long n, int base, char specifier);
int		ft_form(char specifier, va_list ap);
int		print_address(unsigned long n);

// GNL

char	*get_next_line(int fd);
void	setitfree(t_list **list, t_list *clean_line, char *buf);
t_list	*find_last_line(t_list *list);
int		size_of_line(t_list *list);
int		list_the_line(t_list **list, char *line);
int		look_slash_n(t_list *list);
int		create_line(t_list **list, int fd);
char	*save_line(t_list *list);
void	copy_line(t_list *list, char *str);
int		clean_list(t_list **list);

#endif
