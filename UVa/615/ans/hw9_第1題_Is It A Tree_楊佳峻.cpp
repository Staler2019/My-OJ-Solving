// TODO
#include<stdio.h>
#include<stdlib.h>
int IsTree(int nSet);
int IsInSet(int*n,int nSet,int x); /* Return member ID */
int g[500][500];
void Trace(int nSet,int root);
int visit = 0; /*Tree Traversal*/
int main(){
    int a,b;/* input */
    int numberSet[500],nSet;/*numberSet and Set size */
    int indexA,indexB; /*member ID of numberSet*/
    int icase,i,j,multiEdge;

    for(icase =1; ;icase++){        // 決定組別
        multiEdge = 0;/*Prevent From muti-edge*/
        scanf("%d%d",&a,&b);        // 每組第一筆資料
        if(a==-1&&b==-1)return 0;
        if(a==0&&b==0){
            printf("Case %d is a tree.\n",icase);
            continue;
        }

        /* Initialize */
        for(i=0;i<500;i++)          // g
            for(j=0;j<500;j++)
                g[i][j]=0;

        /* EnSet(a,b) */
        if(a==b){
            numberSet[0]=a;
            nSet = 1;
            g[0][0] = 1;
        }
        else{
            numberSet[0]=a;
            numberSet[1]=b;
            nSet = 2;
            g[1][0] = 1;
        }
        while(1){
            scanf("%d%d",&a,&b);    // 每組第二筆資料之後
            if(!a&&!b)break;/*End Of Case */

            indexA = IsInSet(numberSet,nSet,a);
            if(indexA==-1){/* EnSet(a,b) */
                numberSet[nSet++]= a;
                indexA = nSet-1;
            }

            indexB = IsInSet(numberSet,nSet,b);
            if(indexB==-1){/* EnSet(a,b) */
                numberSet[nSet++]= b;
                indexB = nSet-1 ;
            }


            if(g[indexB][indexA]==0)
                g[indexB][indexA] = 1;
            else {multiEdge = 1;}
        }

        if(multiEdge)printf("Case %d is not a tree.\n",icase);
        else if(IsTree(nSet))printf("Case %d is a tree.\n",icase);
        else printf("Case %d is not a tree.\n",icase);

    }
return 0;
}
int IsInSet(int*n,int nSet,int x){
    int i;
    for(i=0;i<nSet;i++)
        if(n[i]==x) return i;
    return -1;
}
int IsTree(int nSet){
    int i,j;
    int checkSum,nRoot,root;
    for(i=0,nRoot=0;i<nSet;i++){
        if(g[i][i]==1)return 0;/* Cycle */
        for(j=0,checkSum=0;j<nSet;j++){
            checkSum+=g[i][j];
            if(checkSum>1) {return 0;}
        }

        if(!checkSum) {nRoot++;root = i; /*Record who is Root */}

    }
    if(nRoot!=1){return 0;}
    /* Check Cycle and path :Using DFS*/
    visit = 1;/*From root */
    Trace(nSet,root);

    if(visit==nSet) return 1;
    else return 0;

}
void Trace(int nSet,int start){
    int i;
    for(i=0;i<nSet;i++)
        if(g[i][start]){
            visit++;
            Trace(nSet,i);
        }
    return ;
}