#include <stdio.h>

int main() 
{
	int a,b,x;
	while(scanf("%d%d",&a,&b)==2)		/* scnaf 回傳值是 "引數成功 match 之數目"
											: ex:
											: int a1, a2, a3;
											: int ret = scanf("%d%d%d", &a1, &a2, &a3);
											: 如果使用者輸入 10 22 12
											: 回傳值 ret = 3
											: 如果值用者輸入 10 22 ss
											: 最後一個引數沒有 match 到
											: 回傳值 ret 								*/
										/* feof(stdin) 或 ferror(stdin)怎麼用 
											當讀取到檔案結束或讀取錯誤時，
											它們的傳回值是 true，
											你可以用 if (feof(stdin)) break; 這樣的寫法，
											記得要放在 scanf 的下一行。					*/
	{
		if(a>b)
			printf("A %d\n",a-b);
		else
		{
			if(b>a)
				printf("B %d\n",b-a);
			else
				printf("0\n");
		}
	}
}
