這次作業我是用終端機做的
其中有寫一個Makefile，把多個檔案一起編譯
先輸入這行

>> make

輸入上面那行指令後，會多出
lex.yy.c  y.tab.c  y.tab.h  y.output  parser五個檔案
之後依序輸入執行指令，執行指令有放在另一個檔案(test_all.txt)
輸出結果則放在output_dump1,2,3.jpg

>> ./parser TEST-COMPILER02-FOR-PARSER/test-parser-error.p;./parser TEST-COMPILER02-FOR-PARSER/test-minus-neg.p

上面這行代表兩個錯誤的testcase，分別會出現錯誤顯示在第6行(; -)

>> ./parser TEST-COMPILER02-FOR-PARSER/no-parsing-error/test-constant.p;./parser TEST-COMPILER02-FOR-PARSER/no-parsing-error/test-recursion.p;./parser TEST-COMPILER02-FOR-PARSER/no-parsing-error/test-function.p;./parser TEST-COMPILER02-FOR-PARSER/no-parsing-error/test-operator.p;./parser TEST-COMPILER02-FOR-PARSER/no-parsing-error/test-operator2.p

上面這行會顯示出前5筆測資都是OK

>> ./parser TEST-COMPILER02-FOR-PARSER/no-parsing-error/test-procedure.p;./parser TEST-COMPILER02-FOR-PARSER/no-parsing-error/test02-uninitialized-var.p;./parser TEST-COMPILER02-FOR-PARSER/no-parsing-error/test00-runtime-range-check.p;./parser TEST-COMPILER02-FOR-PARSER/no-parsing-error/test01-global-var.p;./parser TEST-COMPILER02-FOR-PARSER/no-parsing-error/test04.p;./parser TEST-COMPILER02-FOR-PARSER/no-parsing-error/test-mini.p;

上面這行會顯示出後6筆測資也都是OK
