#include <stdio.h>
#include <fcntl.h>

#define SUCCESS		0
#define FAIL		1


int	check_file_access(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDWR);
	if (fd == -1)
	{
		perror("Error");
		return (FAIL);
	}
	return (SUCCESS);
}


int	main(int argc, char *argv[])
{
	if (check_file_access(argv[1]) == FAIL)
		return (FAIL);

	return (0);
}
