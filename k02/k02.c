#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

int main(void)
{
    double z;
    double mu_1, mu_2;
    double sd_1, sd_2;
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("mu_1=");
    scanf("%lf",&mu_1);
    printf("sd_1=");
    scanf("%lf",&sd_1);
    printf("mu_2=");
    scanf("%lf",&mu_2);
    printf("sd_2=");
    scanf("%lf",&sd_2);

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        z=(val-mu_1)/sd_1;
        L1=p_stdnorm(z)*L1;

        z=(val-mu_2)/sd_2;
        L2=p_stdnorm(z)*L2;

    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_1: %f\n",L1);
    printf("L_2: %f\n",L2);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

