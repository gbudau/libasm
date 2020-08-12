/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:28:16 by gbudau            #+#    #+#             */
/*   Updated: 2020/08/12 19:12:04 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

size_t	ft__strlen(const char *str);
int		ft__strcmp(const char *s1, const char *s2);
char	*ft__strcpy(char *dst, const char *src);
char	*ft__strdup(const char *str);
ssize_t ft__write(int fd, const void *buf, size_t count);

#endif
