#include "includes/libft/libft.h"
#include "bonus/pipex_bonus.h"
#include "bonus/get_next_line_bonus.h"
#include <stdio.h>

char	**my_split(char *str)
{
	char	*tmp;
	char	**res;
	int		i;
	
	tmp = str;// hello world
	while (*tmp)
	{
		while (!(*tmp == '\'' || *tmp == '\"') && *tmp)
			tmp++;
		while ((*tmp == '\'' || *tmp == '\"') && *tmp)
			tmp++;
		while (!(*tmp == '\'' || *tmp == '\"') && *tmp)
		{
			if (*tmp == ' ')
				*tmp = 127;
			tmp++;
		}
	}
	res = ft_split(str, ' ');
	i = -1;
	while (res[++i])
		while (*res[i])
			if (*res[i]++ == 127)
				*res[i] = ' ';
	return (res);
}

int main()
{
    int  i = 0;
    char *s = "hello world";
    char **res = my_split(s);
    while (res[i])
    {
        printf(";;;;%s;;;;\n", res[i]);
        i++;
    }
    return 0 ;
}