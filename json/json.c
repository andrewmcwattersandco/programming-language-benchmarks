#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/yyjson.h"

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dp;

	if ((dir = opendir ("companyfacts")) == NULL) {
		perror ("Cannot open companyfacts");
		exit (1);
	}

	while ((dp = readdir (dir)) != NULL) {
		char pathname[PATH_MAX];
		FILE *fp;
		long size;
		char *json;
		yyjson_doc *doc;

		if (strcmp(strrchr(dp->d_name, '.') + 1, "json") != 0)
			continue;

		strlcpy(pathname, "companyfacts/", sizeof pathname);
		strlcat(pathname, dp->d_name, sizeof pathname);

		if ((fp = fopen(pathname, "r")) == NULL)
			continue;

		if (fseek(fp, 0L, SEEK_END) == 0) {
			if ((size = ftell(fp)) == -1L) {
				perror ("ftell");
				exit (1);
			}
		} else {
			perror ("fseek");
			exit (1);
		}
		rewind(fp);

		json = malloc(size);
		if (fread(json, size, 1, fp) < 1) {
			perror ("fread");
			exit (1);
		}

		/* Read JSON */
		doc = yyjson_read(json, size, 0);

		/* Free the doc */
		yyjson_doc_free(doc);
		free(json);
		fclose(fp);
	}

	return 0;
}
