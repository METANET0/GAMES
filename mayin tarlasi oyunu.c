#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void tablo(int a[8][8],int k[8][8],int p[8][8],int *r,int *f)
{
    int i,j;
     printf("    ");
    for(i=0;i<8;i++)
    {
        printf("  %d ",i+1);
    }
    printf("\n");
      for(i=0;i<9;i++)
    {
        printf("----");
    }
    printf("\n");
    for(i=0;i<8;i++)
    {
       printf(" %d |",i+1);
        for(j=0;j<8;j++)
        {
            if(p[i][j]<7 && p[i][j]>-2)
            {
                printf("  D ");
            }
            else if(k[i][j]<10 && k[i][j]>-2)
            {
                printf(" %2d ",k[i][j]);
                if(*f!=-1)
                {
                 (*r)++;
                }
            }
            else
            {
                printf("  # ");
            }
        }
        printf("\n");
    }
}
void mayinlar(int a[8][8])
{
    int c,b,i,j,e,d;
    srand(time(0));
    for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
            c=rand()%7;
            b=rand()%7;
            a[c][b]=-1;
        }
    }
     for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
             if(a[i][j]==-1)
             {
                 for(e=i-1;e<=i+1;e++)
                  {
                     if(e>-1 && e<8)
                     {
                          for(d=j-1;d<=j+1;d++)
                        {
                            if(d>=0 && d<=7)
                            {
                             if(a[e][d]!=-1)
                             {
                               a[e][d]++;
                             }
                            }
                         }
                      }
                  }
             }
         }
    }

}
void secim(int a[8][8],int e,int b,int k[8][8],int *f)
{
    int i,j,c,d;
    if(a[e][b]==0)
    {
      k[e][b]=a[e][b];
      for(c=e-1;c<=e+1;c++)
      {
        if(c<8 && c>-1)
       {
        for(d=b-1;d<=b+1;d++)
         {
          if(d<8 && d>-1)
             {
              if(c==e && d==b)
              {
                continue;
              }
               else
              {
                if(a[c][d]==0)
                {
                 if(c==e || d==b)
                 {
                  if(k[c][d]!=0)
                  secim(a,c,d,k,f);
                 }
                }
                else
                {
                 k[c][d]=a[c][d];
                }
              }
            }
          }
        }
      }
    }
    else if(a[e][b]==-1)
    {
       printf("===================\n");
       printf("!!!!GAME OVER!!!!\n");
       printf("===================\n");
       printf("    ");
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
          k[i][j]=a[i][j];
        }
    }
        *f=-1;
    }
    else
    {
        k[e][b]=a[e][b];
    }
}
void bayrak (int a[8][8],int c,int b,int p[8][8])
{
    p[c][b]=a[c][b];
}
void kaldirma(int p[8][8],int c,int b)
{
    p[c][b]=90;
}
int main()
{
    //mayin tarlasi baslasin...
    int i,j,e,b,f=0,q,r=0;
    char c,x='d';
    int a[8][8],k[8][8],p[8][8];
    s2:
     f=0;
        for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            a[i][j]=0;
        }
    }
      for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            k[i][j]=10;
        }
    }
       for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            p[i][j]=10;
        }
    }
    mayinlar(a);
    tablo(a,k,p,&r,&f);
     s1:
        printf("nokta secmek icin c giriniz,bayrak eklemek icin b giriniz,bayrak kaldirmak icin k giriniz\n");
        scanf(" %c",&c);
        printf("satir no giriniz\n");
        scanf("%d",&e);
        printf("grup no giriniz\n");
        scanf("%d",&b);
        if(c=='c')
      {
        secim(a,e-1,b-1,k,&f);
        r=0;
        tablo(a,k,p,&r,&f);

      }
      else if(c=='b')
      {
          bayrak(a,e-1,b-1,p);
          r=0;
          tablo(a,k,p,&r,&f);
      }
      else if(c=='k')
      {
          kaldirma(p,e-1,b-1);
          r=0;
          tablo(a,k,p,&r,&f);
      }
      else
      {
          printf("lutfen gecerli yol seciniz\n\n");
      }
      if(r>=58)
      {
          printf("\n==================\n");
          printf("\2\2\2\2 YOU WIN \2\2\2\2\n");
          printf("==================\n\n");
          f=-1;
      }
      if(f==0)
      {
          goto s1;
      }
      printf("\nlutfen cikis icin c'ye,yeni bir oyun icin d ye basiniz\n");
      scanf(" %c",&x);
      if(x=='d')
      {
          goto s2;
      }
      getch();
  return 0;
}
