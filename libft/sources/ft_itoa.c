/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:03:49 by lrosalee          #+#    #+#             */
/*   Updated: 2019/08/31 14:01:42 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nbr;

	nbr = (n > 0) ? n : -n;
	i = (n < 0) ? 2 : 1;
	while (nbr /= 10)
		i++;
	nbr = (n > 0) ? n : -n;
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[0] = (n < 0) ? '-' : '0';
	while (nbr)
	{
		str[--i] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (str);
}
