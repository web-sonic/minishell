/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:47:07 by ctragula          #+#    #+#             */
/*   Updated: 2021/03/16 16:01:39 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



/* 
** @params: int argc: 
**			int argv:
** Имитирует работу шелла
** @return char *line: введенная строка в терминале
*/
void
	shell_loop(int argc, char **argv)
{
	char *line;
	t_list table;

	while (STATUS)
	{
		line = readline();
//		table = parser(line);
//		execute(table);
	}

}