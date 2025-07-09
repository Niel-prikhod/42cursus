#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int	fd = open("gnl.txt", O_RDONLY);
	char	buf[100];
	size_t	buffer_size = 1;
	int i = 0;
	while (buf[i] != '\0')
	{
		int	size = read(fd, buf, buffer_size);
		printf("read: %i bytes\n%s\n", size, buf);
		i++;
	}
	close(fd);
	return 1;
}
