/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:25:19 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/19 14:13:56 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static char	*ft_value(char *key, char *env)
{
	char	*ret;
	int		len;

	ret = 0;
	len = ft_strlen(key);
	if (ft_strncmp(key, env, len) == 0)
	{
		if (*(env + len) == Equal)
		{
			ret = ft_strdup(env + len + 1);
			ft_check_error();
		}
	}
	return (ret);
}

char	*ft_search_env(char *key, char **env)
{
	char	*value;
	int		i;

	i = 0;
	value = 0;
	while (env[i] != 0)
	{
		value = ft_value(key, env[i]);
		if (value != 0)
			return (value);
		i++;
	}
	return (ft_strdup(""));
}
