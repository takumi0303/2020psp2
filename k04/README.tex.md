# 課題4 レポート
bb35319012 大木拓海

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

7 DATAという構造体を作る

16 personという配列を作る  
以降、ループで番号があるかを確認  
なければNo dataと表示

40 heights.csvの一番上を操作から外すため、fgetsをあらかじめ行う

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```
input the filename of sample height: ../sample/heights.csv
sucess
input the filename of sample ID:../sample/IDs.csv
Which ID's data do you want?:45318088
ID=45318088
gender=MALE
height=171.10

## 修正履歴

[comment #20200717]
- main文終了の`}`が変な位置にあります. 
- l.77 person[i]/id はperson[i].idの間違い？
- l.38 `;`がないです. 
- double valは使われていないので要らないのでは?
- これらを訂正すればコンパイルエラーは無くなりますが, まだ正しい値は出てきません. もう少し考えてみましょう. 


[comment #20200721]
- l.27〜 インデントがおかしいです.
- (heightsファイルの方だけ `success` を表示しているのが少し気になりました.)
- l.78 `#define N 14`をしているので, 14ではなくてNのほうが良いです. 
- 変数xは, matched_index とか... 何を示しているか分かるようにした方が良いです. (もっと良い名前ありそうですが)


[comment #20200722]
- OKです. 