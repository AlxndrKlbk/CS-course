program lower_case;
{$codepage utf8}
{$H+}
var 
    character: char;
    converted_string: string = '';
    current_ascii_num: integer;
    ascii_pos: integer;

const
    loop_period = 16;
    first_latin_small_ascii = ord('a');
    last_latin_small_ascii = ord('z');
    
    first_latin_big_ascii = ord('A');
    last_latin_big_ascii = ord('Z');



function check_small_chars_ascii_num(var ch: char): boolean;
var 
    ascii_pos: integer;
    result: boolean = false;

begin
    ascii_pos := ord(ch);
    if (first_latin_small_ascii <= ascii_pos) and (ascii_pos <= last_latin_small_ascii ) then
        result := true;
    check_small_chars_ascii_num := result 
end;



function check_big_chars_ascii_num(var ch: char): boolean;
var 
    ascii_pos: integer;
    result: boolean = false;

begin
    
    ascii_pos := ord(ch);
    if (first_latin_big_ascii <= ascii_pos) and (ascii_pos <= last_latin_big_ascii ) then
        result  := true;
    check_big_chars_ascii_num := result
end;


begin
    writeln(chr(155));
    while not SeekEof do
    begin
        read(character);
        current_ascii_num := ord(character);
        ascii_pos := current_ascii_num + 16 * 2;
        if check_small_chars_ascii_num(character) then
        begin
            converted_string := converted_string + Chr(ascii_pos);
            writeln(chr(ascii_pos))        
        end
        else
        if check_big_chars_ascii_num(character) then
            converted_string := converted_string + character
    
    end;    
    
    writeln(converted_string)
end.

