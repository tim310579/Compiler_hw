PROGRAM foo(input, output, error) ;

   var a, b, aa, bb , tmp: integer;
   var c, d, e , cc, dd: real;
   // test recursive functions
   function  sum(a: integer) : integer;
      begin
         if a <= 0 then sum := 0
         else begin sum := sum(a-1) + a; end;
         // sum is the return value
      end;
   function  sumf(a: real) : real;
      begin
         if a <= 0.0 then sumf := 0.0
         else begin sumf := sumf(a - 0.5) + a ; end;
         // sum is the return value
      end;
   function  sum2(a: integer) : integer;
      begin
         if a <= 0 then sum2 := 0
         else begin sum2 := a + sum2(a-1); end;
         // sum2 is the return value
      end;
   function  sumf2(a: real) : real;
      begin
         if a <= 0.0 then sumf2 := 0.0
         else begin sumf2 := a + sumf2(a - 0.5) ; end;
         // sumf2 is the return value
      end;
   begin  
      a := sum(11);   // the result is 55.
      b := sum(-10);   // the result is 0. 
      c := sumf(10.0);
        aa := sum2(11);
        bb := sum2(-11);
        tmp := 5 + 5 + 22;
        PrintString("integer sum\n");
      PrintInt(a, b, aa, bb, tmp);
        c := sumf(11.0);
        d := sumf(-11.0);
        cc := sumf2(11.0);
        dd := sumf2(-11.0);
        PrintString("float sum\n");
        PrintReal(c, d, cc, dd);
        //PrintReal(c);
        //a := 9 + 8 *(9-2);
        //b := (9-2)*8 + 9;
        //PrintInt(a, b)
   end.   // this is the end of the program
