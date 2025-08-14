#!/usr/bin/env python3
import json
import os


def main():
    directory = "companyfacts"

    try:
        files = os.listdir(directory)
    except OSError as e:
        print(f"json: can't open {directory}: {e}")
        return 1

    for filename in files:
        if not filename.endswith(".json"):
            continue

        filepath = os.path.join(directory, filename)

        try:
            with open(filepath, "r", encoding="utf-8") as f:
                data = f.read()
                json.loads(data)
        except (OSError, json.JSONDecodeError) as e:
            print(f"json: error processing {filepath}: {e}")
            continue

    return 0


if __name__ == "__main__":
    exit(main())
