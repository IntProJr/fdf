/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_mass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:31:30 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/22 14:31:30 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_clear_mass(char ***mas)
{
	char	**s;

	s = *mas;
	while (*s)
	{
		if (*s)
		{
			free(*s);
			*s = NULL;
		}
		s++;
	}
	free(*mas);
}
