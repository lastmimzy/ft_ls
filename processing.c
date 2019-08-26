// http://www.firststeps.ru/linux/r.php?20 - про открытие директорий
// инклуды для чтения содержимого директорий:
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

typedef struct dirent		t_dirent;
typedef struct stat		t_stat;

int         ft_insidedir(const char *content, t_flag *flag)
{
	DIR			*dir;
	t_dirent		*entry;
	t_list			*head;
	char  		        *path;

	head = NULL;
    	if (content)
    	{
        	if ( flag->f_subdir && flag->f_long)
            		printf("\n%s:\n", content);
        	else
            		printf("%s:\n", content);
    	}
    	if (!(dir = opendir(content)))
    	{
		printf("ft_ls: %s: %s\n", content, strerror(errno));
	    	return(errno);
    	}
    	while ((entry = readdir(dir)))
    	{
		path = ft_strnew(ft_strlen(entry->d_name) + 1);  
	    	strncpy(path, entry->d_name, ft_strlen(entry->d_name));
		if (flag->f_all || entry->d_name[0] != '.')
            		ft_lstadd(&head, ft_lstnew(path, ft_strlen(path) + 1));
    	}
    	closedir(dir) //if -1 => error
    	ft_total();
    	ft_display(....); 
    	if (flag->f_subdir)
		ft_processing(flag, ft_sorting(head, flag)); //files, then dir
    	return (0);
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
