#include <stddef.h>
#include <memory>

#define  NRECORDS  8388608

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

int main(int argc, char *argv[])
{
	auto records = std::make_unique<Record[]>(NRECORDS);
	
	for (size_t i = 0; i < NRECORDS; i++) {
		Record r;

		r.set_id(i);
		records[i] = r;
	}

	return 0;
}
