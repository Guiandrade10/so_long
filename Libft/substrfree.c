/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:11:38 by gude-and          #+#    #+#             */
/*   Updated: 2025/07/16 19:11:51 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substrfree(char const *s, unsigned int start, size_t len,
		int freeme)
{
	size_t	s_len;
	size_t	size;
	char	*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (malloc(sizeof(char)));
	if (start + len > s_len)
		len = s_len - start;
	size = len + 1;
	str = (char *) malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	if (freeme == 1)
		free((void *)s);
	return (str);
}
