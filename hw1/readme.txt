這個project1
有附上三張截圖
分別是有關八個testdata的結果
說明如下
第一張
第一項:comment，comment都被忽，所以顯示為空白
第二項:error，被讀到的error都被歸類在lexical error裡
第三項:float，realnumber的token number是58，其中有包含科學記號，
也把他們和float都歸類在realnumber項，有一些不合法的float，則被拆成identifier或digseq項
2nd picture
四:identifier(39),以數字或"_"以外開頭的字串都不算是identifier，所以前五和最後一個是，
第六個是數字開頭，所以不是
五:integer,44為token number，int不解釋
六:operator,各自的operator都有各自的token number沒問題
3rd picture
七:reservedword,各自有token number，其中integer和real原本沒有，所以加成71,72
八:string,string的token number定成66，單行或多行都可辨認成string

execute code放在另外一個txt檔
