use std::fs;

fn main() {
    let dir = "jsonexamples";
    let entries = match fs::read_dir(dir) {
        Ok(entries) => entries,
        Err(e) => {
            eprintln!("json: can't open {}: {}", dir, e);
            std::process::exit(1);
        }
    };

    for entry in entries {
        let entry = match entry {
            Ok(entry) => entry,
            Err(e) => {
                eprintln!("json: error reading directory entry: {}", e);
                continue;
            }
        };

        let path = entry.path();
        if !path.extension().map_or(false, |ext| ext == "json") {
            continue;
        }

        let json_content = match fs::read_to_string(&path) {
            Ok(content) => content,
            Err(e) => {
                eprintln!("json: can't read {}: {}", path.display(), e);
                continue;
            }
        };

        match serde_json::from_str::<serde_json::Value>(&json_content) {
            Ok(_) => {}
            Err(e) => {
                eprintln!("json: can't parse {}: {}", path.display(), e);
                continue;
            }
        }
    }
}
