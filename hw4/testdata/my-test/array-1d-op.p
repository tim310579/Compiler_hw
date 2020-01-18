program foo(input, output, error);
var a : array [1 .. 10] of integer;
begin
  a[0] := 6;
  a[1] := 3;
  
  printInt(a[0]+a[1]);
  printInt(a[0]-a[1]);
  printInt(a[0]*a[1]);
  printInt(a[0]/a[1])
end.
