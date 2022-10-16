program repeat_loop;

var 
    sim: integer;
    number: integer;
    users_sum: integer;
    treshold: integer  = 1000;

begin
    repeat
        write('enter any integer number: ');
        readln(number);
        users_sum := users_sum + number;
        writeln('you current sum is ', users_sum);
    
        if users_sum >= treshold then
            writeln('your sum is bigger then ', treshold, #10#13, 'Bye!')

    until 
        users_sum >= 1000
end.

