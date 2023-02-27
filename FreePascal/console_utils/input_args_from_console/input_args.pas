program args_from_console;

var 
    i: integer;

begin
    for i := 1 to ParamCount do
        writeln('[', i, ']', ParamStr(i))
end.
