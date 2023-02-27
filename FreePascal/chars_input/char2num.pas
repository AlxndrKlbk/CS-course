program ReadNumsByChar;

procedure ReadLongint(var success: boolean; var result: longint);
var
    c: char;
    res: longint;
    pos: integer;

begin
    res := 0;
    pos := 0;
    repeat
        read(c);
        pos := pos + 1
    until (c <> ' ') and (c <> #10);

    while (c <> ' ') and (c <> #10) do
    begin
        if (c < '0') or (c > '9') then
        begin
            writeln('Unexpected ``', c, ''''' in pos: ', pos);
            readln;
            success := false;
            exit
        end;
        res := res*10 + ord(c) - ord('0');
        read(c);
        pos := pos + 1
    end;
    result := res;
    success := true
end;

var
    x, y: longint;
    ok: boolean;
begin
    repeat
        write('Please type the first number: ');
        ReadLongint(ok, x)
    until ok;
    repeat
        write('Please type the second number: ');
        ReadLongint(ok, y)
    until ok;
    writeln(x, ' times ', y, ' is ', x * y)
end.
