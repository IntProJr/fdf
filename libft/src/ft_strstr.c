/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:04:52 by lrosalee          #+#    #+#             */
/*   Updated: 2019/08/31 14:01:42 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	char *big;
	char *small;

	if (*find == '\0')
		return ((char *)str);
	while (*str != '\0')
	{
		big = (char *)str;
		small = (char *)find;
		while (*big != '\0' && *big == *small)
		{
			big++;
			small++;
		}
		if (*small == '\0')
			return ((char *)str);
		str++;
	}
	return (NULL);
}
