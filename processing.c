int			ft_insidedir(const char *content, t_flag *flag)
{
    .
    .
}


static int	ft_processing_files(t_flag *flag, t_list *head)
{
	t_stat	stat;
	t_list	*onlyf; //связный список ТОЛЬКО из файлов

	onlyf = NULL;
	while (head)
	{
		if (lstat(head->content, &stat) < 0)
		{
		    printf("ft_ls: %s: %s\n", head->content, strerror(errno));
			head = head->next;
			continue ;
		}
		if (!S_ISDIR(stat.st_mode))
		{
		    printf("%s this is NOT dir!\n", head->content); //del
			ft_lstadd(&onlyf, ft_lstnew(head->content, ft_strlen(head->content) + 1));
		}
		head = head->next;
	}
	if (onlyf)
//		ft_display(....);
//		ft_putchar('\n'); ?
	return (0);
}

int            ft_processing_dir(t_flag *flag, t_list *head)
{
    t_stat        stat;

    while (head)
    {
        if (lstat(head->content, &stat) < 0)
        {
            printf("ft_ls: %s: %s\n", head->content, strerror(errno));
            return (1);
        }
        if (S_ISDIR(stat.st_mode)) // + проверка на валидность
            ft_insidedir(head->content, flag); //открытие директорий
        head = head->next;
    }
    return (0);
}
