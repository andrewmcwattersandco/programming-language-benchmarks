local json = require("lua.json")
require("dir")

local path = "companyfacts"

local files = dir(path);
for i, file in ipairs(files) do
  if (string.find(file, ".json", -5, true)) then
    io.input("companyfacts/" .. file)
    t = io.read("*all");
    json.decode(t);
  end
end
