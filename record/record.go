package main

func main() {
	records := make([]Record, 68453040);

	for i := 0; i < len(records); i++ {
		r := Record{}

		r.id = i
		records[i] = r;
	}
}

type Record struct {
	id int
}
