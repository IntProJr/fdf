/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:49:41 by lrosalee          #+#    #+#             */
/*   Updated: 2019/08/31 14:01:42 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_number_word(char const *s, char c)
{
	int	i;
	int	count;

	if (s[0] == '\0')
		return (0);
	count = 0;
	if (s[0] != c)
		count++;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int		ft_get_len_word(const char *s, char c)
{
	int len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static char		**ft_clean(char **ret, int len)
{
	int i;

	i = 0;
	while (i < len)
		free(ret[i++]);
	free(ret);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		word_number;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	word_number = ft_number_word(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (word_number + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_number)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		tab[i] = ft_strsub(s, j, ft_get_len_word(s + j, c));
		if (tab[i] == NULL)
			return (ft_clean(tab, i));
		while (s[j] != '\0' && s[j] != c)
			j++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
