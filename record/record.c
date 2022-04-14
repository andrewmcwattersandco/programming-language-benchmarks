#include <stddef.h>

#define  NRECORDS  (sizeof records / sizeof records[0])

struct record {
    int id;
};

struct record records[112813858];

int main()
{
    int i;

    for (i = 0; i < NRECORDS; i++) {
        struct record r;

        r.id = i;
        records[i] = r;
    }

    return 0;
}
