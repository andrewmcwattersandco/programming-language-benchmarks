#!/usr/bin/env python3
class Record:
    def __init__(self, record_id):
        self.id = record_id


def main():
    records = []

    for i in range(16777216):
        r = Record(i)
        records.append(r)


if __name__ == "__main__":
    main()
