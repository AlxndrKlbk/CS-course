program loop_while;

var 
    x: integer;

begin 
    x := 1;
    while x < 101 do 
    begin
        write (x * x, ' ');
        x := x + 1;
    end;
    writeln;
end.
