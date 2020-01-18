PROGRAM foo(input, output, error) ;
   // this test checks various operators

   var a, b, c: integer;
   var d, e: array [ 1 .. 10 ] of integer; 

   begin
      // assignment statement
      a := 6;
      b := a * 30;  //90
      
      // simple if statement
      if b > a then a := a * 2 
               else a := a * 3;  
      PrintInt(a);      //12
      // nested if statement
      if b > a then if b < a - 2 then a := a * 5 
                                 else a := a * 7 
               else a := a / 11 * a;
      PrintInt(a);      //84
      // nested if statement
      if b < a then a := a * 2 
               else if b > 5 + a then a := a - 23
                                 else a := 948 / b;
      PrintInt(a);      //61 
      // simple while statement
      while b > a do a := a * 7;  
      PrintInt(a);      //427
      a := 50;
      // compound statement
      while b > a do begin b := b + 3; a := a * 7 end;  
        PrintString("compound a, b\n");
        PrintInt(a, b); //350, 183
      // nested while statement
      a := 66;
      c := a + b + 1999;
      while b > a do 
            while c > a + b do 
            begin b := b + 3; a := a * 7 end; 
        PrintString("nest while a, b\n");
        PrintInt(a, b); //3234, 189
   end.   // this is the end of the program
