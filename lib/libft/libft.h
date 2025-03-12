/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:54 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/29 16:10:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_format
{
	int		width;
	int		precision;
	int		flags;
	char	type;
}	t_format;


/* DEQUE */

typedef struct s_deque			t_deque;
typedef struct s_deque_node		t_deque_node;

typedef void *					t_deque_type;

struct							s_deque_node
{
	t_deque_node				*prev;
	t_deque_node				*next;
	t_deque_type				data;
};

struct							s_deque
{
	t_deque_node				*head;
	size_t						size;
};

t_deque_type	deque_back(t_deque *deque);
t_deque_type	deque_front(t_deque *deque);
void			deque_emplace_back(t_deque *deque, t_deque_type data);
void			deque_emplace_front(t_deque *deque, t_deque_type data);
void			deque_push_back(t_deque *deque, t_deque_node *node);
void			deque_push_front(t_deque *deque, t_deque_node *node);
t_deque_node	*deque_pop_back(t_deque *deque);
t_deque_node	*deque_pop_front(t_deque *deque);

/* HASH TABLE */

# define TABLE_SIZE 500

typedef struct s_kv
{
	char		*k;
	void		*v;
	struct s_kv	*n;
}				t_kv;

unsigned int	hash(char *key);

void			ht_set(t_kv ht[TABLE_SIZE], char *key, void *value);
char			*ht_get(t_kv ht[TABLE_SIZE], char *key);
t_kv			*ht_init(void);
void			ht_destroy(t_kv ht[TABLE_SIZE]);
void			ht_copy(t_kv src_ht[TABLE_SIZE], t_kv dest_ht[TABLE_SIZE]);

char			**ht_get_keys(t_kv ht[TABLE_SIZE]);
size_t			ht_len(t_kv ht[TABLE_SIZE]);
void			ht_clear(t_kv ht[TABLE_SIZE]);

/* MEMORY */

t_list			**gc_get_storage(int i);
int				gc_set_storage(int flag);
void			*gc_malloc(size_t size);
void			gc_free_gc(int flag);
void			gc_free_ptr(void **ptr);

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, void const *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dest, const char *src, size_t dstsize);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, char c);
char			*ft_strrchr(const char *str, char c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
void			*ft_memchr(const void *src, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(char *big, char *little, size_t len);
long			ft_atoi(const char *nptr);
float			ft_atof(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
int				ft_abs(int n);

/* Printing functions */

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/* Linked-List functions */

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new_node);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new_node);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/* String array functions */

void			ft_strarray_free(char **array);
char			**ft_strarray_alloc(int str_num);
size_t			ft_strarray_len(char **array);
int				ft_strarray_dup(char **src_array, char **dest_array);
char			**ft_strarray_append(char **array, char *new_str);
char			**ft_strarray_remove_by_value(char **array, char *str);
char			**ft_strarray_remove_by_index(char **array, size_t index);

/* GET NEXT LINE */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

char			*gnl(int fd);
char			*str_cutter(int *start, int *end, char **longstr, int free_me);
char			*ft_realloc(char **ptr, int size, int i);

/* ft_printf */

// General
int				ft_dprintf(int fd, const char *format, ...);
int				print(int fd, const char *s, va_list arg);

// Formaters
int				formatter_c(char c, int count, int fd);
int				formatter_s(char *s, int count, int fd);
int				formatter_di(int n, int count, int fd);
int				formatter_u(unsigned int n, int count, int fd);
int				formatter_x(unsigned int x, int count, int upper, int fd);
int				formatter_ptr(void *ptr, int count, int fd);

// Additional
int				numlen(long int n);

#endif // !LIBFT_H
