#include <stdio.h>

#define SUCCESS 0
#define FAIL    1

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (((unsigned char)s1[i] == (unsigned char)s2[i])
		&& s1[i] && s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

//dep : ft_strcmp, tab_len
int	is_valid_texture_direction(char *str, char **tab)
{
	int	tab_len;

	tab_len = ft_tablen(tab);
	if (tab_len < 2 || ft_strcmp(tab[0], str) != 0 || (tab[1][0] != '.' || tab[1][1] != '/'))
		return (FAIL);
	return (SUCCESS);
}

int	main()
{
	char *tableau[] = {"NO", "./path_texture_no", NULL};
	// char *tableau[] = {"NO", NULL};

	if (is_valid_texture_direction("NO", tableau) == 1)
	{
		printf("ERROR\n");
		return (0);
	}
	printf("ALL GOOD\n");
	return (0);

}