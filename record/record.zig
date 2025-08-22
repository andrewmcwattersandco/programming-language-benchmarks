const std = @import("std");
const allocator = std.heap.page_allocator;

const NRECORDS = 16777216;

const Record = struct {
    id: i32,
};

pub fn main() !void {
    const records = try allocator.alloc(Record, NRECORDS);
    defer allocator.free(records);

    for (0..NRECORDS) |i| {
        const r = Record{ .id = @intCast(i) };
        records[i] = r;
    }
}
