PROGRAM foo(input, output, error) ;
   // This example tests simple procedures with parameters. 
   var g: integer;

   procedure  sum(a, b: integer);
      begin
         if a <= 0 then g := b + 9
         else g := b * 3
      end;
      
   begin 
      g := 7; 
      sum(10, 32);   // the result is 96.
        PrintInt(g);
      sum(-10, 21);   // the result is 30. 
        PrintInt(g)
   end.   // this is the end of the program