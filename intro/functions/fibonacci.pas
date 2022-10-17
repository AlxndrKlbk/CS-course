program get_fibo;

function Fibonacci(n: integer): longint ;
var 
    i: integer;
    prepre, pre, current: longint;

begin
    if n <= 0 then
        Fibonacci := 0
    else
    begin
        pre := 0;
        current := 1;

        for i := 2 to n do
        begin
            prepre := pre;
            pre := current;
            current := prepre + pre;

        end;
        
        Fibonacci := current
    end
end;


var
    number: integer;

begin 
    write('type odd number:');
    readln(number);
    writeln('Fibonacci for this number:', Fibonacci(number))    
end.


