#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

char c='y';
long prize=0;
int q_no=1;
int no_of_ff=1;
int no_of_pof=1;
int no_of_ap=1;
void lifeline(int ,int );
void fifty_fifty(int );
void phone_a_friend(int );
void audience_poll(int );
void lost(int ,int );
void quit(int );
void final();
void setdist(int );
void pattern(int ,char );

void main()
{
	clrscr();
	int answer=0;
	int ca=0;
	int p_f=0,p_i=0;
	int k=0;
	int v;
	char am;
	char myline[500];
	gotoxy(28,7);
	cout<<"Welcome to Quiz Frenzy ";
	gotoxy(25,15);
	cout<<"Made by :	Mayuresh Konda";
	getch();
	clrscr();
	setdist(25);
	fstream f("Rules.dat",ios::in|ios::nocreate|ios::binary);
	while(!f.eof())
	{
		f.getline(myline,150);
		cout<<" "<<myline<<endl;
	}
	cout<<"\n\n Press any key to continue....";
	getch();
	f.close();
	clrscr();
	fstream a("Answers.dat",ios::in|ios::nocreate|ios::binary);
	fstream f1("Q2.dat",ios::in|ios::nocreate|ios::binary);
	p_f=f1.tellg();
	while(::c=='y')
	{
		f1.clear();
		if(::q_no>15)  final();
		choose_again:
		clrscr();
		setdist(70);cout<<"Quit<0>"<<endl;
		gotoxy(60,25);cout<<"Prize : "<<prize;
		gotoxy(1,2);
		if(q_no==k+1)
		{
			p_i=p_f;
			k++;
		}
		for(int i=0;i<6;i++)
		{
			f1.getline(myline,150);
			cout<<" "<<myline<<endl;
		}
		p_f=f1.tellg();
		v=p_f-p_i;
		a.get(am);
		ca=(int)(am)-48;
		cout<<"\n\n Enter the correct option ........ ";
		cout<<"\n Or enter 5 for lifeline ........... ";
		cout<<"\n\n Choice : ";
		cin>>answer;
		lost(answer,ca);
		if(answer==5)
		{
			f1.seekg(-v,ios::cur);
			a.seekg(-1,ios::cur);
		}
		if(!(answer>=0&&answer<=5))
		{
			clrscr();
			cout<<" Invalid option\n Choose again..... ";
			getch();
			f1.seekg(-v,ios::cur);
			a.seekg(-1,ios::cur);
			goto choose_again;
		}
		if(answer==0)
		{
			quit(ca);
			f1.seekg(-v,ios::cur);
			a.seekg(-1,ios::cur);
		}
	}
	f1.close();
	a.close();
	getch();
}

void lost(int answer, int ca)
{
	clrscr();
	if(answer==ca)
	{
		setdist(25);
		cout<<" Correct answer \n";
		setdist(25);
		if(::q_no<=5)
			::prize=::prize+1000;
		else if(::q_no>5&&q_no<=10)
			::prize=::prize+5000;
		else
			::prize=prize+10000;
		cout<<" You won Rs."<<::prize;
		delay(1000);
		//nosound();
		clrscr();
		if(::q_no<15)
			cout<<"\n\n Next question ";

		delay(1000);
		clrscr();
		::q_no++;

	}
	else
	{

		if(answer>=1&&answer<=4)
		{
			cout<<" Sorry mate..........\n"
			    <<" Wrong option........\n"
			    <<" The correct answer is "<<ca
			    <<"\n You lost \n";
			cout<<"\n\n";
			setdist(25);
			cout<<" You won Rs."<<prize;
			delay(1000);
			:: c='n';
		}
		else if(answer==5)
			lifeline(answer,ca);
	}
}

void final()
{
	clrscr();
	setdist(25);
	cout<<"!!!... Congratulations...!!!\n\n";
	setdist(31);
	cout<<" You won the game \n\n";
	setdist(31);
	cout<<" You won total of \n";setdist(36);
	cout<<"Rs. "<<::prize;
	getch();
	exit(0);
}

void fifty_fifty(int ca)
{
	randomize();
	int a=ca;
	int b=random(3)+1;
	if(a==b) b=a+1;
	cout<<"\n Answer may be "<<a<<" or "<<b<<".\n Goodluck ";
	getch();
}

