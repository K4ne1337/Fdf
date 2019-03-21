/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:29:31 by abelkhay          #+#    #+#             */
/*   Updated: 2019/01/26 15:50:23 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;

	if (!s1 || !s2)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!fresh)
		return (NULL);
	ft_strcpy(fresh, s1);
	ft_strcat(fresh, s2);
	return (fresh);
}
