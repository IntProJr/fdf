/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:53:11 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/28 15:54:10 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	find_len;
	char	*result;

	i = 0;
	result = (char *)str;
	if (!(find_len = ft_strlen(find)))
		return ((char *)result);
	if (ft_strlen(str) < find_len || len < find_len)
		return (NULL);
	while (result[i] && i <= len - find_len)
	{
		j = 0;
		while (find[j] && find[j] == result[i + j])
			j++;
		if (j == find_len)
			return (&result[i]);
		i++;
	}
	return (NULL);
}
