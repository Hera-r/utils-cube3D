#include <stdio.h>

# define SUCCESS	0
# define FAIL		1

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (((unsigned char)s1[i] == (unsigned char)s2[i])
		&& s1[i] && s2[i] && n)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (SUCCESS);
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


int check_file_extension(char *file_name)
{
	int		i;
	int		len;
	char	*ext;

	i = 0;
	len = ft_strlen(file_name);
	ext = ".cub";
	if (len < 5 || ft_strncmp(file_name + (len - 4), ext, 4) != 0)
	{
		printf("Error\nInvalid File Extension\n");
		return (FAIL);
	}
	return (SUCCESS);
}


int	main(int argc, char *argv[])
{
	if (check_file_extension(argv[1]) == 1)
		return (FAIL);

	return (0);
}
