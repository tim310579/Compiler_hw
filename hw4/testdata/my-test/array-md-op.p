program foo(input, output, error);
var a : array [1 .. 10] of array [1 .. 10] of integer;
begin
  a[1][4] := 6;
  a[5][7] := 3;
  
  printInt(a[1][4]+a[5][7]);
  printInt(a[1][4]-a[5][7]);
  printInt(a[1][4]*a[5][7]);
  printInt(a[1][4]/a[5][7])
end.
