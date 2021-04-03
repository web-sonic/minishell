/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:11:33 by sgath             #+#    #+#             */
/*   Updated: 2021/04/03 16:46:03 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	line_split(t_env *arr_arg, char *line)
{
	int	i;

	i = 1;
	if (!ft_strchr(line, '='))
	{
		arr_arg->val = ft_strdup(line);
		arr_arg->arg = NULL;
		arr_arg->equally = 0;
	}
	else
	{
		arr_arg->val = ft_substr(line, 0, super_strlen(0, '=', line));
		while (line[i] != '=')
			i++;
		arr_arg->arg = ft_substr(line, i + 1, super_strlen(i + 1, '\0', line));
		arr_arg->equally = 1;
	}
}

void
	free_env(void *env)
{
	t_env	*envt;

	envt = env;
	if (envt->arg)
		free(envt->arg);
	free(envt->val);
	free(envt);
}

void
	*return_content(void *content)
{
	return (content);
}

char
	*ft_getenv(const char *name, t_list *envlst)
{
	int		len;
	t_env	*envt;

	len = ft_strlen(name);
	while (envlst)
	{
		envt = envlst->content;
		if (!ft_strncmp(name, envt->val, len + 1))
		{
			if (envt->arg)
				return (ft_strdup(envt->arg));
			else
				return (ft_calloc(sizeof(char), 1));
		}
		envlst = envlst->next;
	}
	return (ft_calloc(sizeof(char), 1));
}
