program fibonacci(output);
VAR a, ans,b,c,d,e,f,g:integer;
var test : real;
FUNCTION fa (a:integer) :integer;
begin
         if a <= 1 then fa := a
	//	fa := 1
       //  else  if a = 0 then
	//	fa := 0 
	else begin fa := fa(a-1) + fa(a-2); end;
end;
FUNCTION fb (a:real) :real;
begin
       if a <= 1.0 then fb := a
                //fa := 1.0
         //else  if a = 0.0 then
           //     fa := 0.0
        else begin fb := fb(a - 1.0) + fb( a - 2.0); end;
end;

begin
    //a:=readlnI();
    //a := 1;
    //ans := fa(a);
    PrintString("\n\n");
	
	g := fa(16);
	PrintInt(g);
    //PrintInt(a,b,c,d,e,f,g);
    
        
	//PrintInt(b,c,d,e,f,g);
	test := fb(16.0);
	PrintReal(test)
end.
