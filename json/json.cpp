#include <dirent.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/stat.h>
#include "simdjson.h"
using namespace std;
using namespace simdjson;

int main()
{
    string dir = "jsonexamples";
    struct dirent *dp;
    DIR *dfd;
    ondemand::parser parser;

    if ((dfd = opendir (dir.c_str())) == nullptr) {
        cerr << "json: can′t open " << dir << endl;
        return 1;
    }
    while ((dp = readdir (dfd)) != nullptr) {
        string name = dir;
        struct stat stbuf;
        off_t size;
        FILE *fp;
        string str;
        ondemand::document doc;

        if (strcmp(strrchr(dp->d_name, '.'), ".json") != 0)
            continue;

        if (dir.size()+strlen(dp->d_name)+2 > PATH_MAX) {
            cerr << "json: name " << dir << '/' << dp->d_name << " too long\n"
                 << endl;
            continue;
        } else {
            name = name + '/' + dp->d_name;
        }

        if (stat(name.c_str(), &stbuf) == -1) {
            cerr << "json: can′t access " << name << endl;
            continue;
        }
        size = stbuf.st_size;

        if ((fp = fopen(name.c_str(), "r")) == nullptr) {
            cout << "json: can′t open " << name << endl;
            continue;
        }

        size_t padded_size = size+SIMDJSON_PADDING;
        str.resize(padded_size);

        if (fread(&str[0], size, 1, fp) != 1
            && (feof(fp) != 0 || ferror(fp) != 0)) {
            cout << "json: can′t read " << name << endl;
            fclose(fp);
            continue;
        }
        str.resize(size);

        padded_string json(str);
        doc = parser.iterate(json);

        fclose(fp);
    }
    closedir(dfd);
    return 0;
}
