#include <stddef.h>

#define  NRECORDS  (sizeof records / sizeof records[0])

class Record {
public:
     void set_id(int i) { id = i; }
private:
     int id;       // the id
};

// Excerpt From
// The C++ Programming Language, Fourth Edition
// Bjarne Stroustrup
// This material may be protected by copyright.

Record records[68453040];

int main(int argc, char *argv[])
{
	for (size_t i = 0; i < NRECORDS; i++) {
		Record r;

		r.set_id(i);
		records[i] = r;
	}

	return 0;
}
