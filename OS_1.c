#include<stdio.h>
int nf,nr,t[20][20],r[20],f[10],pf=0;
void accept()
{
    int i;
    printf("\nHow many references:");
    scanf("%d",&nr);
    printf("Enter reference string:\n");
    for(i=0;i<nr;i++)
    {
        printf("String %d: ",i+1);
        scanf("%d",&r[i]);
    }
    printf("\nHow many frames:");
    scanf("%d",&nf);
}
int search(int pno)
{
    int i;
    for(i=0;i<nf;i++)
    {
        if(f[i]==pno)
        {
            return i;
        }
    }
    return -1;
}
void fifo()
{
    int i,p=0,m,fou;
    for(i=0;i<nf;i++)
    {
        f[i]=-1;
    }
    for(m=0;m<nr;m++)
    {
        fou=search(r[m]);
        if(fou==-1)
        {
            pf++;
            f[p]=r[m];
            p=(p+1)%nf;
            for(i=0;i<nf;i++)
            {
                t[i][m]=f[i];
            }
        }
        else
        {
            for(i=0;i<nf;i++)
            {
                t[i][m]=f[i];
            }
        }
    }
}
void display()
{
    int i,j;
    printf("\nReference String:");
    for(i=0;i<nr;i++)
    {
        printf("%3d",r[i]);
    }
    printf("\n\n");
    for(i=0;i<nf;i++)
    {
        printf("F%d:",i+1);
        for(j=0;j<nr;j++)
        {
            
            if(t[i][j]==-1)
            {
                printf("   ");
            }
            else
            {
                printf("%3d",t[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nPage Fault:%d",pf);
}
int main()
{
    accept();
    fifo();
    display();
    return 0;
}