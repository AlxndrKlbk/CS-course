program subloop;

var 
    hight: integer; {high of diamond}
    half_hight: integer; {half-high of diamond}

    i, j: integer;

begin
    repeat
    begin 
        write('please, enter high of diamond (it must be odd):');
        readln(hight)
    end
    until (hight > 0)  and (hight mod 2 = 1);
    
    half_hight := hight div 2;   


    for i := 1 to half_hight + 1 do
    begin
        for j := 1 to half_hight + 1 - i do
            write(' ');
        write('*');
        
        if i > 1 then
        begin
            for j := 1 to 2 * i - 3 do
            begin
                write(' ')
            end;
            write('*')
        end;
        writeln
    end;
    
    for i := half_hight downto 1 do
    begin 
        for j := 1 to half_hight + 1 - i do
            write(' ');
        write('*');
        
        if i > 1 then
        begin
            for j := 1 to 2 * i - 3 do
            begin
                write(' ')
            end;
            write('*')
        end;
        writeln
    end;
end.
