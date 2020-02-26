/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:34:15 by lrosalee          #+#    #+#             */
/*   Updated: 2019/08/31 14:01:42 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	ptr_s1 = (unsigned char*)s1;
	ptr_s2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ptr_s1[i] != ptr_s2[i])
			return ((int)(ptr_s1[i] - ptr_s2[i]));
		i++;
	}
	return (0);
}
