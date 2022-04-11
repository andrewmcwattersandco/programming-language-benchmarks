#include <stddef.h>

#define  NRECORDS  (sizeof records / sizeof records[0])

struct record {
	int id;
};

struct record records[68453040];

int main(int argc, char *argv[])
{
	for (size_t i = 0; i < NRECORDS; i++) {
		struct record r;

		r.id = i;
		records[i] = r;
	}

	return 0;
}
