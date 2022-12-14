/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:45:10 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/19 14:08:44 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPE_H
# define FT_PIPE_H
# define MAX_BUF 1024 

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../ft_redirect/ft_redirect.h"
# include "../libft/libft.h"
# include "../minishell.h"
# include "../ft_execve/ft_execve.h"
# include <sys/wait.h>
# include "../ft_sig/ft_sig.h"

int	ft_pipe(char **cmd, t_info *info);

#endif
