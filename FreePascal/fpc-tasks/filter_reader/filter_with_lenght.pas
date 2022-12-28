program FilterOk;

var 
    c: char;
    lenght: integer = 0;

begin 
    while not eof do
    begin
        read(c);
        if c = #10 then
        begin
            writeln('lenght of string ', lenght,  '--- Ok');
            lenght := 0
        end;
        lenght := lenght + 1
    end;
    writeln('Good bye')
     
end.


