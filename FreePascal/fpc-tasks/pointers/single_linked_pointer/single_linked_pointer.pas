program NumsToPointer;

type
    itemptr = ^item;
    item = record
        data: integer;
        next: itemptr;
    end;

var
    last_item: itemptr;
    tmp: itemptr;
    numchar: string;
    n: integer;
    result_str: string = '';
begin
    last_item := nil;
    writeln('Enter a numbers until you get bored');
    
    while not SeekEof do
    begin
        read(n);
        new(tmp);
        tmp^.data := n;
        tmp^.next := last_item;
        last_item := tmp
    end;
    
    tmp := last_item;
    while tmp <> nil do
    begin
        str(tmp^.data, numchar);
        result_str := result_str + numchar + ' ';
        tmp := tmp^.next
    end;
    writeln(result_str)
end.
