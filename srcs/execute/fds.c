/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 05:32:18 by ctragula          #+#    #+#             */
/*   Updated: 2021/04/06 14:04:19 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void
	set_fds(t_fdstruct *fds, t_cmd *cmd, t_bool last_cmd)
{
	int	fdpipe[2];

	if (cmd->is_fdin)
		dup2(cmd->fdin, 0);
	else
		dup2(fds->fdin, 0);
	close(fds->fdin);
	if (last_cmd)
		(cmd->is_fdout) ? fds->fdout = dup(cmd->fdout) :
			(fds->fdout = dup(fds->tmpout));
	else
	{
		pipe(fdpipe);
		fds->fdin = fdpipe[0];
		fds->fdout = fdpipe[1];
	}
	(!cmd->is_fdout) ? dup2(fds->fdout, 1) : dup2(cmd->fdout, 1);
	if (cmd->fdout >= 0)
		close(cmd->fdout);
	if (cmd->fdin >= 0)
		close(cmd->fdin);
	close(fds->fdout);
}

void
	init_fd(t_fdstruct *fds)
{
	fds->tmpin = dup(0);
	fds->tmpout = dup(1);
	fds->fdin = dup(fds->tmpin);
	fds->fdout = dup(fds->tmpout);
}

void
	unset_fd(t_fdstruct *fds)
{
	dup2(fds->tmpin, 0);
	dup2(fds->tmpout, 1);
	close(fds->tmpin);
	close(fds->tmpout);
	close(fds->fdin);
	close(fds->fdout);
}

int
	validate_redirects(t_cmd *cmd)
{
	if (cmd->is_fdin || cmd->is_fdout)
		return (0);
	return (1);
}
