#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void	*ft_memcpy(void *buf, const void *source, size_t len);
void	*ft_memmove(void *buf, const void *source, size_t len);
void	*ft_memset(void *arr, int c, size_t len);
void	ft_bzero(void *arr, size_t len);
void	*ft_calloc(size_t sym, size_t symsize);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *string, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_n_len(int n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
int		ft_isalnum(int character);
int		ft_isalpha(int character);
int		ft_isascii(int character);
int		ft_isdigit(int character);
int		ft_isprint(int character);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_toupper(int c);

size_t	ft_strlcat(char *buf, const char *source, size_t size);
size_t	ft_strlcpy(char *buf, const char *source, size_t bufsize);

#endif
