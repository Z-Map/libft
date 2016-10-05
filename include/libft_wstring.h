/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_wstring.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:34:07 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 03:39:37 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBft_wstrING_H
# define LIBft_wstrING_H
#include <wchar.h>
# include "ft.h"
# include "libft_memory.h"

size_t				ft_wstrlen (const wchar_t *s);

/*
** TO DO
*/
char				*ft_wstrdup (const char *s1);
char				*ft_wstrcpy (char *dst, const char *src);
char				*ft_wstrncpy (char *dst, const char *src, size_t n);
char				*ft_wstrcat (char *s1, const char *s2);
char				*ft_wstrncat (char *s1, const char *s2, size_t n);
size_t				ft_wstrlcat (char *dst, const char *src, size_t size);
char				*ft_wstrchr (const char *s, int c);
char				*ft_wstrrchr (const char *s, int c);
char				*ft_wstrchrnot (const char *s, int c);
char				*ft_wstrchranpy (const char *s, const char *clst, char end);
int					ft_wstridx(const char *s, int c);
char				*ft_wstrstr (const char *s1, const char *s2);
char				*ft_wstrnstr (const char *s1, const char *s2, size_t n);
int					ft_wstrcmp (const char *s1, const char *s2);
int					ft_wstrncmp (const char *s1, const char *s2, size_t n);
char				*ft_wstrnew (size_t size);
void				ft_wstrdel (char **as);
void				ft_wstrclr (char *s);
void				ft_wstriter(char *s, void (*f)(char *));
void				ft_wstriteri(char *s, void (*f)(unsigned int, char *));
char				*ft_wstrmap(char const *s, char (*f)(char));
char				*ft_wstrmapi(char const *s, char (*f)(unsigned int, char));
int					ft_wstrequ(char const *s1, char const *s2);
int					ft_wstrnequ(char const *s1, char const *s2, size_t n);
char				*ft_wstrsub(char const *s, unsigned int start, size_t len);
char				*ft_wstrjoin(char const *s1, char const *s2);
char				*ft_wstrtrim(char const *s);
char				**ft_wstrsplit(char const *s, char c);
int					ft_wisalnum(int c);
int					ft_wisalpha(int c);
int					ft_wisdigit(int c);
int					ft_wisascii(int c);
int					ft_wisprint(int c);
int					ft_wtolower(int c);
int					ft_wtoupper(int c);
int					ft_wislower(int c);
int					ft_wisupper(int c);
size_t				ft_wwrdcount(char const *s, int c);
char				*ft_wstrunsplit(const char **tab, char separator);
char				*ft_wstrmjoin(const size_t n, ...);
char				*ft_wstrreplace(char *s, char what, char by);
size_t				ft_wstrcount(const char *str, char c);
int					ft_wstrncount(char *str, char c, unsigned int n);
char				*ft_wstrrev(char *str);
char				*ft_wstrnrev(char *str, size_t n);
char				*ft_wstrup(char *s);
char				*ft_wstrupdup(const char *s);
char				*ft_wstrlow(char *s);
char				*ft_wstrlowdup(const char *s);

#endif
