package main

import (
	"encoding/json"
	"fmt"
	"os"
	"strings"
)

func main() {
	dir := "companyfacts"
	files, err := os.ReadDir(dir)
	if err != nil {
		fmt.Fprintf(os.Stderr, "json: can't open %s: %v\n", dir, err)
		os.Exit(1)
	}

	for _, file := range files {
		if !strings.HasSuffix(file.Name(), ".json") {
			continue
		}

		name := dir + "/" + file.Name()
		jsonFile, err := os.Open(name) // For read access.
		if err != nil {
			fmt.Fprintf(os.Stderr, "json: can't open %s: %v\n", name, err)
			continue
		}
		defer jsonFile.Close()

		stat, err := jsonFile.Stat()
		if err != nil {
			fmt.Fprintf(os.Stderr, "json: can't stat %s: %v\n", name, err)
			continue
		}

		jsonBlob := make([]byte, stat.Size())
		_, err = jsonFile.Read(jsonBlob)
		if err != nil {
			fmt.Fprintf(os.Stderr, "json: can't read %s: %v\n", name, err)
			continue
		}

		var f interface{}
		err = json.Unmarshal(jsonBlob, &f)
		if err != nil {
			fmt.Fprintf(os.Stderr, "json: can't parse %s: %v\n", name, err)
			continue
		}
	}
}
