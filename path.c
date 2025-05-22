#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int path(int cost[10][10], int s, char p[100])
{
    int dis[10], v[10], pre[10], nex = 0, count = 0, min = 10000;
    for (int i = 0; i < 10; i++) {
        dis[i] = pre[i] = 0;
    }
    for (int i = 0; i < 10; i++) {
        if (i != s) {
            dis[i] = cost[i][s];
            if (dis[i] < 10000) {
                pre[i] = s;
            }
        }
        else {
            dis[s] = 0;
        }
        v[i] = 0;
    }

    v[s] = 1;
    pre[s] = s;
    count++;

    while (count < 10) {
        min = 10000;
        for (int i = 0; i < 10; i++) {
            if (v[i] == 0 && dis[i] < min) {
                min = dis[i];
                nex = i;
            }
        }

        v[nex] = 1;
        count++;

        for (int i = 0; i < 10; i++) {
            if (v[i] == 0 && dis[nex] + cost[i][nex] < dis[i]) {
                dis[i] = cost[i][nex] + dis[nex];
                pre[i] = nex;
            }
        }
    }

    int way[10], idx = 0, cmp[10], cmps = 10000, sum = 0;

    for (int i = 0; i < 10; i++) {
        way[i] = cmp[i] = 0;
    }

    way[idx] = s;
    idx++;

    for (int i = 0; i < 10; i++) {
        if (cost[i][s] != 0 && cost[i][s] < 10000) {
            sum++;
        }
    }

    if (sum < 2) {
        sprintf(p, "%c", 'n');
    }

    else {
        for (int j = 0; j < 10; j++) {
            if (cost[j][s] < 10000) {

                int diss[10], vs[10], nexs = 0, counts = 0, mins = 10000, pres[10];
                for (int i = 0; i < 10; i++) {
                    diss[i] = pres[i] = 0;
                }

                for (int i = 0; i < 10; i++) {
                    if (i != s && i != j) {
                        diss[i] = cost[i][s];
                        if (diss[i] < 10000) {
                            pres[i] = s;
                        }
                    }
                    else {
                        diss[s] = 0;
                        diss[j] = 10000;
                    }
                    vs[i] = 0;
                }

                vs[s] = 1;
                pres[s] = s;
                counts++;

                while (counts < 10) {
                    mins = 10000;
                    for (int i = 0; i < 10; i++) {
                        if (vs[i] == 0 && diss[i] < mins) {
                            mins = diss[i];
                            nexs = i;
                        }
                    }

                    vs[nexs] = 1;
                    counts++;

                    for (int i = 0; i < 10; i++) {
                        if (vs[i] == 0 && diss[nexs] + cost[i][nexs] < diss[i]) {
                            diss[i] = cost[i][nexs] + diss[nexs];
                            pres[i] = nexs;
                        }
                    }
                }

                cmp[j] = cost[j][s] + diss[j];
                int tmp = pres[j];

                if (cmp[j] < cmps) {
                    cmps = cmp[j];
                    idx = 1;
                    way[idx] = j;
                    idx++;

                    for (int i = 0; i < 10; i++) {
                        if (tmp != s) {
                            way[idx] = tmp;
                            tmp = pres[tmp];
                            idx++;
                        }
                    }
                }

            }
        }
        way[idx] = s;
        for (int i = 0; i < idx + 1; i++) {
            if (i < idx) {
                sprintf(p + 2 * i, "%d,", way[i]);
            }
            else
                sprintf(p + 2 * i, "%d", way[i]);
        }
    }

   return 0;  
}


int main()
{
   
    int cost[10][10];
    int n,i,j,s,d;
    char p[100];
 
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        { 
           cost[i][j]=10000;
        }  
    }


    cost[0][1]=1;
    cost[0][3]=4;
    cost[1][0]=1;
    cost[1][2]=3;
    cost[1][4]=1;
    cost[2][1]=3;
    cost[2][4]=1;
    cost[2][5]=2;
    cost[3][0]=4;
    cost[3][4]=1;
    cost[4][1]=1;
    cost[4][2]=1;
    cost[4][3]=1;
    cost[5][2]=2;

    
    printf("Source: ");
    scanf("%d",&s);
    path(cost,s,p);
    
    if(p[0]=='n'){
    	printf("There is no path\n");
    }
    else{
        printf("The shortest path is %s\n",p); 
    }
		

  
    return 0;
      
}
