PROGRAM aa(input, output, error); 
VAR a, b, d: INTEGER;
VAR c: REAL;

FUNCTION tt : INTEGER;
VAR a, b : INTEGER;    // No error since the scope is different from global
BEGIN
  a := 3;
  b := a+4;
  PrintInt(a, b);       //3, 7
  tt := b
END;

BEGIN
    a := 3;
    b := 4;
        d := tt;
        PrintInt(d)     //7
END.
