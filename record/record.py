#!/usr/bin/env python3
class Record:
    def __init__(self, record_id):
        self.id = record_id


def main():
    records = []

    for i in range(67108864):
        r = Record(i)
        records.append(r)


if __name__ == "__main__":
    main()
