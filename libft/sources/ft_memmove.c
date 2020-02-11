/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:28:50 by lrosalee          #+#    #+#             */
/*   Updated: 2019/08/31 14:01:42 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;

	ptrdst = (unsigned char*)dst;
	ptrsrc = (unsigned char*)src;
	i = 0;
	if (len == 0 || ptrdst == ptrsrc)
		return (ptrdst);
	if (!dst && !src)
		return (NULL);
	if (ptrsrc < ptrdst)
		while (++i <= len)
			ptrdst[len - i] = ptrsrc[len - i];
	else
		while (len-- > 0)
			*(ptrdst++) = *(ptrsrc++);
	return (dst);
}
