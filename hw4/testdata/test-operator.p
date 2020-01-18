PROGRAM foo(input, output, error) ;
   // this test checks various operators

   var a, b, c: integer;
   var d, e: array [ 1 .. 10 ] of integer; 

   begin
        a := 0;
        b := a + 93;  // simple expression
        PrintInt(b);    //93
        b := a - 93;  // simple expression
        PrintInt(b);    //-93
        b := a * 93;  // simple expression
        PrintInt(b);    //0
        b := a / 93;  // simple expression
        PrintInt(b);    //0
        b := 3 + 93 * 5 + b * (23-15*6/9);  // complex expression
        PrintInt(b);    //468
      a := 1;   // test relation operators
      if b > a then a := a * 2 else a := a * 3;
        PrintInt(a);    //2
      if b < a then a := a * 5 else a := a * 7;
        PrintInt(a);    //14
      if b = a then a := a * 11 else a := a * 13;
        PrintInt(a);    //182
      if b >= a then a := a * 17 else a := a * 19;
        PrintInt(a);    //3094
      if b <= a then a := a * 23 else a := a * 29;
        PrintInt(a);    //71162
      if b != 0 then a := a * 31 else a := a * 37;
        PrintInt(a);    //2206022
      if not (b < a) then a := a * 41 else a := a * 43;
        PrintInt(a);    //94858946
   end.   // this is the end of the program
