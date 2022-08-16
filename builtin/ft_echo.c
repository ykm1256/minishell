/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:10:36 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/16 15:19:00 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_echo(char *str, int offset)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s", str);
		if (str[i + 1])
			printf(" ");
	}

	if (offset)
		printf("\n");
}
