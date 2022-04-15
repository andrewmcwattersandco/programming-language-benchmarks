package main

import (
	"encoding/json"
	"fmt"
	"log"
	"os"
	"strings"
)

func main() {
	dir := "companyfacts"
	files, err := os.ReadDir(dir)
	if err != nil {
		log.Fatal(err)
	}

	for _, file := range files {
		if !strings.HasSuffix(file.Name(), ".json") {
			continue
		}

		name := dir + "/" + file.Name()
		file, err := os.Open(name) // For read access.
		if err != nil {
			log.Fatal(err)
		}

		stat, err := file.Stat()
		if err != nil {
			log.Fatal(err)
		}

		jsonBlob := make([]byte, stat.Size())
		_, err = file.Read(jsonBlob)
		if err != nil {
			log.Fatal(err)
		}

		var f interface{}
		err = json.Unmarshal(jsonBlob, &f)
		if err != nil {
			fmt.Println("error:", err)
		}
	}
}
