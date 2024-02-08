#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL	1

static int	element_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
			i++;
		}
	}
	return (count);
}

static char	*strdup_index(char const *s, int st, int end)
{
	char	*newstr;
	int		size;
	int		i;

	size = (end - st) + 1;
	i = 0;
	newstr = malloc(size * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (st < end)
	{
		newstr[i] = s[st];
		i++;
		st++;
	}
	newstr[i] = '\0';
	return (newstr);
}

static char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
	i++;
	}
	free(tab);
	return (0);
}

static char	**append_list(char const *s, char c, char **tab)
{
	int	i;
	int	index;
	int	start;

	i = 0;
	start = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		i++;
		if (s[i] && s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
			i++;
			tab[index] = strdup_index(s, start, i);
			if (!tab[index])
				return (free_tab(tab));
			index++;
		}
	}
	tab[index] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		size;

	if (!s)
		return (NULL);
	size = element_count(s, c);
	tab = malloc((size + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	append_list(s, c, tab);
	return (tab);
}

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


static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	validate_color_code(int color_code)
{
	if (color_code < 0 || color_code > 255)
		return (FAIL);
	return (SUCCESS);
}


int	check_numb_color(const char *nptr)
{
	char	**tab;
	int		i;
	int		n;
	int		j;

	i = 0;
	n = 0;
	j = 0;
	tab = ft_split(nptr, ',');
	if (!tab)
		return (FAIL);
	if (ft_tablen(tab) > 3)
		return (free_tab(tab), FAIL);
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (!ft_isdigit(tab[j][i]))
				return (free_tab(tab), FAIL);
			n = n * 10 + (tab[j][i] - '0');
		i++;
		}
		if (validate_color_code(n) == FAIL)
			return (free_tab(tab), FAIL);
	j++;
	i = 0;
	n = 0;
	}
	return (free_tab(tab), SUCCESS);
}

int	is_valid_color_format(char *str, char **tab)
{
	int	tab_len;

	tab_len = ft_tablen(tab);
	if (tab_len < 2 || ft_strcmp(tab[0], str) != 0)
		return (FAIL);
	if (check_numb_color(tab[1]) == FAIL)
		return (FAIL);
	return (SUCCESS);
}


int main()
{
	char *tableau[] = {"F", "226,100,0", NULL};

	if (is_valid_color_format("F", tableau) == FAIL)
	{
		printf("ERROR FORMAT\n");
		return (FAIL);
	}
	printf("ALL GOOD\n");
	return (0);
}


//F 220,100,0