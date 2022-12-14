/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:14:07 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/19 14:14:44 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static int	ft_is_pipe(const char *str)
{
	if (ft_strncmp(str, PIPE, 2) == 0)
		return (0);
	else
		return (1);
}

static int	ft_is_red(const char *str)
{
	if (ft_strncmp(str, OUTPUT, 2) == 0)
		return (0);
	else if (ft_strncmp(str, D_OUTPUT, 3) == 0)
		return (0);
	else if (ft_strncmp(str, D_INPUT, 3) == 0)
		return (0);
	else if (ft_strncmp(str, INPUT, 2) == 0)
		return (0);
	else
		return (1);
}

static int	ft_check_pipe(char **parse)
{
	int	i;

	i = 0;
	while (parse[i] != 0)
	{
		if (ft_is_pipe(parse[i]) == 0)
		{
			if (i == 0)
				return (1);
			else
				if (ft_is_pipe(parse[i - 1]) == 0)
					return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_check_red(char **parse)
{
	int	i;

	i = 0;
	while (parse[i] != 0)
	{
		if (ft_is_red(parse[i]) == 0)
		{
			if (parse[i + 1] == 0)
				return (1);
			else if (ft_is_red(parse[i + 1]) == 0)
				return (1);
			else if (ft_is_pipe(parse[i + 1]) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_parse_syntax(char **parse)
{
	if (ft_check_pipe(parse) == 1)
		return (1);
	else if (ft_check_red(parse) == 1)
		return (1);
	else
		return (0);
}
