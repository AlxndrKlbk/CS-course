program record_type;

type
    CheckPoint = record
        n: integer;
        latitude, longitude: real;
        hidden: boolean;
        penalty: integer;
    end;

const 
    MaxCheckPoint = 75;


type 
    CheckPointArray = array [1..MaxCheckPoint ] of CheckPoint;

var
    track: CheckPointArray;

begin
end.

