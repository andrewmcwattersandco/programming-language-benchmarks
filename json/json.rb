#!/usr/bin/env ruby
require 'json'

def main
  directory = 'companyfacts'

  begin
    files = Dir.entries(directory)
  rescue Errno::ENOENT, Errno::EACCES => e
    puts "json: can't open #{directory}: #{e}"
    return 1
  end

  files.each do |filename|
    next unless filename.end_with?('.json')

    filepath = File.join(directory, filename)

    begin
      data = File.read(filepath, encoding: 'utf-8')
      JSON.parse(data)
    rescue Errno::ENOENT, Errno::EACCES, JSON::ParserError => e
      puts "json: error processing #{filepath}: #{e}"
      next
    end
  end

  0
end

exit(main) if __FILE__ == $0
