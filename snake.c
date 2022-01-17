#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

/// GLOBALLY DECLARE VARIABLE

int w=119,h=23;
int x,y,fX,fY,lX,lY,score=0,gameOver,flag,life=3;
int tallX[100],tallY[100],count=0;
int i,j,prevX,b=1,prevY,prevX2,prevY2,lv=1;

/// FUNCTION PROGRAMME

void delay(unsigned int mseconds)
{
clock_t goal = mseconds + clock();
    while (goal > clock());
}
void setup()
{
    gameOver=0;
    score=0;
    x=h/2;
    y=w/2;
lable1:
    fX=rand()%22;
    if(fX<10)
    goto lable1;
lable2:
    fY=rand()%100;
    if(fY<10)
    goto lable2;
}

/// <<<<<<<<<<VIEW>>>>>>>>>>>
void view()
{
   
    int i,j,k;
    system("cls");
printf("\n                                 LIFE=%d              LEVEL %d             SCORE=%d\n\n",life,lv,score);
printf("\t     FOR PAUSE PRESS Q\t\t\tFOR PLAY PRESS P\t\t\tFOR EXIT GAME PRESS O\n\n");
    for( i = 0; i < h; i++)
    {
        for ( j = 0; j < w; j++)
        {
           if(lv==2 && i>8 && i<13 && j>50 && j<65 || i==h-1 && j>10 && j<108 || j==w-11|| i==0 && j>10 && j<108 || j==10 || lv==2 && i>15 && i<20 && j>15 && j<30 || lv==2 && i>2 && i<7 && j>15 && j<30 || lv==2 && i>15 && i<20 && j>88 && j<103 || lv==2 && i>2 && i<7 && j>88 && j<103)
           {
                printf("*");
           }
           else
           if(i==x && j==y){
           printf("O");}
           else if(i==fX && j== fY)
           {
            printf("F");
           }else
           {
               int a=0;
           for ( k = 0; k < count; k++)
           {
               if(i==tallX[k] && j==tallY[k])
               {
                   printf("o");
                   a=1;
               }
           }
           
            if(a==0)
            printf(" ");
           }
           
        } 
        
        printf("\n");
        
    }
}

///<<<<<<<<<<INPUT>>>>>>>>>>>>

void input()
{
    if(kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag=1;
            break;
        case 's':
            flag=2;
            break;
        case 'w':
            flag=3;
            break;
        case 'z':
            flag=4;
            break;
        case 'o':
        gameOver=1;
        break;
        case 'q':
        lable45:
            if(getch()=='p')
            break;
            else
                goto lable45;  
        }
    }
}

///<<<<<<<<<<<<<<<MAKE>>>>>>>>>>>>>>>>>

void make()
{
    
    prevX=tallX[0];
    prevY=tallY[0];
    tallX[0]=x;
    tallY[0]=y;

    for ( i =1; i < count; i++)
    {
        prevX2=tallX[i];
        prevY2=tallY[i];
        tallX[i]=prevX;
        tallY[i]=prevY;
        prevX=prevX2;
        prevY=prevY2;
    }
    
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    default :
        break;
    }

    if(x==0 || x==22 || y==10 || y==108|| lv==2 && x>8 && x<13 && y>50 && y<65 || lv==2 && x>15 && x<20 && y>15 && y<30 || lv==2 && x>2 && x<7 && y>15 && y<30 || lv==2 && x>15 && x<20 && y>88 && y<103 || lv==2 && x>2 && x<7 && y>88 && y<103)
    {
        
    life=life-1;
lable5:
    x=rand()%22;
    if(x<10 || lv==2 && x>8 && x<13 || lv==2 && x>15 && x<20 || lv==2 && x>2 && x<7 || lv==2 && x>15 && x<20 || lv==2 && x>2 && x<7)
    goto lable5;
lable6:
    y=rand()%100;
    if(y==0)
    goto lable6;
    }
    for ( i = 0; i < count; i++)
    {
        if(x==tallX[i] && y==tallY[i])
        {
            life-=1;
        lable7:
            x=rand()%22;
            if(x<=0 || x>=22 || lv==2 && x>8 && x<13 || lv==2 && x>15 && x<20 || lv==2 && x>2 && x<7 || lv==2 && x>15 && x<20 || lv==2 && x>2 && x<7)
            goto lable7;
        lable8:
            y=rand()%99;
            if(y>=108 || y<=10 || lv==2 && y>50 && y<65 || lv==2 && y>15 && y<30 || lv==2 && y>15 && y<30 || lv==2 && y>88 && y<103 || lv==2 && y>88 && y<103)
            goto lable8;
        }
    }
    if(life==0)
    {
        gameOver=1;
    }
    if(x==fX && y==fY)
    {
lable3:
    fX=rand()%20;
    if(fX<=0 || fX>=22 || lv==2 && fX>8 && fX<13 || lv==2 && fX>15 && fX<20 || lv==2 && fX>2 && fX<7 || lv==2 && fX>15 && fX<20 || lv==2 && fX>2 && fX<7 )
    goto lable3;
lable4:
    fY=rand()%99;
    if(fY>=108 || fY<=10|| lv==2 && fY>50 && fY<65 || lv==2 && fY>15 && fY<30 || lv==2 && fY>15 && fY<30 || lv==2 && fY>88 && fY<103 || lv==2 && fY>88 && fY<103)
    goto lable4;
    score+=10;
    count+=1;
    }
}

///<<<<<<<<<<<<<<<<<<<LEVEL>>>>>>>>>>>>>>>>

void level()
{
for ( i = 0; i < 28; i++)
    {
        for (j = 0; j < 119; j++)
        {
            if(i==12 && j==52)
            {
                printf("LEVEL %d",lv);
            }
            if(i==13 && j==44)
            {
                printf("LOADING"); 
                for (size_t k = 0; k <= 5; k++)
                    {
                        printf(".");
                        delay(400);
                    }
            }else       
            {
                printf(" ");
            }
        }
        if(i!=12)
        printf("\n");
        
    }system("cls");
}
/////////////////SNAKE FUNCTION//////////////
void snake()
{
    for ( i = 0; i < 28; i++)
    {
        for (j = 0; j < 119; j++)
        {
            if(i==12 && j==52)
            {
                printf("SNAKE GAME");
            }
            if(i==13 && j==38)
            {
                printf(".....BY CHANDAN"); 
                for (size_t k = 0; k <= 5; k++)
                    {
                        printf(".");
                        delay(400);
                    }
            }else       
            {
                printf(" ");
            }
        }
        if(i!=12)
        printf("\n");
        
    }system("cls");
    

}

//<<<<<<<<<<<MAIN FUNCTION>>>>>>>>>>>>

int main(int argc, char const *argv[])
{
    int OP,i,j;
    snake();
    i=0;
    j=0;
    level();
    setup();
    lable10: 
    switch(score)
    {
            case 0:
        while (!gameOver)
        {
            view();
            input();
            make();
            if(score==300)
            break;
        }
        if(gameOver==0)
            goto lable10;
        break;
            case 100:
            system("cls");
            lv=2;
            level();
            while (!gameOver)
        {
            view();
            input();
            make();
        if(score==500)
            break;
        }
        if(gameOver==0)
            goto lable10;
            break;

    }
    system("cls");
    for ( i = 0; i < 28; i++)
    {
        for (j = 0; j < 119; j++)
        {
            if(i==14 && j==55)
            {lable36:
                printf("GAME OVER");
                for (size_t k = 0; k <= 5; k++)
                    {
                        printf(".");
                        delay(200);
                    }
            }else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    

    return 0;
}