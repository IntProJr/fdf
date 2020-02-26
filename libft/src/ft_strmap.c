/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:40:34 by lrosalee          #+#    #+#             */
/*   Updated: 2019/08/31 14:01:42 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	size_t	i;

	result = NULL;
	if (s && f && (result = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (s[i])
		{
			result[i] = f(s[i]);
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
