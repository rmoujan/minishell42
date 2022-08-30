char *expand_dollar(char *s, char **en, char *av[])
{
    int flag;
    t_expand *d;
    
    flag = 0;
    d = (t_expand*) malloc(sizeof(t_expand));
    ft_initializeexpand(d, s, en, av);
    while (s[d->i] != '\0')
    {
        flag_expand(s, d->i, &flag);
        if (s[d->i] == '$')
            chunk0_expand(d);
        if (s[d->i] == '$' && ft_isdigit(s[d->i + 1]) && flag != '\'')
            chunk1_expand(d);
        else if (s[d->i] ==  '$' && ft_isalnum(s[d->i + 1]) && flag != '\'')
            chunk2_expand(d);
        else if (s[d->i] == '$' && s[d->i + 1] == '?' && flag != '\'')
            chunk3_expand(d);
        else if (s[d->i] == '$' && (s[d->i + 1] == '\'' || s[d->i + 1] =='"'))
            d->start = ++d->i;
        else if(s[d->i + 1] == '\0')
         chunk4_expand(d);
        else
            d->i++;
    }
    return d->new;
}


********************
void	ft_free_str(char *str1, char *str2)
{
	free(str1);
	free(str2);
}
void	ft_search_p(t_node *head, char *str, t_vars *x)
{
	x->ptr = ft_strdup(my_strchr(str, '='));
	head->data = ft_strjoin(head->data, x->ptr);
	x->k = 1;
	ft_free_str(x->str1, x->str2);
}

void	ft_free_node(t_node *head, char *str, t_vars *x)
{
	if (ft_search(str) == 0)
	{
		free(head->data);
		head->data = ft_strdup(str);
		ft_free_str(x->str1, x->str2);
	}
	x->k = 1;
}
void	ft_creat(t_vars *x, t_cmdfinal **cmd_final, char *str)
{
	if (x->k == 0)
		creat_node((*cmd_final)->envp, str);
}

void	ft_exist_var(t_cmdfinal **cmd_final, char *str)
{
	t_cmdfinal	*tmp;
	t_node		*head;
	t_vars		x;

	x.i = 0;
	x.k = 0;
	tmp = (*cmd_final);
	head = *tmp->envp;
	while (head)
	{
		x.str1 = ft_ret_var(head->data);
		x.str2 = ft_ret_var(str);
		if (ft_strcmp(x.str1, x.str2) == 0)
		{
			if (ft_search_pluse(str) == 0)
			{
				ft_search_p(head, str, &x);
				break ;
			}
			ft_free_node(head, str, &x);
			break ;
		}
		head = head->next;
		ft_free_str(x.str1, x.str2);
	}
	ft_creat(&x, cmd_final, str);
}