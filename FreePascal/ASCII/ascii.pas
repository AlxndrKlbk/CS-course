program print_ascii;

var 
    i, j: integer;
    c: char;

begin
    write ('  |');
    for c := '0' to '9' do
        write(' .', c);
    for c := 'A' to 'F' do
        write(' .', c);
    writeln;
    write('  |');
    
    for i := 1 to 16 do
        write('---');
    writeln;
    for i := 2 to 7 do
    begin
        write(i, '.|' );
        for j := 0 to 15 do
            write('  ', char(i*16 + j));
        writeln
    end
end.
    
