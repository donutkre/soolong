/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:12:50 by ktiong            #+#    #+#             */
/*   Updated: 2021/04/29 14:12:50 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define BIAS 0x3FF

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_chrstr(unsigned char c, const char *s);
void				ft_putchar(char c);
char				*ft_strcpy(char *dst, const char *src);
void				ft_putstr(char const *s);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_atoi(const char *nbr);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_free(char *c);
void				ft_putfstr_fd(char *s, size_t len, int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_itoa(int n);
int					ft_open(char *file);
char				*ft_strndup(char *s);
char				*ft_strnew(size_t size);
int					get_next_line(int fd, char **line);
int					ft_strlen(char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, char *src, size_t size);
char				*ft_strrev(char *str);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s1, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_putnbr(int n);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

char				*ft_htoi(unsigned long long n, char s);
char				*ft_utoi(unsigned long long n);
char				*ft_otoi(unsigned long long n);
int					ft_ishex(int c);
int					ft_ispunc(int c);
int					ft_isxdigit(int c);
int					ft_isspace(int c);
void				ft_memdel(void **ap);
int					ft_zerolen(char *str);
void				ft_putnstr_fd(char *s, size_t max_len, int fd);
long				ft_tern(int c, long c1, long c2);
char				ft_ternc(int c, char c1, char c2);
long long			ft_ternl(int c, long long c1, long long c2);
long double			ft_ternf(int c, long double c1, long double c2);
void				*ft_ternp(int c, void *c1, void *c2, short tofree);

#endif
