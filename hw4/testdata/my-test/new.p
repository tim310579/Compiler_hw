PROGRAM aaa(aaa,bbb,ccc);
VAR aa,bb,cc : INTEGER;
VAR dd : REAL;
VAR ax: array [4..8] of integer;
//VAR ff: array [ 2 .. 10 ] of array[4..8] of integer;
VAR jj: ARRAY[1..6] of array[3..7] of REAL;

FUNCTION heloo (a,b,c,t:integer; d,e,f : real) :integer;
VAR h,q : integer;
var tet : real;
begin
    //h := 188;
    //h := h + a;
        tet := d + e;
    //PrintInt(h, a, b, c, t);
    //d := 87.88;
        PrintReal(d, e, f, tet);
    //PrintString("seppppp\n");
      //  heloo := 12;
        dd := 12.1212
end;


BEGIN
//        PrintInt(1256);
  //      PrintInt(878787);
//        PrintInt(1,2,3,4, 5, 6);
        PrintReal(9.1, 42.3, 6.54, 7.23);
//    dd := 3.54*8.5+5.77;
//    jj[1][3] := 9898.98;
//    PrintString("test for real\n");
//    PrintReal(dd, dd, jj[1][3], 0.878);
//    PrintString("test for integer\n");
//    aa := 65;
//    bb := aa;
    //ax[5] := 87;
    //ff[5][6] := 52;
    //ff[7][7] := aa;
    //PrintInt(ax[5], ff[5][6], ff[7][7]);
    
    //PrintString("ter\n");
    //PrintReal(gg[2][7][8], gg[2][7][9], gg[2][4][5]);
    
    //PrintString("test and test\n");

    aa := heloo(2, 3, 4, 2, -5.4, -6.5, -9.7);
    //PrintInt(aa);
      //  PrintReal(dd);
        //sum(aa, bb);
//    aa := tt(1) + aa;  
//    PrintInt(aa);
    PrintReal(dd)
    //if gg[2][7][9] < gg[4][5][6] then PrintString("test positive\n")
    //else PrintString("test negative\n")
END.
