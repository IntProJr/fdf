/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:40:13 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/28 15:54:10 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_memset(void *destination, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char*)destination;
	i = 0;
	if (len)
	{
		while (i < len)
		{
			p[i] = c;
			i++;
		}
	}
	return (destination);
}
