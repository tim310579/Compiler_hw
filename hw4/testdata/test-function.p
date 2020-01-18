PROGRAM foo(input, output, error) ;
   var a, b: integer;
   
   // test simple, non-recursive functions
   function  simplesum(a: integer) : integer;
      begin
         simplesum := a * b
         // simplesum is the return value
      end;

   begin  
      a := 7; b := 13;
      a := 3 + simplesum(10);   // the result is 133 .
      b := 1 * simplesum(-10);   // the result is -130. 
      PrintInt(a, b)
   end.   // this is the end of the program
