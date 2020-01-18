//  1  2  3  4  5
//  6  7  8  9 10     63  72  81
// 11 12 13 14 15 -> 108 117 126
// 16 17 18 19 20    153 162 171
// 21 22 23 24 25

program foo(input, output, error);
var a: array [1 .. 5] of array [1 .. 5] of integer;
var ret: array [1 .. 9] of integer;
var i, j, k, s, pos, index: integer;
begin
  i := 0;
  j := 0;
  while i < 5 do
    begin
      while j < 5 do
        begin
          a[i][j] := 5*i + j + 1;
          j := j + 1
        end;
      i := i + 1;
      j := 0
    end;
  i := 0;
  while i < 9 do
    begin
      ret[i] := 0;
      i := i + 1
    end;
  
  i := 0;
  j := 0;
  k := 0;
  s := 0;
  index := 0;
  while i < 3 do
    begin
      while j < 3 do
        begin
          pos := 3*i + j;
          while k < 3 do
            begin
              while s < 3 do
                begin
                  ret[index] := ret[index] + a[i+k][j+s];
                  s := s + 1;
                end;
              k := k + 1;
              s := 0;
            end;
        j := j + 1;
        k := 0;
        s := 0;
        index := index + 1
        end;
    i := i + 1;
    j := 0;
    k := 0;
    s := 0
    end;
  
  i := 0;
  while i < 9 do
    begin
      printInt(ret[i]);
      i := i + 1
    end;
end.
