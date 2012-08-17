-- A more unix-like copy command
local args =  { ... }
if #args < 2 then
    print 'Usage: cp <source-file> <destination-file>'
    print '       cp <source-file...> <destination-dir>'
    return
end

local dest = shell.resolve(table.remove(args))
local destIsDir = fs.isDir(dest)

-- if copying more than one file, destination must be valid dir
if #args > 1 and not destIsDir then
    print 'Destination is not a directory'
    return
end

for i = 1, #args do
    local file = shell.resolve(args[i])
    if destIsDir then
        fs.copy(file, fs.combine(dest, fs.getName(file)))
    else
        fs.copy(file, dest)
    end
end
