 else if (str[i] ==  '$' && ft_isalnum(str[i + 1]) && flag != '\'')
        {
            start = ++i;
            while (str[i] != '\0' && (ft_isalnum(str[i]) || str[i] == '_'))
                i++;
            ptr = ft_substr(str, start, ((i) - start));
            ptr = get_value(ft_substr(str, start, ((i) - start)), envp);
            new = ft_strjoin(new, get_value(ft_substr(str, start, ((i) - start)), envp));
            start = i;
        }