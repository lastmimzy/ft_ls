# include <stdio.h>
# include <stdlib.h>
# include <string.h>


static int    ft_error(int i)
{
    if (i)
        printf("ft_ls: illegal option -- %c\n", i);
    printf("usage: ./ft_ls [-1GRalrt] [file ...]\n");
    //зафришить флаги
    //разная ошибка- дописать для "--" и для двойных "GG"
    return (1);
}


typedef struct    s_flag
{
    int            f_subdir;  //R
    int            f_all;     //a
    int            f_long;    //l
    int            f_rev;     //r
    int            f_time;    //t
    int            f_color;   //G
    int            f_onef;    //1
    int            f_dironly;  //d
}                         t_flag;

char    *ft_strchr(const char *str, int c)
{
    while (*str)
    {
        if ((char)c == *str)
            return ((char*)str);
        str++;
    }
    if ((char)c == *str)
        return ((char*)str);
    return (NULL);
}

static void    ft_zeroflag(t_flag *flag)
{
       flag->f_subdir = 0;   //R
       flag->f_all = 0; //a
       flag->f_long = 0;   //l
       flag->f_rev = 0;    //r
       flag->f_time = 0;   //t
       flag->f_color = 0;   //G
       flag->f_onef = 0;  //1
       flag->f_dironly = 0;  //d
}

int        ft_getone(int ac, char **av,
                                    const char *controlstr, int *firstarg)
{
    static int    letter = 1;

  //  printf("%c", argv[*firstarg][1]);  DEL
    if (*firstarg < ac && av[*firstarg][0] == '-')
    {
        if (letter != 1 && !av[*firstarg][letter])
        {
              letter = 1;
              (*firstarg)++;
              return (ft_getone(ac, av, controlstr, firstarg));
        }
        ft_strchr(controlstr, av[*firstarg][letter]);
        printf("%c", av[*firstarg][letter]);//del .check
        return (av[*firstarg][letter++]);
    }
    return (-1);
}

static int    ft_parseflag(int ac, char **av, int *firstarg, t_flag *flag)
{
    int        c;

    ft_zeroflag(flag);
    while ((c = ft_getone(ac, av, "RalrtG1d", firstarg)) > 0)
    {
        if (c == 'R')
            flag->f_subdir = ((flag->f_subdir == 0) ? 1: ft_error(c));
        else if (c == 'a')
            flag->f_all = ((flag->f_all == 0) ? 1: ft_error(c));
        else if (c == 'l')
            flag->f_long = ((flag->f_long == 0) ? 1: ft_error(c));
        else if (c == 'r')
            flag->f_rev = ((flag->f_rev == 0) ? 1: ft_error(c));
        else if (c == 't')
            flag->f_time = ((flag->f_time == 0) ? 1: ft_error(c));
        else if (c == 'G')
            flag->f_color = ((flag->f_color == 0) ? 1: ft_error(c));
        else if (c == '1')
            flag->f_onef = ((flag->f_onef == 0) ? 1: ft_error(c));
        else if (c == 'd')
            flag->f_dironly = ((flag->f_dironly == 0) ? 1: ft_error(c));
        else
            return (ft_error(c));
    }
    return (0);
}

int            main()
{
    t_flag        flag;
    int           firstarg;
    int           ac=3;
    char          *av[3];

    av[0]="wred";
    av[1]="-Rl1";
    av[2]="-Gk";

    firstarg = 1;
    ft_parseflag(ac, av, &firstarg, &flag);
   // return (ft_printed(ac, av, firstarg, &flag));
    return (0);
}
