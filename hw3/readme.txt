這次作業真的好難XD，和上次差好多
我有寫一個Makefile，直接在終端機打make就可以了
之後的執行code都在testcode.txt裡面
先打make，之後複製貼上就可以了
因為太多了，就不放在這裡了
是說這次測資好多，檢查得好累==
另外也有附上output file
執行時也可以選看要顯示在螢幕還是output.txt

還是放一下好了

make

---------------------------with output in output file-------------------

./parser t/test-wrong-func-parameter.p > out/test-wrong-func-parameter.txt
./parser t/test-duplicate2.p > out/test-duplicate2.txt
./parser t/test00-type-error-in-array.p > out/test00-type-error-in-array.txt
./parser t/test02-uninitialized-var.p > out/test02-uninitialized-var.txt
./parser t/test03-uninitialized-var.p > out/test03-uninitialized-var.txt
./parser t/test-minus-neg.p > out/test-minus-neg.txt
./parser t/test-undeclared.p > out/test-undeclared.txt 
./parser t/test-duplicate.p > out/test-duplicate.txt
./parser t/test-type-error.p > out/test-type-error.txt
./parser t/test-error-00.p > out/test-error-00.txt
./parser t/test-correct.p > out/test-correct.txt
./parser t/semantics-test02-errors.p > out/semantics-test02-errors.txt
./parser t/test-undeclared2.p > out/test-undeclared2.txt

---------------------error部分--------------------------------------

./parser t/e/test-LHS.p > out/e/test-LHS.txt
./parser t/e/test-parameter.p > out/e/test-parameter.txt
./parser t/e/test-procedure.p > out/e/test-procedure.txt 
./parser t/e/test-retval.p > out/e/test-retval.txt
./parser t/e/test-array-dim-error_3.p > out/e/test-array-dim-error_3.txt
./parser t/e/test-array-index_error_3.p > out/e/test-array-index_error_3.txt
./parser t/e/test-duplicate_2.p > out/e/test-duplicate_2.txt
./parser t/e/test-undeclared_2.p > out/e/test-undeclared_2.txt
./parser t/e/test-uninitialized_2.p > out/e/test-uninitialized_2.txt
./parser t/e/test-type-error_2.p > out/e/test-type-error_2.txt

------------------------with output in screen--------------------------

./parser t/test-wrong-func-parameter.p;
./parser t/test-duplicate2.p;
./parser t/test00-type-error-in-array.p;
./parser t/test02-uninitialized-var.p;  
./parser t/test03-uninitialized-var.p; 
./parser t/test-minus-neg.p; 
./parser t/test-undeclared.p; 
./parser t/test-duplicate.p;
./parser t/test-type-error.p;
./parser t/test-error-00.p; 
./parser t/test-correct.p ; 
./parser t/semantics-test02-errors.p;
./parser t/test-undeclared2.p;

----------------------error部分---------------------------

./parser t/e/test-LHS.p;
./parser t/e/test-parameter.p ;
./parser t/e/test-procedure.p ;
./parser t/e/test-retval.p;          
./parser t/e/test-array-dim-error_3.p ; 
./parser t/e/test-array-index_error_3.p; 
./parser t/e/test-duplicate_2.p;
./parser t/e/test-undeclared_2.p;
./parser t/e/test-uninitialized_2.p; 
./parser t/e/test-type-error_2.p; 