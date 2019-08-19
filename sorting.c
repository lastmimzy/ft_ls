# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef unsigned char    t_byte;

typedef    struct        s_list
{
    void            *content;
    size_t           content_size;
    struct s_list    *next;
}                         t_list;

static t_list    *ft_sorting_ascii(t_list *head)
{
    t_list    *str1;
    t_list    *str2;  
    char      *temp;

    str1 = head;
    while (str1)
    {
        str2 = str1->next;
        while (str2)
        {
            if (ft_strcmp(str1->content, str2->content) > 0)
            {
              temp = str1->content;
              str1->content = str2->content;
              str2->content = temp;
            }
            str2 = str2->next;
        }
        str1 = str1->next;
    }
    return (head);
}


t_list			*ft_sorting(t_list *head, t_flag *flag)
{
//	if (flag->f_time)
//		head = ft_sorting_t(); 
//	else
	  	head = ft_sorting_ascii(head);
//	if (flag->f_rev)
//		head = ft_sorting_r();
	return (head);
}

static int    ft_printed(int ac, char **av, int firstarg, t_flag *flag)
{
    t_list    *head;

    head = NULL;
    if(firstarg < ac)
    {
        while (firstarg < ac)
        {
            if (!head)
                head = ft_lstnew(av[firstarg], ft_strlen(av[firstarg]) + 1);
            else
                ft_lstadd(&head,
                    ft_lstnew(av[firstarg], ft_strlen(av[firstarg]) + 1));
            firstarg++;
        }
    }
//    else
//        head = ft_lstnew(//empty);
    ft_sorting(head, flag);
//  return(processing());
}
