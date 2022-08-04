/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:05:45 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/04 11:27:37 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "../minishell.h"
#include "../libft/libft.h"

static bool	ft_check_env(char *str, char **env)
{
	char const	*del = ft_strchr(str, EQUAL);
	const int	len = del - str;
	char		**ep;
	char		**temp;
	bool		f;

	ep = env;
	f = false;
	while (*ep != 0)
	{
		if (ft_strncmp(*ep, str, len) == 0 && (*ep)[len] == EQUAL)
		{
			temp = ep;
			free(*temp);
			f = true;
			while (*temp != 0)
			{
				*temp = *(temp + 1);
				temp++;
			}
		}
		else
			ep++;
	}
	return (f);
}

static bool	ft_check_str(char *str)
{
	char	*temp;

	if (str == 0 || *str == 0 || *str == EQUAL)
		return (false);
	temp = ft_strchr(str, '=');
	if (temp != 0)
		if (*(temp - 1) != 0 && *(temp + 1) != 0)
			return (true);
	return (false);
}

static char	**ft_dup(char *str, char **env)
{
	char	**ret;
	int		i;

	i = 0;
	while (env[i] != 0)
		i++;
	ret = malloc(sizeof(char *) * (i + 2));
	ft_check_error();
	i = 0;
	while (env[i] != 0)
	{
		ret[i] = ft_strdup(env[i]);
		ft_check_error();
		i++;
	}
	ret[i] = ft_strdup(str);
	ret[i + 1] = 0;
	i = 0;
	while (env[i] != 0)
		free(env[i++]);
	free(env[i]);
	free(env);
	return (ret);
}

bool	ft_export(char *str, t_info *info)
{
	char	**ret;

	if (ft_check_str(str) == false)
		return (false);
	if (ft_check_env(str, info->old_env))
		info->old_env = ft_dup(str, info->old_env);
	else
	{
		ft_check_env(str, info->env);
		info->env = ft_dup(str, info->env);
	}
	return (true);
}
