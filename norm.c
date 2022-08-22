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