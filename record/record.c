#include <stddef.h>
#include <stdlib.h>

#define  NRECORDS  112813858

struct record {
    int id;
};

int main(int argc, char *argv[])
{
    int i;
    struct record *records;

    records = malloc(NRECORDS * sizeof(struct record));
    if (records == NULL) {
        return 1;
    }

    for (i = 0; i < NRECORDS; i++) {
        struct record r;

        r.id = i;
        records[i] = r;
    }

    free(records);
    return 0;
}
