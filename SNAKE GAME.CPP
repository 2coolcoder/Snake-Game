#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<dos.h>
#include<ctype.h>

#define height 20
#define width 79
struct position
{
	int x,y;
};
struct file
{
	int flag;
	int Highscore;
	int Fruit;
	char ch;
	position S[100];
	position F;

};
class game
{
	public:
	game()
	{
		f=fileload();
		if(startscreen())
		{
			hscoreold=Highscore;
			ch='d';
			Fruit=0;
		    SetFruitPosition();
		    S[0].x=width/2;
		    S[0].y=height/2;
		}
		cout<<"all set";
	}
	char ch;
	int Fruit, Highscore,hscoreold,f;
	position S[100],F;
	int startscreen();
	int fileload();
	void savedata(int );
	int check(int ,int );
	void SetFruitPosition();
	void SetSnakePosition();
	void pause();
	void Draw();
	void Input();
	void Logic();
	void direction();
	void Gameover();
};

int game::startscreen()
{
	char k;int flag=0;
	while(1)
     {
	clrscr();
	cout<<"///////////SNAKE GAME/////////////";
	cout<<"\n\n1. START NEW GAME";
	cout<<"\n2. INSTRUCTIONS\n3. HIGHSCORE\n4. CREDITS";
	if(f==1)
	   cout<<"\n5. CONTINUE PREVIOUS GAME";
	cout<<"\n0. EXIT";
	if(flag==0) cout<<"\nENTER YOUR CHOICE";
	if(flag!=0) cout<<"\n\nINVALID INPUT!!!!!!!\nRE-ENTER YOUR CHOICE";
	k=getch();
	flag=0;
	k=(int)k-48;
	if(k==1)return 1;
	else if((int)k==5 && f==1)return 0;
	else if((int)k==2)
	{
		clrscr();
		cout<<"///////////SNAKE GAME/////////////";
		cout<<"\n<<<<<---INSTRUCTIONS--->>>>\n\nThe objective of the player is \nTo giude the snake ( Oooooooo ) to the fruits ( * ) and gain score. \n The game ends when the snake hits itself";
		cout<<"\nTo guide the snake : \n Press w to move up \n Press s to move down \n Press a to move left \n Press d to move right";
		cout<<"\n\n\n\nPress any key to go back to menu.";
		getch();
	}
	else if((int)k==3)
	{
		clrscr();
		cout<<"///////////SNAKE GAME/////////////";
		cout<<"\n\n\n\nHighscore: "<<Highscore;
		cout<<"\n\n\n\n Press any key to go back to menu.";
		getch();
	}
	else if((int)k==4)
	{
		clrscr();
		cout<<"///////////SNAKE GAME/////////////";
		cout<<"\n\n\nSnake Game is the common name for a video game concept where the player maneuvers a line which grows in length, with the line itself being a primary obstacle. The concept originated in the 1976 arcade game Blockade.\n It has been recreated by Rohitangshu Bose and Rupankar Podder through the application of c++ ";
		cout<<"\n\n\n\n Press any key to go back to menu.";
		getch();
	}
	else if((int)k==0)
		exit(0);
	else flag=1;
	}
}
void game:: SetFruitPosition()
{
	label:
	{
		srand(time(0));
		F.x=rand()%(width-5)+2;
		F.y=rand()%(height-5)+2;
		if(check(F.x,F.y))
		goto label;
	}
}
int game:: fileload()
{
	fstream data;
	file f ;
	f.flag=0;
	data.open("data.bin" , ios::in | ios::out | ios::binary);
	if(!data)
	{
		Highscore=0;
		hscoreold=0;
		return  0;
	}
	data.read((char*)&f , sizeof(f) );
	if(f.flag==0)
	{
		Highscore= f.Highscore;
		return 0;
	}
	for(int i=0;i<=Fruit;i++)
	S[i]=f.S[i];
	Fruit=f.Fruit;
	ch=f.ch;
	F=f.F;
	Highscore= f.Highscore;
	return 1;
}
void game::savedata(int a)
{
	ofstream data;
	data.open("data.bin", ios::out|ios::binary);
	file f;
	f.flag=0;
	if (a==1)
	{
		f.F=F;
		f.flag=1;
		f.ch=ch;
		f.Highscore=Highscore;
		for(int i=0;i<=Fruit;i++)
			f.S[i]=S[i];
		f.Fruit=Fruit;
		data.write((char*)&f, sizeof(f));
	}
	else
	{
		f.Highscore=Highscore;
		data.write((char*)&f, sizeof(f));
	}
}
int game::check(int i,int j)
{
	for(int k=1;k<=Fruit;k++)
	{
		if(S[k].x==i && S[k].y==j)
		     return 1;
	}
	return 0;

}
void game::SetSnakePosition()
{
	if(S[0].x==width-1)
		S[0].x=1;
	if(S[0].x==0)
		S[0].x=width-2;
	if(S[0].y==height)
		S[0].y=1;
	if(S[0].y==0)
		S[0].y=height-1;
}
void game::pause()
{
	clrscr();
	cout<<"///////////SNAKE GAME/////////////";
	cout<<"\n///////-----PAUSED-----////////";
	cout<<"\n\n Press p to play. \n Press s to save and exit. \n Press x to exit without saving.";
	int t=1;
	while(t==1)
	{
		char temp=getch();
		tolower(temp);
		switch(temp)
		{
			case 'p' :t=0;break;
			case 's' :savedata(1);exit(0);break;
			case 'x' : savedata(2);exit(0);
		}
	}
}
void game::Draw()
{
	clrscr();
	       //	cout<<Fruit<<" "<<F.x<<"-"<<F.y<<" "<<ch<<"x"<<S[0].x<<"y"<<S[0].y<<endl;
	cout<<"�";
	for(int i=1;i<width-1;i++)
		cout<<"�";
	cout<<"�";
	cout<<endl;
	for(int j=1;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
		       if(check(i,j))
				cout<<"o";
		       else if(j==F.y && i==F.x)
				cout<<"X";
			else if(i==S[0].x && j== S[0].y)
				cout<<"O";
			else if(i==0||i==(width-1))
				cout<<"�";
			else
				cout<<" ";
		}
		cout<<endl;
	}
	cout<<"�";
	for(i=1;i<width-1;i++)
		{
			cout<<"�";
		}
	cout<<"�";
	for(i=Fruit;i>=0;i--)
	    S[i+1]=S[i];
	direction();
	cout<<endl<<"SCORE: "<<Fruit*5<<"\tHighscore= "<<Highscore;
	cout<<"\nPress p to pause    x to exit without saving";
}
void game:: Input()
{
	char c;
	tolower(c);
	for(int i=0;i<70;i++)
	{
		if(kbhit())
		{
			c=getch();
			if((c=='w' && ch!='s')||(c=='a' && ch!='d') ||(c=='s' && ch!='w')||(c=='d'&& ch!='a'))
				ch=c;
			else if (c=='p')
			pause();
			else if(c=='x')
			{	savedata(2);
				exit(0);
			}
		}
	      if(ch=='w'|| ch=='s')
	      delay(2);
	      if(ch=='a'||ch=='d')
	      delay(1);
	}
}
void game:: Logic()
{
	if(S[0].x==F.x && S[0].y==F.y)
	{
		SetFruitPosition();
		Fruit++;
	}
	SetSnakePosition();
	if(check(S[0].x,S[0].y) )
		Gameover();
	if(5*Fruit>Highscore)
	Highscore=5*Fruit;
}
void game:: direction()
{
   switch(ch)
   {
	case 'w': S[0].y--;break;
	case 's': S[0].y++;break;
	case 'a': S[0].x--;break;
	case 'd': S[0].x++;break;
   }
}
void game::Gameover()
{
 	clrscr();
 	cout<<"////////////------GAME OVER------////////////"<<endl<<endl;
 	if(hscoreold<Highscore)
	cout<<"\nCongratulations!! High score !!";
 	cout<<"Your score : "<<5*Fruit<<endl<<endl<<"Press x to exit.";
	savedata(2);
 	char ch=getch();
 	if(ch=='x')
 	exit(0);
 	Gameover();
}
void main()
{
	game OBJ;
	while(1)
	{
		OBJ.Draw();
		OBJ.Input();
		OBJ.Logic();
	}
}
