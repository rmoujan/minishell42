/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:12:23 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/27 18:53:31 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"
int	my_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void    ft_quote(char *str)
{
	int i;
	int	k;
	int	c;

	i = 0;
	k = 0;
	c = 0;
	write(1,"declare -x ",11);
	while (str[i])
	{
		write(1,&str[i],1);
		if (str[i] == '=' && c == 0)
		{
			k = 1;
			c = 1;
			write(1,"\"",1);
		}
		i++;
	}
	if (k == 1)
    	write(1,"\"",1);
	write(1,"\n",1);
}

void	printlist(t_node *head)
{
	t_node	*temp;

	temp = head;
	if (temp == NULL)
		printf("empty");
	while (temp != NULL)
	{
		ft_quote(temp->data);
		temp = temp->next;
	}
}

void	ft_sort_env(t_node **head, t_cmdfinal **cmd_final)
{
	t_node	*temp;
	t_node	*tmp;
	char	*max;

	temp = *head;
	tmp = *head;
	while (tmp != NULL)
	{
		temp = *head;
		while (temp->next != NULL)
		{
			if (ft_strcmp(temp->data, temp->next->data) > 0)
			{
				max = ft_strdup(temp->data);
				temp->data = temp->next->data;
				temp->next->data = max;
			}
			temp = temp->next;
		}
		tmp = tmp->next;
	}
	*(*cmd_final)->envp = *head;
}

int	valid_var(char *var)
{
	int	i;

	i = 0;
	while (var[i] != '\0' && var[i] != '=')
	{
		if (!(var[i] >= 'A' && var[i] <= 'Z')
			&& !(var[i] >= 'a' && var[i] <= 'z')
			&& !(var[i] >= '0' && var[i] <= '9')
			&& !(var[i] == '_') && !(var[i] == '=') && 
			!((var[i] == '+') && (var[i + 1] == '='))
			 )
			return (1);
		i++;
	}
	if ((var[0] >= '0' && var[0] <= '9'))
		return(1);
	if (!(var[0] >= 'A' && var[0] <= 'Z')
		&& !(var[0] >= 'a' && var[0] <= 'z')
		&& !(var[0] == '_') && (var[0] == '='))
		return (1);
	return (0);
}
int	ft_search_pluse(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			if (str[i - 1] == '+')
				return(0);
		i++;
	}
	return(1);
}
char	*ft_ret_var(char *str) // check if return segfault
{
	int	i;
	int cmp;
	char *ptr;
	
	i = 0;
	cmp = 1;
	while (str[i])
	{
		if (ft_search_pluse(str) == 0)
		{
			if (str[i + 1] == '+')
			{
				break;
			}
		}
		if (str[i + 1] == '=')
		{
			break;
		}
			cmp++;
		i++;
	}
	ptr = malloc(sizeof(char) * cmp + 1);
	i = 0;
	while (cmp > 0)
	{
		ptr[i] = str[i];
		i++;
		cmp--;
	}
	ptr[i] = '\0';
	return(ptr);
}

char	*my_strchr(char *s, int c)
{
	char	cara;
	int		i;
	int		j;
	char	*p1;

	i = 0;
	j = 0;
	p1 = (char *)s;
	cara = (char)c;
	while (p1[i] != '\0')
	{
		if (p1[i] == cara)
		{
			i++;
			return (&p1[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		while (p1[j] != '\0')
			j++;
		return (&p1[j]);
	}
	return (NULL);
}

void	ft_exist_var(t_cmdfinal **cmd_final, char *str)
{
	t_cmdfinal *tmp;
	t_node		*head;
	char	*ptr;
	int	i;
	int	k;
	
	i = 0;
	k = 0;
	tmp = (*cmd_final);
	head = *tmp->envp;
	while  (head)
	{
		if (ft_strcmp(ft_ret_var(head->data), ft_ret_var(str)) == 0)
		{
			if(ft_search_pluse(str) == 0)
			{
				ptr = ft_strdup(my_strchr(str, '='));
				head->data =ft_strjoin(head->data, ptr);
				k=1;
				break;
			}
			if (ft_search(str) == 0)
			{
				free(head->data);
				head->data =  ft_strdup(str);
			}
			k = 1;
			break;
		}
		head = head->next;
	}
	if (k == 0)
	{
		creat_node((*cmd_final)->envp, str);
	}
}

int	check_var(t_cmdfinal **cmd_final)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if ((*cmd_final)->tab[1])// i++ => tab[i]
	{
		while ((*cmd_final)->tab[i])
		{
			if (valid_var((*cmd_final)->tab[i]) == 0)
			{
				ft_exist_var(cmd_final, (*cmd_final)->tab[i]);
			}
			else
			{
				printf("export: `%s': not a valid identifier\n", (*cmd_final)->tab[i]);
				return(1);
			}
			i++;
		}
	}
	return (0);
}

int	my_export(t_cmdfinal **cmd_final)
{
	if (check_var(cmd_final) == 0)
		ft_sort_env((*cmd_final)->envp, cmd_final);// rempalase
	if (!((*cmd_final)->tab[1]))
		printlist(*(*cmd_final)->envp);
		free_tab(cmd_final);
	return(0);
}