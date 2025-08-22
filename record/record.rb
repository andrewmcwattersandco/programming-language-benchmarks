#!/usr/bin/env ruby

class Record
  attr_accessor :id

  def initialize(record_id)
    @id = record_id
  end
end

def main
  records = []

  (0...16_777_216).each do |i|
    r = Record.new(i)
    records << r
  end
end

main if __FILE__ == $0
