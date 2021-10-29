#include <fcntl.h>
#include <unistd.h>

void ft_putstr(char *str, int output)
{
	while(*str)
		write(output, str++, 1);
}

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		ft_putstr("File name missing.", 2);
		goto error;
	}
	else if(2 < argc)
	{
		ft_putstr("Too many arguments.", 2);
		goto error;
	}

	int fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		ft_putstr("Cannot read file.", 2);
		goto error;
	}
	char buf[255];
	int bytes_read;
	while(bytes_read = read(fd, buf, 255))
		write(1, buf, bytes_read);
	
	close(fd);

	return 0;
error:
	return 1;
}