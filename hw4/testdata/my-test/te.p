PROGRAM aa(input, output, error); 
VAR a, b, gg: INTEGER;
VAR c: REAL;

FUNCTION tt : INTEGER;
VAR a, b : ARRAY[1..2] of INTEGER;
BEGIN
  a[1] := 3;    // No error since this reference is to local variable
  b[1] := a[1]+4;
  tt := b[1]
END;

BEGIN
    a := 3;
    b := 4;
    gg := 0;
    if a > 2 and b > 0 then if a > 9 then PrintInt(a) else PrintString("lalalal\n") else PrintString("hahah\n");
    if a > 2 and b < 77 then PrintInt(a) else PrintString("hahah\n");    
    if a > 2 or b > 77 then PrintInt(a) else PrintString("hahah\n");
    if a > 24 or b > 77 then PrintInt(a) else PrintString("hahah\n");

        while a < 8 do 
        begin
                 a := a +1;
                 b := 5;
                 while b < 10 do
                       begin
                        PrintInt(gg);
                        //a := a + 1;
                        gg := gg + 1;
                        b := b + 1;
                        end;
        end;
        //gg := tt;
        PrintString("result\n");
        PrintInt(gg);
END.