void phone_a_friend(int ca)
{
	again:
	clrscr();
	int no;
	cout<<" Select from the foll. : \n\n"
	    <<"\n\n 1. Raj Verma"
	    <<"\n  Ph No. 9772504156"
	    <<"\n\n 2. Pradeep Kumar"
	    <<"\n  Ph No. 8866354245"
	    <<"\n\n 3. Anand Sharma"
	    <<"\n  Ph No. 8965412544"
	    <<"\n\n Choose from above : ";
	cin>>no;
	if(no>=1&&no<=3)
	{
		for( int i=0;i<=4;i++)
		{
			clrscr();
			gotoxy(25,12);
			cout<<" Calling ";
			for(int j=0;j<=10;j++)
			{
				cout<<".";
				delay(100);
			}
			clrscr();
		}
		gotoxy(1,3);
		pattern(80,'�');
		gotoxy(22,5);cout<<".......... Audio Transcript.......... ";
		for(i=4;i<=12;i++)
		{
			gotoxy(1,i);
			pattern(17,'�');
			gotoxy(64,i);
			pattern(17,'�');
		}
		gotoxy(25,9);cout<<" Hey buddy congratulations . ";
		gotoxy(28,10);cout<<" I'm gonna be short . ";
		gotoxy(19,11);cout<<" I heard the questions and the answers too . ";
		gotoxy(30,12);cout<<" Answer may be "<<ca<<" . ";
		gotoxy(1,13);pattern(80,'�');
		getch();
	}
	else
	{
		cout<<" \n\n You have to enter a valid choice....\n Try again \n";
		getch();
		goto again;
	}
}

void audience_poll(int ca)
{
	int a,b,c,d,e;
	a=random(100)+1;
	c=random(100)+1;
	if(a>=50)  a/=2;
	if(c>=50)  c/=2;
	e=a+c;
	if(e>35)
	{
		a=random(17)+1;
		c=35-a;
	}
	d=(a+c)/2;
	b=100-(a+c+d);
	clrscr();
	cout<<"\n The result is as follows \n";
	switch(ca)
	{
		case 1: cout<<" A - "<<b<<" %"<<endl
			    <<" B - "<<a<<" %"<<endl
			    <<" C - "<<c<<" %"<<endl
			    <<" D - "<<d<<" %"<<endl;
		break;

		case 2: cout<<" A - "<<a<<" %"<<endl
			    <<" B - "<<b<<" %"<<endl
			    <<" C - "<<c<<" %"<<endl
			    <<" D - "<<d<<" %"<<endl;
		break;

		case 3: cout<<" A - "<<c<<" %"<<endl
			    <<" B - "<<a<<" %"<<endl
			    <<" C - "<<b<<" %"<<endl
			    <<" D - "<<d<<" %"<<endl;
		break;

		case 4: cout<<" A - "<<d<<" %"<<endl
			    <<" B - "<<a<<" %"<<endl
			    <<" C - "<<c<<" %"<<endl
			    <<" D - "<<b<<" %"<<endl;
		break;

		default: cout<<" Internal error \n Try again\n";
			 ::no_of_ap=1;
		break;
	}
	getch();
}
void lifeline(int answer,int ca)
{
	if(::no_of_ff==0 && ::no_of_pof==0 && ::no_of_ap==0)
	{
		cout<<" Sorry......\n\n All your lifelines are exhausted \n\n";
		getch();
	}
	else
	{
		clrscr();
		cout<<"\n\n You chose a lifeline \n You have :\n\n";
		if(::no_of_ff==1)  cout<<"\n 1.Fifty-Fifty ";
		if(::no_of_pof==1) cout<<"\n 2.Phone a Friend ";
		if(::no_of_ap==1)  cout<<"\n 3.Audeince Poll ";
		cout<<"\n\n Press 4 to return ";
		abc:
		cout<<"\n\n Choose an option : ";
		cin>>answer;
		clrscr();
		if(answer==1&&::no_of_ff==1)
		{
			cout<<" You chose 50-50 ";
			delay(1500);
			::no_of_ff=0;
			fifty_fifty(ca);
		}
		else if(answer==2&&::no_of_pof==1)
		{
			cout<<" You chose Phone a Friend \n\n";
			delay(1500);
			::no_of_pof=0;
			phone_a_friend(ca);
		}
		else if(answer==3&&::no_of_ap==1)
		{
			cout<<" You chose Audience Poll ";
			delay(1500);
			::no_of_ap=0;
			audience_poll(ca);
		}
		else if(answer==4)
		{}
		else
		{
			cout<<" Enter proper choice ";
			goto abc;
		}
	}
}
void setdist(int a)
{
	for(int i=0;i<=a;i++)
	{
		cout<<" ";
	}
}
void pattern(int n,char ch)
{
	for(int i=0;i<n;i++)
		cout<<ch;
}

void quit(int ca)
{
	clrscr();
	cout<<" So you want to quit \n\n";
	if(::no_of_ff==0 && ::no_of_pof==0 && ::no_of_ap==0)
	{
		cout<<" Sorry you cannot do that.\n You used all your lifelines \n";
		getch();
	}
	else
	{
		cout<<" The correct answer was "<<ca;
		cout<<"\n No matter buddy.....";
		cout<<"\n You played well.....\n\n";
		setdist(31);
		cout<<" You won total of \n";setdist(36);
		cout<<"Rs. "<<::prize;
		getch();
		exit(0);
	}
}
