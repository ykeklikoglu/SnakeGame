#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<iostream>
using namespace std;

int score=-1;
struct ylan{
	int xeks;
	int yeks;
};
void yeni(int ar[][25],struct ylan yilan[])
{
	int t(0);
	for(int i=0;i<25;i++)
		for(int j=0;j<25;j++)
		{
			if(i==0||j==0||i==24||j==24)
			{
				ar[i][j]=3;
			}
			else
				ar[i][j]=0;
		}
		for (int m=10;m<=17;m++){
			ar[10][m]=1;
			yilan[t].xeks=10;
			yilan[t].yeks=m;
			t++;
		}

}
void yem(int ar[][25])
{
	int m,t,de=0;
	score++;
	do{
		t=rand()%25;
		m=rand()%25;
		if(score%5==4)
		{
			if(ar[t][m]==0)
			{
				ar[t][m]=5;de=1;
				score++;
			}
		}
		else if(ar[t][m]==0)
		{
			ar[t][m]=2;de=1;
		}
	}while(de==0);
}
void yazdir(int ar[][25])
{
	double m=((0.1*score)+1.8);
	cout<<"seviye:"<<(int)m<<endl;
	for(int i=0;i<25;i++)
	{
		for(int j=0;j<25;j++)
		{
			if(ar[i][j]==3){cout<<"[]";printf(" ");}
			else if(ar[i][j]==0){cout<<"   ";}
			else if(ar[i][j]==2){cout<<"@";printf("  ");}
			else if(ar[i][j]==5){cout<<"@@";printf(" ");}
			else {cout<<"O";printf("  ");}
		}
		cout<<endl;
	}
	for(int z=0;z<100000000/m;z++){}
	system("CLS");
}
char up(int (&arr)[25][25],struct ylan (&yilan)[625],int *boy)
{
	int i;
	if(arr[(yilan[0].xeks)-1][yilan[0].yeks]==2||arr[(yilan[0].xeks)-1][yilan[0].yeks]==5)
	{
		for(i=(*boy);i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].xeks--;
		for(i=(*boy);i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		(*boy)++;
		yem(arr);
		return 'w';
	}
	else if((arr[(yilan[0].xeks)-1][yilan[0].yeks]==3)||(arr[(yilan[0].xeks)-1][yilan[0].yeks]==1))
	{
		return 'm';
	}
	else
	{
		arr[yilan[*boy-1].xeks][yilan[*boy-1].yeks]=0;
		for(i=(*boy-1);i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].xeks--;
		for(i=(*boy-1);i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		return 'w';
	}
}
char down(int (&arr)[25][25],struct ylan (&yilan)[625],int *boy)
{
	int i;
	if(arr[(yilan[0].xeks)+1][yilan[0].yeks]==2||arr[(yilan[0].xeks)+1][yilan[0].yeks]==5)
	{
		for(i=(*boy);i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].xeks++;
		for(i=(*boy);i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		(*boy)++;
		yem(arr);
		return 's';
	}
	else if((arr[(yilan[0].xeks)+1][yilan[0].yeks]==3)||(arr[(yilan[0].xeks)+1][yilan[0].yeks]==1))
	{
		return 'm';
	}
	else
	{
		arr[yilan[*boy-1].xeks][yilan[*boy-1].yeks]=0;
		for(i=(*boy-1);i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].xeks++;
		for(i=(*boy-1);i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		return 's';
	}
}
char sol(int (&arr)[25][25],struct ylan (&yilan)[625],int *boy)
{
	int i;
	if(arr[(yilan[0].xeks)][(yilan[0].yeks)-1]==2||arr[(yilan[0].xeks)][(yilan[0].yeks)-1]==5)
	{
		for(i=(*boy);i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].yeks--;
		for(i=(*boy);i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		(*boy)++;
		yem(arr);
		return 'a';
	}
	else if((arr[yilan[0].xeks][(yilan[0].yeks)-1]==3)||(arr[yilan[0].xeks][(yilan[0].yeks)-1]==1))
	{
		return 'm';
	}
	else
	{
		arr[yilan[*boy-1].xeks][yilan[*boy-1].yeks]=0;
		for(i=(*boy-1);i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].yeks--;
		for(i=(*boy-1);i>=0;i--)
		{
			arr[yilan[0].xeks][yilan[0].yeks]=1;
		}
		return 'a';
	}
}
char sag(int (&arr)[25][25],struct ylan (&yilan)[625],int *boy)
{
	if(arr[(yilan[0].xeks)][(yilan[0].yeks)+1]==2||arr[yilan[0].xeks][(yilan[0].yeks)+1]==5)
	{
		int i;
		for(i=(*boy);i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		(yilan[0]).yeks++;
		for(i=(*boy);i>=0;i--)
		{
			arr[(yilan[i]).xeks][(yilan[i]).yeks]=1;
		}
		(*boy)++;
		yem(arr);
		return 'd';
	}
	else if((arr[(yilan[0]).xeks][((yilan[0]).yeks)+1]==3)||(arr[(yilan[0]).xeks][((yilan[0]).yeks)+1]==1))
	{
		return 'm';
	}
	else
	{
		arr[yilan[*boy-1].xeks][yilan[*boy-1].yeks]=0;
		for(int i=(*boy-1);i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].yeks++;
		for(int i=(*boy-1);i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		return 'd';
	}
}
char ters (int ok,int ok2)
{
	if (ok2=='d')
	{
		if(ok=='a'){return 'a';}
		else{return(ok2);}
	}
	else if(ok2=='a')
	{
		if(ok=='d'){return 'd';}
		else{return(ok2);}
	}
	else if(ok2=='s')
	{
		if(ok=='w'){return 'w';}
		else{return (ok2);}
	}
	else if(ok2=='w')
	{
		if(ok=='s'){return 's';}
		else{return (ok2);}
	}
	else if(ok2=='p'){return (ok2);}
	else
	{
		return(ok);
	}
}
int main (void)
{
	system ("color 4F");
	int boy;
	struct ylan yilan[625];
	char ok,ok2,ok3;;
	srand(time(NULL));
	int arr[25][25];
	do{
		cout<<"Uyari:Oyun w,a,s,d tuslariyla oynanmaktadir.\n@=1\n@@=2puan\nOyunda yilanin hizi seviye ile zamanla degisebilir.\n\nOyunu tam ekrana aliniz.\nbaslamak icin 'a'ye basiniz.\nOyunu duraklatmak icin 'p' ye basiniz\n";
		cin>>ok;}while(ok!='a');
		boy=8;
		yeni(arr,yilan);
		yem(arr);
		do{
			switch(ok)
			{
			case 'w':ok=up(arr,yilan,&boy);break;
			case 's':ok=down(arr,yilan,&boy);break;
			case 'd':ok=sag(arr,yilan,&boy);break;
			case 'a':ok=sol(arr,yilan,&boy);break;
			case 'p':system("pause");ok=ok3;
			}
			ok2=ok;
			ok3=ok;
			yazdir(arr);
			if(ok=='m'){break;}
			if(kbhit( )){ok2=getch();ok=ters(ok,ok2);}
		}while(!(ok=='m'));
		cout<<"\noyun bitti.\n";printf("\nscore=%d\n",score);cout<<"\ncikis icin bir tusa basin.\n";ok=getch();
		printf("\nBYE BYE\n");
}