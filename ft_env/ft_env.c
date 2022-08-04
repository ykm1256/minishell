/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:16:00 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/04 11:28:58 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../minishell.h"

void	ft_env(t_info *info)
{
	int		i;

	i = 0;
	while (info->old_env[i] != 0)
	{
		printf("%s\n", info->old_env[i]);
		++i;
	}
	i = 0;
	while (info->env[i] != 0)
	{
		printf("%s\n", info->env[i]);
		++i;
	}
}
