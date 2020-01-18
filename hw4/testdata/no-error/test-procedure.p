PROGRAM aa(input, output, error); 
VAR a, b: INTEGER;
VAR c: REAL;

FUNCTION ss : INTEGER;
BEGIN
  ss := 3+4*5
END;

PROCEDURE tt;
BEGIN
    a := ss+33*ss;
    c := 0.5
END;

function uu : real;
begin
        uu := 5.3 + 1.4*8.0
end;
BEGIN
    a := ss*ss+ss;
    c := uu*uu+uu;
    PrintInt(a);        //23*23+23=552
        PrintReal(c);   //16.5+16.5*16.5= 288.75
    tt;
    PrintInt(a);        //23+33*23 = 782
        tt;
        PrintInt(a);
        tt;
    PrintInt(a)
END.

