PROGRAM aa(input, output, error); 
VAR a, b, d: INTEGER;
VAR c: REAL;

FUNCTION fact(x:INTEGER) : INTEGER;
BEGIN
    if(x = 1) then
        fact := x
    else
        begin
                //PrintInt(x);
                fact := x*fact(x-1)
        end;
END;

BEGIN
    a := fact(10);      //362880
    b := fact(3);       //6
    d := fact(7);       //5040
        PrintInt(a, b, d)
END.
