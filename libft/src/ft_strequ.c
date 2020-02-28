/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:15:03 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/28 15:54:10 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	else if (ft_strlen((char*)s1) != ft_strlen((char*)s2))
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((s1[i] == '\0' && s2[i] == '\0') ? 1 : 0);
}
