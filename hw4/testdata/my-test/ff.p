PROGRAM aa(input, output, error); 
VAR a, b, g, h: INTEGER;
VAR c, d, e: REAL;
VAR ff: array [ 1 .. 10 ] of array[4..8] of array[5..10] of real;
VAR fg: array [ 2 .. 10 ] of integer;
var com: array[1..2] of ARRAY[3..4] of INTEGER;
PROCEDURE ss(a,b:INTEGER; c:REAL);
BEGIN
        PrintInt(a, b);
        PrintReal(c)
END;
//function ads(a, b : real) : real;
//begin
  //  PrintReal(a, b);
//end;
FUNCTION tt (ass: integer): INTEGER;
BEGIN
  tt := ass * a
END;

BEGIN
        ff[4][7][6] := 65.432;
        ff[5][5][8] := 68.764;
        ff[6][6][7] := 63.732;
        //fg[7][6] := 77;
        PrintReal(ff[6][6][7], ff[5][5][8], ff[4][7][6]);
        //PrintReal(ff[4][7][6]);
        //PrintReal(ff[5][5][8]);
        //a := fg[7][6] + 30;
        //c := ff[5][5][8] - ff[6][7][7];
        //PrintReal(c);
        a := 56+ 7;
        b := 555;
        g := 45 + (9*7+4);
        PrintInt(a, b, g);
        //c := ads(a, b)
             //a := 3+tt;
        //b := 8+43;
        //c := 1.2*4.0;
        //a := 55 + 54*10;
        //g := tt;
        //c := 6.6;
        //if c = 6.5 then PrintString("c > 6.5\n") else PrintString("ll");
        //if c > 10.1 then PrintString("c > 10.1\n") else PrintString("hahaha");
        //if c != 6.6 then PrintString("c != 6.6\n") else PrintString("fffff");
        //h := 3 + 93 * 5 + 87;   //555
        a := 3 + 93 * 5 + 87 * (23+15*6);       //10299
        b := 3 + 9 * 5 + 87 * (2+15*6);         //8052
        //g := 9*8+8;
        c := 7.12 * (8.5+9.55+112.3) + 12.12;
        d := 6.5 * 8.0;
        e := 12.1/4.3;
        PrintReal(c, d, e);
        PrintInt(a, b);
        //PrintInt(a, b, g, h)
        //tt := 7*8+(9*7);
        //    ss(a, tt, 0.5);
        fg[3+4-6] := 10;
        com[1+100*0+1][2+4/2] := 100;
        fg[3] := tt(12) ;
        PrintInt(a, b, fg[3], fg[3+4-6], com[1+100*0+1][2+4/2]);
        c := 5.55;
        d := 5.55;
        if c >= d then PrintString("yes\n") else printString("no\n");     
    //ss(tt, tt)  // wrong number of parameters
END.
