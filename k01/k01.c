#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave)

{
    return(((N-1)*ave/N)+(val/N));
}
extern double var_online()
{
    return(((N-1)*square_ave/N)+pow(val,2)/N)-pow((((N-1)*ave/N)+(val/N)),2);
}
int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    double var,square_ave,unvar;
    double ave =0;
    int N=0;
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
   N++;
   var=var_online(val,ave,square_ave,N);
   ave=ave_online(val,ave,N);
   square_ave=ave_online(pow(val.2),square_ave,N);



    }

    ubvar=N*var/(N-1);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("ave=%1f\n",stderr);
    printf("var=%1f\n",var);
    printf("unvar=%1f\n",unvar);


    return 0;


}

