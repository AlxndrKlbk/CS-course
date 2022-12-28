program PointerPointerRemove;

type
    itemptr = ^item;
    item = record
        data: integer;
        next: itemptr;
    end;

var
    pp: ^itemptr;
    first, tmp: itemptr;
    n: integer;
    numchar: string;
    result_str: string = '';
begin
    first := nil;
    writeln('Enter a numbers until you get bored');

    while not SeekEof do
    begin
        read(n);
        new(tmp);
        tmp^.data := n;
        tmp^.next := first;
        first := tmp
    end;
    
    pp := @first;
    while pp^ <> nil do
    begin
        if pp^^.data < 0 then
        begin
            tmp := pp^;
            pp^ := pp^^.next;
            dispose(tmp)
        end
        else
        begin 
            Str(pp^^.data, numchar);
            result_str := result_str + numchar + ' ';
            pp := @(pp^^.next)
        end
    end;
    writeln(result_str)
end.
