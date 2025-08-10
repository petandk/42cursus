/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:29:46 by pamanzan          #+#    #+#             */
/*   Updated: 2024/10/29 16:18:11 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_strlen(char *str);
int				ft_isalpha(char c);
int				ft_str_isalpha(char *str);
int				ft_str_isdigit(char *str);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
char			ft_toupper(int c);
char			ft_tolower(char c);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strnstr(const char *str1, const char *str2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
int				ft_atoi(char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t num, size_t size);
char			*ft_strdup(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

#endif
