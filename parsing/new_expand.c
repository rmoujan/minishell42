/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:01:07 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/30 15:26:36 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"
//still need norm 29/08/20222
char	*expand_dollar(char *s, char **en, char *av[])
{
	t_expand	*d;
	int			flag;

	flag = 0;
	d = (t_expand *) malloc(sizeof(t_expand));
	initial_expand(d, s, en, av);
	while (s[d->i] != '\0')
	{
		flag_expand(s, d->i, &flag);
		if (s[d->i] == '$')
			chunk0_expand(d);
		if (s[d->i] == '$' && ft_isdigit(s[d->i + 1]) && flag != '\'')
			chunk1_expand(d);
		else if (s[d->i] == '$' && ft_isalnum(s[d->i + 1]) && flag != '\'')
			chunk2_expand(d);
		else if (s[d->i] == '$' && s[d->i + 1] == '?' && flag != '\'')
			chunk3_expand(d);
		else if (s[d->i + 1] == '\0')
			chunk4_expand(d);
		else
			d->i++;
	}
	return (chunk5_expand(d));
}

int	check_dollar(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			counter++;
		i++;
	}
	return (counter);
}

char	*change_emptystr(char **str)
{
	char	*ptr;

	free(*str);
	ptr = ft_itoa(-1);
	return (ptr);
}

//22 lines
void	expand_cmd(char ***tab, char **envp, char *argv[])
{
	char	**cmd;
	char	*ptr;
	int		i;

	i = 0;
	cmd = *tab;
	while (cmd[i] != '\0')
	{
		if (check_dollar(cmd[i]) != 0)
		{
			ptr = cmd[i];
			cmd[i] = expand_dollar(cmd[i], envp, argv);
			if (cmd[i][0] == '\0')
				cmd[i] = change_emptystr(&cmd[i]);
			else if (cmd[i][0] == '"' && cmd[i][1] == '"' && cmd[i][2] == '\0')
				cmd[i] = change_emptystr(&cmd[i]);
			else if (cmd[i][0] == '\'' && cmd[i][1] == '\''
				&& cmd[i][2] == '\0')
			{
				cmd[i] = change_emptystr(&cmd[i]);
			}
			free(ptr);
		}
		i++;
	}
}

void	ft_expand(t_cmdfinal *cmd, char **envp, char *argv[])
{
	t_cmdfinal	*tmp;
	t_files		*save;
	char		*ptr;

	tmp = cmd;
	while (tmp)
	{
		save = tmp->file;
		while (tmp->file)
		{
			if (tmp->file->id != 3)
			{
				ptr = tmp->file->name;
				tmp->file->name = expand_dollar(tmp->file->name, envp, argv);
				free(ptr);
			}
			tmp->file = tmp->file->next;
		}
		expand_cmd(&tmp->tab, envp, argv);
		tmp->file = save;
		tmp = tmp->next;
	}
}
