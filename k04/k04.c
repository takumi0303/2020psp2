#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 14

struct DATA
{
    int id;
    double height;
    int gender;
};

int main(void)
{
    struct  DATA person[N];  /* data */

    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int input_id;
    int i;
    int position_x=-1;
    


printf("input the filename of sample height: ");
fgets(fname,sizeof(fname),stdin);
fname[strlen(fname)-1]= '\0';
fp= fopen(fname,"r");
if(fp==NULL)
{
    fputs("File open error\n",stderr);
    exit(EXIT_FAILURE);
}

i=0;
fgets(buf,sizeof(buf),fp);

while (fgets(buf,sizeof(buf),fp)!=NULL)
{
   sscanf(buf,"%d,%lf",&person[i].gender,&person[i].height);
   i=i+1;
}
if(fclose(fp) == EOF){
    fputs("file close error\n",stderr);
    exit(EXIT_FAILURE);
}

printf("input the filename of sample ID:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    fp = fopen(fname,"r");
    if(fp==NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    i=0;
    while(fgets(buf,sizeof(buf),fp)!=NULL)
    {
        sscanf(buf,"%d",&person[i].id);
        i=i+1;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

     printf("Which ID's data do you want?:");
     scanf("%d",&input_id);

     for(i=0;i<N;i++)
     {
         if(person[i].id==input_id)
           {
               position_x=i;
           }
          else
          
            {
                position_x=position_x;      
            }
          
           
     }

     if(position_x==-1)
     {
         printf("No data");
     }
     else
     {
        printf("ID=%d\n",person[position_x].id);
        printf("gender=%s\n",person[position_x].gender==1?"MALE":"FEMALE");    /* 三項演算子 */
        printf("height=%.2lf\n",person[position_x].height); 
    }

    return 0;
}
     
     
