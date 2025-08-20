#!/usr/bin/env python3
import os

src = __file__
dst = src + ".orig"

os.rename(src, dst)

try:
    import json as json_module
finally:
    os.rename(dst, src)


def main():
    directory = "jsonexamples"

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
                json_module.loads(data)
        except (OSError, json_module.JSONDecodeError) as e:
            print(f"json: error processing {filepath}: {e}")
            continue

    return 0


if __name__ == "__main__":
    exit(main())
