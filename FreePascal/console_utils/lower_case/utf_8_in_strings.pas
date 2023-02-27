program unicode_str_test;
 
{$mode objfpc}{$H+}
{$codepage utf8}
uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
var
  s: unicodestring;
  str: string;
begin
    str:= chr(150);
    writeln(str);

    s := chr(150);
    writeln(s)
end.
