#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

size_t getFileSize(const char* filename)
{
struct stat st;
if(stat(filename, &st) != 0)
	{
	return 0;
	}
return st.st_size;
}

int main(int argc, char **argv)
{
FILE *fp;
char c;
int size;

fp = fopen(argv[1], "r");

if (fp)
	{
	while ((c = getc(fp)) != EOF)
	putchar(c);

	printf("\n");
	size = getFileSize(argv[1]);
	printf ("%20s has %d bytes.\n", argv[1], size);
	}
else
printf("Please, provide a valid file name.\n");

fclose(fp);
}
