/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 08:12:06 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/20 18:20:11 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <unistd.h>
# include <stdlib.h>

char	*return_value(char **s);
char	*get_next_line(int fd);
int		chec_new_line(char *s);
char	*ft_str_dup(char *s, int len);
int		ft_str_len(char *s);
char	**my_split(char *str);
char	*ft_join(char *s1, char *s2);

#endif
