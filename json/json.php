<?php

$dir = "companyfacts";

if (!is_dir($dir)) {
    fprintf(STDERR, "json: can't open %s: directory not found\n", $dir);
    exit(1);
}

$files = scandir($dir);
if ($files === false) {
    fprintf(STDERR, "json: can't read directory %s\n", $dir);
    exit(1);
}

foreach ($files as $file) {
    if (!str_ends_with($file, ".json")) {
        continue;
    }
    
    $filepath = $dir . "/" . $file;
    
    $jsonContent = file_get_contents($filepath);
    if ($jsonContent === false) {
        fprintf(STDERR, "json: can't read %s\n", $filepath);
        continue;
    }
    
    $decoded = json_decode($jsonContent);
    if ($decoded === null && json_last_error() !== JSON_ERROR_NONE) {
        fprintf(STDERR, "json: can't parse %s: %s\n", $filepath, json_last_error_msg());
        continue;
    }
}

?>
