//1.   http://man7.org/linux/man-pages/man3/getpwnam.3.html
//2.   https://stackoverflow.com/questions/43173142/getpwuid-and-getgrgid-causes-segfault-when-user-does-not-exist-for-given-uid

#include <sys/types.h>
#include <pwd.h>

typedef struct stat		t_stat;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

static void		ft_showmode(mode_t st_mode) //type and permission
{
    //ft_show_type
    ft_putchar((st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((st_mode & S_IXOTH) ? 'x' : '-');
}

static int		ft_display_l(const char *content)
{
	t_stat		stat;
	t_passwd	*pwd;
	t_group		*grp;
	//time

	if (lstat(content, &stat) < 0)
	{
        printf("ft_ls: %s: %s\n", head->content, strerror(errno));
        return (1);
    }
	pwd = getpwuid(stat.st_uid); // get user ID
	grp = getgrgid(stat.st_gid); //get group ID
	//time = ft_showt(////);
	ft_showmode(stat.st_mode);
	ft_printf(" % % % % % ",
		stat.st_nlink, pwd->pw_name, grp->gr_name, stat.st_size, /time/); //st_size выводится по-другому при другом mode (видео ft_ls)
//	ft_showname(...) может, добавить цвет?
	return (0);
}

int				ft_display(t_flag *flag, t_list *head)
{
	while (head)
	{
		if (flag->f_long)
			(void)ft_display_l(head->content);
		if ()
		.
		.
		.
		head = head->next;
	}
	return (0);
}
