const std = @import("std");
const allocator = std.heap.page_allocator;

pub fn main() !void {
    const dir = "jsonexamples";

    var directory = std.fs.cwd().openDir(dir, .{ .iterate = true }) catch |err| {
        std.debug.print("json: can't open {s}: {}\n", .{ dir, err });
        return;
    };
    defer directory.close();

    var iterator = directory.iterate();
    while (try iterator.next()) |entry| {
        if (entry.kind != .file or !std.mem.endsWith(u8, entry.name, ".json")) {
            continue;
        }

        const file = directory.openFile(entry.name, .{}) catch |err| {
            std.debug.print("json: can't open {s}: {}\n", .{ entry.name, err });
            continue;
        };
        defer file.close();

        const file_size = try file.getEndPos();
        const contents = try allocator.alloc(u8, file_size);
        defer allocator.free(contents);

        _ = try file.readAll(contents);

        var parsed = std.json.parseFromSlice(std.json.Value, allocator, contents, .{}) catch |err| {
            std.debug.print("json: can't parse {s}: {}\n", .{ entry.name, err });
            continue;
        };
        defer parsed.deinit();
    }
}
