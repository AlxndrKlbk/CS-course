program HelloFile;

const 
    msg = 'Hello, world!';
    filename = 'hello.txt';

var 
    f: text;

begin
    {$I-}
    assign(f, filename);
    rewrite(f);
    if IOResult <> 0 then
    begin
        writeln('Could''t open file', filename);
        halt(1)
    end;
    
    writeln(f, msg);

    if IOResult <> 0 then
    begin
        writeln('Could''t write to the file');
        halt(1)
    end;
    close(f)
end.

