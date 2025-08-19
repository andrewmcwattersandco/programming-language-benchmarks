#include <dirent.h>
#if defined(__linux__)
#include <linux/limits.h>
#endif
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "cJSON.h"

int main()
{
    const char dir[] = "companyfacts";
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir (dir)) == NULL) {
        fprintf(stderr, "json: can′t open %s\n", dir);
        return 1;
    }
    while ((dp = readdir (dfd)) != NULL) {
        char name[PATH_MAX];
        struct stat stbuf;
        off_t size;
        FILE *fp;
        char *string;
        cJSON *json;

        char *ext = strrchr(dp->d_name, '.');
        if (ext == NULL || strcmp(ext, ".json") != 0)
            continue;

        if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(name)) {
            fprintf(stderr, "json: name %s/%s too long\n",
                dir, dp->d_name);
            continue;
        } else {
            snprintf(name, sizeof(name), "%s/%s", dir, dp->d_name);
        }

        if (stat(name, &stbuf) == -1) {
            fprintf(stderr, "json: can′t access %s\n", name);
            continue;
        }
        size = stbuf.st_size;

        if ((fp = fopen(name, "r")) == NULL) {
            printf("json: can′t open %s\n", name);
            continue;
        }

        if ((string = malloc(size)) == NULL)
            continue;

        if (fread(string, size, 1, fp) != 1
            && (feof(fp) != 0 || ferror(fp) != 0)) {
            printf("json: can′t read %s\n", name);
            free(string);
            fclose(fp);
            continue;
        }

        json = cJSON_Parse(string);

        cJSON_Delete(json);
        free(string);
        fclose(fp);
    }
    closedir(dfd);
    return 0;
}
