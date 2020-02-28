/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:57:40 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/28 15:54:10 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	while (dst[i] != '\0')
		i++;
	len = 0;
	while (src[len] != '\0' && len < n)
	{
		dst[i] = src[len];
		i++;
		len++;
	}
	dst[i] = '\0';
	return (dst);
}
