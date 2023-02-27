program RandomStars;
uses crt;

const 
    DelayDuration = 5;
    ColorCount = 16;
var 
    AllColors: array[1..ColorCount] of word =
    (
        Black, Blue, Green, Cyan, Red, Magenta, Brown,
        LightGray, DarkGray, LightBlue, LightGreen,
        LightCyan, LightRed, LightMagenta, Yellow, White
    );
var 
    x, y, col: integer;

begin
    randomize;
    clrscr;
    while not keypressed do
    begin 
        x := random(ScreenWidth) + 1;
        y := random(ScreenHeight) + 1;
        if (x = ScreenWidth) and (y = ScreenHeight) then
            continue;
        col := random(ColorCount) + 1 ;
        GotoXY(x, y);
        TextColor(AllColors[col]);
        write('*');
        delay(DelayDuration)
    end;
    write(#27'[0m');
    clrscr
end.

