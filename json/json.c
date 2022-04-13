#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fext(const char *name)
{
	return strrchr(name, '.') + 1;
}

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dp;

	if ((dir = opendir ("companyfacts")) == NULL) {
		perror ("Cannot open companyfacts");
		exit (1);
	}

	while ((dp = readdir (dir)) != NULL) {
		if (strcmp(fext(dp->d_name), "json") == 0) {
			printf("%s\n", dp->d_name);
		}
	}

	return 0;
}
