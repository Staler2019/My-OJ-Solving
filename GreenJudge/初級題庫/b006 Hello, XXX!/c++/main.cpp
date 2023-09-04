#include <stdio.h>
#include <iostream>
#include <string>
	/*
		iostream.h裡面定義的所有類以及物件都是在全域空間裡，所以你可以直接用cout但在iostream裡面，它所定義的東西都在名字空間std裡面，所以你必須加上using namespace std才能使用cout
		一般一個C++的老的帶".h"副檔名的標頭檔，比如iostream.h，在新標準後的標準庫中都有一個不帶".h"副檔名的相對應，區別除了後者的好多改進之外，還有一點就是後者的東東都塞進了"std"名字空間中。
		但唯獨string特別。問題在於C++要相容C的標準庫，而C的標準庫裡碰巧也已經有一個名字叫做string.h"的標頭檔，包含一些常用的C字串處理函數，比如樓主提到的string。這個標頭檔跟C++的string類半點關係也沒有
		，所以<string>並非<string.h>的"升級版本"，他們是毫無關係的兩個標頭檔。
	*/
using namespace std;

int main() 
{
	string name;
	cin >> name;
	cout << "Hello, "+name+"!";
}
