package main

func main() {
	records := make([]Record, 16777216)

	for i := 0; i < len(records); i++ {
		r := Record{id: i}
		records[i] = r
	}
}

type Record struct {
	id int
}
