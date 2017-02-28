#include<bits/stdc++.h>
#include<stdio.h>
#include<cstring>
using namespace std;
typedef int ii;
#define MAX 24
template <class Type>
 class queuee
 {
  Type que[MAX];
  int front,rear;
  public:
  void init()
  {
  	front=rear=-1;
  }
  void insert(Type ch);
  Type popp();
 };
 char user_team[100];
class player  //player - completed ==needs approval
{
	public:
	char player_name[20];
	ii player_age;
	char player_position[10];
	ii player_jersy_no;
	ii ball_control;
	ii shooting;
	ii passing;
	ii overall;
};

		
class X;

class project //project equivalent team class
{
	public:
	char team_name[20];
	ii id;
	ii team_matches_played; 
	ii team_matches_won;
	ii winning_attribute;	
	ii attack;
	ii mid;
	ii defence;
	
	player pp[11];
	ii team_confidence;
	ii team_rank;
	ii team_popularity;
	ii home_advt;
	ii team_rating;
	 X winner(project &,project &);
	 ii popular_player(project,project);
	 void update_grow();
	 void update_down();
	//friend void update_points_table(X);
};
class X
{
	public:
	project qwerty[2];
	//project *qwerty2;
	
};
//X winner(project ,project);
project obp[17];
void project_read()
{
	FILE *fp1,*fp2;
	fp1=fopen("project.txt","r");
	fp2=fopen("player.txt","r");
	ii i=0;
	while(i<16)
	{
		fscanf(fp1,"%s%d%d%d%d%d%d%d%d%d%d%d%d%d",obp[i].team_name,&obp[i].id,&obp[i].team_matches_played,&obp[i].team_matches_won,&obp[i].winning_attribute,&obp[i].team_confidence,&obp[i].team_rank,&obp[i].team_popularity,&obp[i].home_advt,&obp[i].team_rating,&obp[i].attack,&obp[i].mid,&obp[i].defence);
		//cout<<obp[i].team_name<<endl;
		ii j=0;
		while(j<11)
		{
			fscanf(fp2,"%s%d%s%d%d%d%d%d",obp[i].pp[j].player_name,&obp[i].pp[j].player_age,obp[i].pp[j].player_position,&obp[i].pp[j].player_jersy_no,&obp[i].pp[j].overall,&obp[i].pp[j].ball_control,&obp[i].pp[j].shooting,&obp[i].pp[j].passing);
		//	cout<<obp[i].pp[j].player_name<<endl;//obp[i].pp[j].player_age<<obp[i].pp[j].player_position<<obp[i].pp[j].player_jersy_no<<obp[i].pp[j].overall<<obp[i].pp[j].ball_control<<obp[i].pp[j].shooting<<obp[i].pp[j].passing<<endl<<endl;
			
			j++;
		}
		//cout<<endl;
		i++;
	}
	fclose(fp1);
	fclose(fp2);
}
class point_table_group //pts table display fun
{
	public:
	char team_name[4][20];
	int goal_scored[4];
	int goal_diff[4];
	int team_point[4];
	point_table_group()
	{
		ii i;
		for(i=0;i<4;i++){
		goal_scored[i]=0;
		goal_diff[i]=0;
		team_point[i]=0;
	}
}
};																								//We have to form an object of each group as g1,g2,g3,g4;
class finale
{
	public:
	project f[2];
	static int counter3;
	
		void set_finals_team(project t1)
		{
			f[counter3++]=t1;
		}
		finale(){ }
		X winner3(project &,project &);
};
int finale::counter3=0;
finale finalf;

class semi_final
{
	public:
	project sf[5];
	static int counter1;
	
		semi_final()
		{
		
		}
		void set_semi_finals_team(project t1)
		{
			sf[counter1++]=t1;
		}
		 X winner2(project &,project &);
};
int semi_final::counter1=0;
semi_final semif;

class qfinal
{
	public:
	project qf[9];
	static int counter;
		qfinal()
		{
		
		}
		void set_qfinal_team(project t1)
		{
			qf[counter++]=t1;
		}
		 X winner1(project &,project &);
};
int qfinal::counter=0;
qfinal quaterf;
// vaibhav ka code//

class grp_A:public point_table_group
{
	public:
	project a;
	project b;
	project c;
	project d;
	grp_A()
	{
		
	}
	void update_points_table(X);
		void input();
};

class grp_B:public point_table_group
{
	public:
	project a;
	project b;
	project c;
	project d;
	void update_points_table(X);
		void input();
};
class grp_C:public point_table_group
{
	public:
	project a;
	project b;
	project c;
	project d;
	
	void update_points_table(X);
		void input();
};
class grp_D:public point_table_group
{
	public:
	project a;
	project b;
	project c;
	project d;
	void update_points_table(X);
		void input();
};

ii project::popular_player(project o1,project o2)
{
	ii i,c1=0,c2=0,c;
	for(i=0;i<11;i++)
	{
		if(o1.pp[i].overall>=85)
			c1++;
		if(o2.pp[i].overall>=85)
			c2++;
	}
	c=c1*10+c2;
	return c;
}
void project:: update_grow()
{
	team_confidence+=2;
	team_popularity+=1;
	attack+=1;
}
void project::update_down() //check for zero
{
	team_confidence-=2;
	team_popularity-=1;
	defence=-1;
}


X project::winner(project &o1,project &o2)
{
	//cout<<"YYY";
	double WinProb_A=0,WinProb_B=0;
	if(o1.home_advt==1)
	WinProb_A=0.5;
	else 
	WinProb_B=0.5;
	if(o1.team_confidence>o2.team_confidence)
	{
		WinProb_A+=(double)((o1.team_confidence-o2.team_confidence)/10);
	}
	else
	{
		WinProb_B+=(double)((o2.team_confidence-o1.team_confidence)/10);
	}
	if(o1.team_popularity>o2.team_popularity)
	{
		WinProb_A+=(double)((o1.team_popularity-o2.team_popularity)/10);
	}
	else
	{
		WinProb_B+=(double)((o2.team_popularity-o1.team_popularity)/10);
	}
	ii x=o1.attack+o1.mid+o1.defence;
	ii y=o2.attack+o2.mid+o2.defence;
	if(x>y)
		WinProb_A+=(double)(abs(x-y)/10);
	else
		WinProb_B+=(double)(abs(x-y)/10);
 	ii win=o1.popular_player(o1,o2);  /*This is the function for popular players in a team*/
 	ii B_win=win%10;
 		win/=10;
 	ii A_win=win;
 	x=abs(A_win-B_win);
 	if(A_win>B_win)
 	WinProb_A+=(double)(abs(x/40));
 	else
 	WinProb_B+=(double)(abs(x/40));
 	if(WinProb_A-WinProb_B>0.0001)
 	{
 		o1.update_grow(); // Function for growth in team after winning//
 		o2.update_down(); // Function for reducing Qualties after loss//
		o1.winning_attribute=1;
		o2.winning_attribute=0;
 	}
 	else 
 	{
 		o2.update_grow(); // Function for growth in team after winning//
 		o1.update_down(); // Function for reducing Qualties after loss//
		o1.winning_attribute=0;
		o2.winning_attribute=1;
 	}
	X xxx;
	xxx.qwerty[0]=o1;
	xxx.qwerty[1]=o2;
	//cout<<"NNN";
	return xxx;
 //	update_points_table(o1,o2);// For updation of points table// 
 	
}
/* problem starter*/


void grp_A::input()
{
queuee <class project>qu;
		project f,ss;
		qu.init();
		int ar[120],ar1[12],k=1,m=0,l,i,j,r,p,q,s;
	srand(time(NULL));
	for(i=1;i<=4;i++)
	{
		for(j=i+1;j<=4;j++)
		{
			ar[k]=i*10+j;
			k++;
			ar[k]=j*10+i;
			k++;
		}
	}
	while(k!=1)
	{
	s=rand()%12+1;
//	cout<<s<<endl;
	if(ar[s]!=0 && r!=s)
	{
	//cout<<" "<<ar[s]<<endl;
	p=ar[s]%10;
	q=ar[s]/10;
	
	//cout<<q<<" "<<p<<endl;
	k--;
	//cout<<a.id<<" "<<b.id<<" "<<c.id<<" "<<d.id<<endl;
	//cout<<p<<" "<<q<<endl;
	if(a.id==p)
	{
		 f=a;
	}
	else if(a.id==q)
	{
		 ss=a;
	}
	if(b.id==p)
	{
		f=b;
	}
	else if(b.id==q)
	{
		ss=b;
	}
	if(c.id==p)
	{
		 f=c;
	}
	else if(c.id==q)
	{
		 ss=c;
	}
	if(d.id==p)
	{
		 f=d;
	}
	else if(d.id==q)
	{
		 ss=d;
	}
	
	qu.insert(f);
	qu.insert(ss);
}
	ar[s]=0;
	r=s;
	
	}
	char sss;
	int count=0;
	X xxx;
	while(count!=12)
	{
		project vv=qu.popp();
		project vo=qu.popp();
		
		cout<<vv.team_name<<"V/S"<<vo.team_name<<endl;
		//cout<<vv.id<<" "<<vo.id<<endl;
		 xxx=vv.winner(vv,vo);
		if(xxx.qwerty[0].winning_attribute==1)
		cout<<xxx.qwerty[0].team_name<<" IS WINNER"<<endl;
		else
		cout<<xxx.qwerty[1].team_name<<" IS WINNER"<<endl;
		this->update_points_table(xxx);
		cout<<"Press Any KEY to Continue"<<endl;
		sss=getche();
		count++;
	}
//	cout<<endl;
	

	ii maximum=-1;
	ii index1,index2;
	for(i=0;i<4;i++)
	{
		if(this->team_point[i]>maximum)
		{
			index1=i;
			maximum=this->team_point[i];
		}
		
	}
	this->team_point[index1]=-1;
	maximum=-1;
	for(i=0;i<4;i++)
	{
		if(this->team_point[i]>maximum)
		{
			index2=i;
			maximum=this->team_point[i];
		}
		
	}
	//cout<<this->team_name[index1]<<" "<<this->team_name[index2]<<" ";
	this->team_point[index2]=-1;
	if(strcmp(this->team_name[index1],a.team_name)==0 || strcmp(this->team_name[index2],a.team_name)==0)
	{
			quaterf.set_qfinal_team(a);
	}
	if(strcmp(this->team_name[index1],b.team_name)==0 || strcmp(this->team_name[index2],b.team_name)==0)
	{
			quaterf.set_qfinal_team(b);
	}
	if(strcmp(this->team_name[index1],c.team_name)==0 || strcmp(this->team_name[index2],c.team_name)==0)
	{
			quaterf.set_qfinal_team(c);
	}
	if(strcmp(this->team_name[index1],d.team_name)==0 || strcmp(this->team_name[index2],d.team_name)==0)
	{
			quaterf.set_qfinal_team(d);
	}
	cout<<endl;
}

void grp_B::input()
{
		queuee <class project>qu;
		project f,ss;
		qu.init();
		int ar[120],ar1[12],k=1,m=0,l,i,j,r,p,q,s;
	srand(time(NULL));
	for(i=1;i<=4;i++)
	{
		for(j=i+1;j<=4;j++)
		{
			ar[k]=i*10+j;
			k++;
			ar[k]=j*10+i;
			k++;
		}
	}
	while(k!=1)
	{
	s=rand()%12+1;
//	cout<<s<<endl;
	if(ar[s]!=0 && r!=s)
	{
	//cout<<" "<<ar[s]<<endl;
	p=ar[s]%10;
	q=ar[s]/10;
	
	//cout<<q<<" "<<p<<endl;
	k--;
	
	
	if(a.id==p)
	{
		 f=a;
	}
	else if(a.id==q)
	{
		 ss=a;
	}
	if(b.id==p)
	{
		f=b;
	}
	else if(b.id==q)
	{
		ss=b;
	}
	if(c.id==p)
	{
		 f=c;
	}
	else if(c.id==q)
	{
		 ss=c;
	}
	if(d.id==p)
	{
		 f=d;
	}
	else if(d.id==q)
	{
		 ss=d;
	}
	
	qu.insert(f);
	qu.insert(ss);
}
ar[s]=0;
	r=s;
	
	}
	int count=0;
	X xxx;
	while(count!=12)
	{
		project vv=qu.popp();
		project vo=qu.popp();
		vv.home_advt=1;
	//	cout<<vv.id<<" "<<vo.id<<endl;
		xxx=vv.winner(vv,vo);
		this->update_points_table(xxx);
		count++;
	}
	ii maximum=-1;
	ii index1,index2;
	for(i=0;i<4;i++)
	{
		if(this->team_point[i]>maximum)
		{
			index1=i;
			maximum=this->team_point[i];
		}
		
	}
	this->team_point[index1]=-1;
	maximum=-1;
	for(i=0;i<4;i++)
	{
		if(this->team_point[i]>maximum)
		{
			index2=i;
			maximum=this->team_point[i];
		}
		
	}
	this->team_point[index2]=-1;
	if(strcmp(this->team_name[index1],a.team_name)==0 || strcmp(this->team_name[index2],a.team_name)==0)
	{
			quaterf.set_qfinal_team(a);
	}
	if(strcmp(this->team_name[index1],b.team_name)==0 || strcmp(this->team_name[index2],b.team_name)==0)
	{
			quaterf.set_qfinal_team(b);
	}
	if(strcmp(this->team_name[index1],c.team_name)==0 || strcmp(this->team_name[index2],c.team_name)==0)
	{
			quaterf.set_qfinal_team(c);
	}
	if(strcmp(this->team_name[index1],d.team_name)==0 || strcmp(this->team_name[index2],d.team_name)==0)
	{
			quaterf.set_qfinal_team(d);
	}
	cout<<endl;
	
}

void grp_C::input()
{
		queuee <class project>qu;
		project f,ss;
		qu.init();
		int ar[120],ar1[12],k=1,m=0,l,i,j,r,p,q,s;
	srand(time(NULL));
	for(i=1;i<=4;i++)
	{
		for(j=i+1;j<=4;j++)
		{
			ar[k]=i*10+j;
			k++;
			ar[k]=j*10+i;
			k++;
		}
	}
	while(k!=1)
	{
	s=rand()%12+1;
//	cout<<s<<endl;
	if(ar[s]!=0 && r!=s)
	{
	//cout<<" "<<ar[s]<<endl;
	p=ar[s]%10;
	q=ar[s]/10;
	
	//cout<<q<<" "<<p<<endl;
	k--;
	
	
	if(a.id==p)
	{
		 f=a;
	}
	else if(a.id==q)
	{
		 ss=a;
	}
	if(b.id==p)
	{
		f=b;
	}
	else if(b.id==q)
	{
		ss=b;
	}
	if(c.id==p)
	{
		 f=c;
	}
	else if(c.id==q)
	{
		 ss=c;
	}
	if(d.id==p)
	{
		 f=d;
	}
	else if(d.id==q)
	{
		 ss=d;
	}
	
	qu.insert(f);
	qu.insert(ss);
}
ar[s]=0;
	r=s;
	
	}
	int count=0;
	X xxx;
	while(count!=12)
	{
		project vv=qu.popp();
		project vo=qu.popp();
		vv.home_advt=1;
		//cout<<vv.id<<" "<<vo.id<<endl;
		xxx=vv.winner(vv,vo);
		this->update_points_table(xxx);
		count++;
	}
	ii maximum=-1;
	ii index1,index2;
	for(i=0;i<4;i++)
	{
		if(this->team_point[i]>maximum)
		{
			index1=i;
			maximum=this->team_point[i];
		}
		
	}
	this->team_point[index1]=-1;
	maximum=-1;
	for(i=0;i<4;i++)
	{
		if(this->team_point[i]>maximum)
		{
			index2=i;
			maximum=this->team_point[i];
		}
		
	}
	this->team_point[index2]=-1;
		if(strcmp(this->team_name[index1],a.team_name)==0 || strcmp(this->team_name[index2],a.team_name)==0)
	{
			quaterf.set_qfinal_team(a);
	}
	if(strcmp(this->team_name[index1],b.team_name)==0 || strcmp(this->team_name[index2],b.team_name)==0)
	{
			quaterf.set_qfinal_team(b);
	}
	if(strcmp(this->team_name[index1],c.team_name)==0 || strcmp(this->team_name[index2],c.team_name)==0)
	{
			quaterf.set_qfinal_team(c);
	}
	if(strcmp(this->team_name[index1],d.team_name)==0 || strcmp(this->team_name[index2],d.team_name)==0)
	{
			quaterf.set_qfinal_team(d);
	}
	cout<<endl;
	
}

void grp_D::input()
{
		queuee <class project>qu;
		project f,ss;
		qu.init();
		int ar[120],ar1[12],k=1,m=0,l,i,j,r,p,q,s;
	srand(time(NULL));
	for(i=1;i<=4;i++)
	{
		for(j=i+1;j<=4;j++)
		{
			ar[k]=i*10+j;
			k++;
			ar[k]=j*10+i;
			k++;
		}
	}
	while(k!=1)
	{
	s=rand()%12+1;
//	cout<<s<<endl;
	if(ar[s]!=0 && r!=s)
	{
	//cout<<" "<<ar[s]<<endl;
	p=ar[s]%10;
	q=ar[s]/10;
	
	//cout<<q<<" "<<p<<endl;
	k--;
	
	
	if(a.id==p)
	{
		 f=a;
	}
	else if(a.id==q)
	{
		 ss=a;
	}
	if(b.id==p)
	{
		f=b;
	}
	else if(b.id==q)
	{
		ss=b;
	}
	if(c.id==p)
	{
		 f=c;
	}
	else if(c.id==q)
	{
		 ss=c;
	}
	if(d.id==p)
	{
		 f=d;
	}
	else if(d.id==q)
	{
		 ss=d;
	}
	
	qu.insert(f);
	qu.insert(ss);
	}
	ar[s]=0;
	r=s;
	
	}
	int count=0;
	X xxx;
	while(count!=12)
	{
		project vv=qu.popp();
		project vo=qu.popp();
		vv.home_advt=1;
		//cout<<vv.id<<" "<<vo.id<<endl;
		xxx=vv.winner(vv,vo);
		this->update_points_table(xxx);
		count++;
	}
	ii maximum=-1;
	ii index1,index2;
	for(i=0;i<4;i++)
	{
		if(this->team_point[i]>maximum)
		{
			index1=i;
			maximum=this->team_point[i];
		}
		
	}
	this->team_point[index1]=-1;
	maximum=-1;
	for(i=0;i<4;i++)
	{
		if(this->team_point[i]>maximum)
		{
			index2=i;
			maximum=this->team_point[i];
		}
		
	}
	this->team_point[index2]=-1;
		if(strcmp(this->team_name[index1],a.team_name)==0 || strcmp(this->team_name[index2],a.team_name)==0)
	{
			quaterf.set_qfinal_team(a);
	}
	if(strcmp(this->team_name[index1],b.team_name)==0 || strcmp(this->team_name[index2],b.team_name)==0)
	{
			quaterf.set_qfinal_team(b);
	}
	if(strcmp(this->team_name[index1],c.team_name)==0 || strcmp(this->team_name[index2],c.team_name)==0)
	{
			quaterf.set_qfinal_team(c);
	}
	if(strcmp(this->team_name[index1],d.team_name)==0 || strcmp(this->team_name[index2],d.team_name)==0)
	{
			quaterf.set_qfinal_team(d);
	}
	cout<<endl;
	
}


/*
 ---------------------------------------------------------------
 insert function
 ---------------------------------------------------------------
 */
 template <class Type>void queuee<Type>::insert(Type item)
 {
 //	cout<<"INSERT";
  if (rear>=MAX)
  {
  cout << "Queue is full\n";
  return;
  }
  if(front==-1)
   front++;
  que[++rear] = item;//inserting the item in the Que
 }
 /*
 ---------------------------------------------------------------
 pop function
 ---------------------------------------------------------------
 */
template <class Type>Type queuee<Type>::popp()
 {
 //	cout<<"POPPOP";
  Type val;
  if((front==-1)||(front>rear))
  {
  cout << "Queue is empty\n";
  exit(0); // return null on empty stack
  }
  val= que[front];//item to be deleted
  front++;
  return val;
 }

// vaibhav ka code khtm//

/* Here come's the algorithm;*/
	X xxx;
X qfinal:: winner1(project &o1,project &o2)
{
	
	double WinProb_A=0,WinProb_B=0;
	if(o1.home_advt==1)
	WinProb_A=0.5;
	else 
	WinProb_B=0.5;
	if(o1.team_confidence>o2.team_confidence)
	{
		WinProb_A+=(double)((o1.team_confidence-o2.team_confidence)/10);
	}
	else
	{
		WinProb_B+=(double)((o2.team_confidence-o1.team_confidence)/10);
	}
	if(o1.team_popularity>o2.team_popularity)
	{
		WinProb_A+=(double)((o1.team_popularity-o2.team_popularity)/10);
	}
	else
	{
		WinProb_B+=(double)((o2.team_popularity-o1.team_popularity)/10);
	}
	ii x=o1.attack+o1.mid+o1.defence;
	ii y=o2.attack+o2.mid+o2.defence;
	if(x>y)
		WinProb_A+=(double)(abs(x-y)/10);
	else
		WinProb_B+=(double)(abs(x-y)/10);
 	ii win=o1.popular_player(o1,o2);  /*This is the function for popular players in a team*/
 	ii B_win=win%10;
 		win/=10;
 	ii A_win=win;
 	x=abs(A_win-B_win);
 	if(A_win>B_win)
 	WinProb_A+=(double)(abs(x/40));
 	else
 	WinProb_B+=(double)(abs(x/40));
 	if(WinProb_A-WinProb_B>0.0001)
 	{
 		o1.update_grow(); // Function for growth in team after winning//
 		o2.update_down(); // Function for reducing Qualties after loss//
		o1.winning_attribute=1;
		o2.winning_attribute=0;
 	}
 	else 
 	{
 		o2.update_grow(); // Function for growth in team after winning//
 		o1.update_down(); // Function for reducing Qualties after loss//
		o1.winning_attribute=0;
		o2.winning_attribute=1;
 	}
//	X xxx;
	xxx.qwerty[0]=o1;
	xxx.qwerty[1]=o2;
	return xxx;//update_points_table(o1,o2);// For updation of points table// 
 	
}


X semi_final:: winner2(project &o1,project &o2)
{
	
	double WinProb_A=0,WinProb_B=0;
	if(o1.home_advt==1)
	WinProb_A=0.5;
	else 
	WinProb_B=0.5;
	if(o1.team_confidence>o2.team_confidence)
	{
		WinProb_A+=(double)((o1.team_confidence-o2.team_confidence)/10);
	}
	else
	{
		WinProb_B+=(double)((o2.team_confidence-o1.team_confidence)/10);
	}
	if(o1.team_popularity>o2.team_popularity)
	{
		WinProb_A+=(double)((o1.team_popularity-o2.team_popularity)/10);
	}
	else
	{
		WinProb_B+=(double)((o2.team_popularity-o1.team_popularity)/10);
	}
	ii x=o1.attack+o1.mid+o1.defence;
	ii y=o2.attack+o2.mid+o2.defence;
	if(x>y)
		WinProb_A+=(double)(abs(x-y)/10);
	else
		WinProb_B+=(double)(abs(x-y)/10);
 	ii win=o1.popular_player(o1,o2);  /*This is the function for popular players in a team*/
 	ii B_win=win%10;
 		win/=10;
 	ii A_win=win;
 	x=abs(A_win-B_win);
 	if(A_win>B_win)
 	WinProb_A+=(double)(abs(x/40));
 	else
 	WinProb_B+=(double)(abs(x/40));
 	if(WinProb_A-WinProb_B>0.0001)
 	{
 		o1.update_grow(); // Function for growth in team after winning//
 		o2.update_down(); // Function for reducing Qualties after loss//
		o1.winning_attribute=1;
		o2.winning_attribute=0;
 	}
 	else 
 	{
 		o2.update_grow(); // Function for growth in team after winning//
 		o1.update_down(); // Function for reducing Qualties after loss//
		o1.winning_attribute=0;
		o2.winning_attribute=1;
 	}
//	X xxx;
	xxx.qwerty[0]=o1;
	xxx.qwerty[1]=o2;
	return xxx;//update_points_table(o1,o2);// For updation of points table// 
 	
}


X finale:: winner3(project &o1,project &o2)
{
	
	double WinProb_A=0,WinProb_B=0;
	if(o1.home_advt==1)
	WinProb_A=0.5;
	else 
	WinProb_B=0.5;
	if(o1.team_confidence>o2.team_confidence)
	{
		WinProb_A+=(double)((o1.team_confidence-o2.team_confidence)/10);
	}
	else
	{
		WinProb_B+=(double)((o2.team_confidence-o1.team_confidence)/10);
	}
	if(o1.team_popularity>o2.team_popularity)
	{
		WinProb_A+=(double)((o1.team_popularity-o2.team_popularity)/10);
	}
	else
	{
		WinProb_B+=(double)((o2.team_popularity-o1.team_popularity)/10);
	}
	ii x=o1.attack+o1.mid+o1.defence;
	ii y=o2.attack+o2.mid+o2.defence;
	if(x>y)
		WinProb_A+=(double)(abs(x-y)/10);
	else
		WinProb_B+=(double)(abs(x-y)/10);
 	ii win=o1.popular_player(o1,o2);  /*This is the function for popular players in a team*/
 	ii B_win=win%10;
 		win/=10;
 	ii A_win=win;
 	x=abs(A_win-B_win);
 	if(A_win>B_win)
 	WinProb_A+=(double)(abs(x/40));
 	else
 	WinProb_B+=(double)(abs(x/40));
 	if(WinProb_A-WinProb_B>0.0001)
 	{
 		o1.update_grow(); // Function for growth in team after winning//
 		o2.update_down(); // Function for reducing Qualties after loss//
		o1.winning_attribute=1;
		o2.winning_attribute=0;
 	}
 	else 
 	{
 		o2.update_grow(); // Function for growth in team after winning//
 		o1.update_down(); // Function for reducing Qualties after loss//
		o1.winning_attribute=0;
		o2.winning_attribute=1;
 	}

	xxx.qwerty[0]=o1;
	xxx.qwerty[1]=o2;
	return xxx;//update_points_table(o1,o2);// For updation of points table// 
 	
}


// For popular players
// Recent Changes//
void grp_A:: update_points_table(X xxx)
{
//	cout<<"Y"<<" ";
	int maxi,mini;
	project o1=xxx.qwerty[0];
	project o2=xxx.qwerty[1];
		ii s=rand()%5+0;
		ii p=rand()%5+0;
		
		while(p==s)
			p=rand()%5+0;
			//cout<<p<<" "<<s<<endl;
		if(s>p)
		{
			maxi=s;
			mini=p;
		}
		else
		{
			maxi=p;
			mini=s;
			
		}
		int i,store1,store2;
		for(i=0;i<4;i++)
		{
			//cout<<team_name[i]<<" ";
			if(strcmp(o1.team_name,this->team_name[i])==0)
				store1=i;
			if(strcmp(o2.team_name,this->team_name[i])==0)
				store2=i;
		}
	//	cout<<"1"<<" ";	
		
		if(o1.winning_attribute==1)
		{
	//		cout<<"2"<<endl;;
			this->team_point[store1]+=3;
			this->goal_scored[store1]+=maxi;
			this->goal_scored[store2]+=mini;
			this->goal_diff[store1]+=(maxi-mini);
			this->goal_diff[store2]-=(maxi-mini);
		}
		else
		{
		//	cout<<"2"<<endl;
			this->team_point[store2]+=3;
			this->goal_scored[store2]+=maxi;
			this->goal_scored[store1]+=mini;
			this->goal_diff[store2]+=(maxi-mini);
			this->goal_diff[store1]-=(maxi-mini);
		
		}
}

void grp_B:: update_points_table(X xxx)
{
	//cout<<"Y"<<" ";
	int maxi,mini;
	project o1=xxx.qwerty[0];
	project o2=xxx.qwerty[1];
		ii s=rand()%5+0;
		ii p=rand()%5+0;
		while(p==s)
			p=rand()%5+0;
	//		cout<<p<<" "<<s;
		if(s>p)
		{
			maxi=s;
			mini=p;
		}
		else
		{
			maxi=p;
			mini=s;
			
		}
		ii i,store1,store2;
	//	cout<<o1.team_name<<" "<<o2.team_name;
		for(i=0;i<4;i++)
		{
			//cout<<team_name[i]<<" ";
			if(strcmp(o1.team_name,this->team_name[i])==0)
				store1=i;
			if(strcmp(o2.team_name,this->team_name[i])==0)
				store2=i;
		}
	//	
		
	//	cout<<team_name[0];
	//	cout<<store1<<" "<<store2;	
		if(o1.winning_attribute==1)
		{
			this->team_point[store1]+=3;
			this->goal_scored[store1]+=maxi;
			this->goal_scored[store2]+=mini;
			this->goal_diff[store1]+=(maxi-mini);
			this->goal_diff[store2]-=(maxi-mini);
		}
		else
		{
	
			this->team_point[store2]+=3;
			this->goal_scored[store2]+=maxi;
			this->goal_scored[store1]+=mini;
			this->goal_diff[store2]+=(maxi-mini);
			this->goal_diff[store1]-=(maxi-mini);
		
		}
	//	cout<<"XX";
		cout<<endl;
}

void grp_C:: update_points_table(X xxx)
{
	//cout<<"Y"<<" ";
	int maxi,mini;
	project o1=xxx.qwerty[0];
	project o2=xxx.qwerty[1];
		ii s=rand()%5+0;
		ii p=rand()%5+0;
		while(p==s)
			p=rand()%5+0;
		if(s>p)
		{
			maxi=s;
			mini=p;
		}
		else
		{
			maxi=p;
			mini=s;
			
		}
		int i,store1,store2;
		for(i=0;i<4;i++)
		{
			//cout<<team_name[i]<<" ";
			if(strcmp(o1.team_name,this->team_name[i])==0)
				store1=i;
			if(strcmp(o2.team_name,this->team_name[i])==0)
				store2=i;
		}
			
		if(o1.winning_attribute==1)
		{
			this->team_point[store1]+=3;
			this->goal_scored[store1]+=maxi;
			this->goal_scored[store2]+=mini;
			this->goal_diff[store1]+=(maxi-mini);
			this->goal_diff[store2]-=(maxi-mini);
		}
		else
		{
	
			this->team_point[store2]+=3;
			this->goal_scored[store2]+=maxi;
			this->goal_scored[store1]+=mini;
			this->goal_diff[store2]+=(maxi-mini);
			this->goal_diff[store1]-=(maxi-mini);
		
		}
		cout<<endl;
}

void grp_D::update_points_table(X xxx)
{
//	cout<<"Y"<<" ";
	int maxi,mini;
	project o1=xxx.qwerty[0];
	project o2=xxx.qwerty[1];
		ii s=rand()%5+0;
		ii p=rand()%5+0;
		while(p==s)
			p=rand()%5+0;
		if(s>p)
		{
			maxi=s;
			mini=p;
		}
		else
		{
			maxi=p;
			mini=s;
			
		}
		int i,store1,store2;
		for(i=0;i<4;i++)
		{
			//cout<<team_name[i]<<" ";
			if(strcmp(o1.team_name,this->team_name[i])==0)
				store1=i;
			if(strcmp(o2.team_name,this->team_name[i])==0)
				store2=i;
		}
	//		
		if(o1.winning_attribute==1)
		{
			this->team_point[store1]+=3;
			this->goal_scored[store1]+=maxi;
			this->goal_scored[store2]+=mini;
			this->goal_diff[store1]+=(maxi-mini);
			this->goal_diff[store2]-=(maxi-mini);
		}
		else
		{
	
			this->team_point[store2]+=3;
			this->goal_scored[store2]+=maxi;
			this->goal_scored[store1]+=mini;
			this->goal_diff[store2]+=(maxi-mini);
			this->goal_diff[store1]-=(maxi-mini);
		
		}
}
//project q1,q2;
X xxx1;
void Quater_FINAL_MATCHES()
{
	for(ii i=0;i<8;i++)
	{
		cout<<quaterf.qf[i].team_name<<endl;
	}
	cout<<endl;
	 xxx1=quaterf.winner1(quaterf.qf[0],quaterf.qf[4]); 
	if(xxx1.qwerty[0].winning_attribute==1)
	semif.set_semi_finals_team(xxx1.qwerty[0]);
	else
	semif.set_semi_finals_team(xxx1.qwerty[1]);
	
	 xxx1=quaterf.winner1(quaterf.qf[1],quaterf.qf[6]);
	if(xxx1.qwerty[0].winning_attribute==1)
	semif.set_semi_finals_team(xxx1.qwerty[0]);
	else
	semif.set_semi_finals_team(xxx1.qwerty[1]);
	
	 xxx1=quaterf.winner1(quaterf.qf[2],quaterf.qf[5]);
	if(xxx1.qwerty[0].winning_attribute==1)
	semif.set_semi_finals_team(xxx1.qwerty[0]);
	else
	semif.set_semi_finals_team(xxx1.qwerty[1]);
	
	 xxx1=quaterf.winner1(quaterf.qf[3],quaterf.qf[7]);
	if(xxx1.qwerty[0].winning_attribute==1)
	semif.set_semi_finals_team(xxx1.qwerty[0]);
	else
	semif.set_semi_finals_team(xxx1.qwerty[1]);
}
	X xxx2;
void SEMI_FINAL_MATCHES()
{
	for(ii i=0;i<4;i++)
	{
		cout<<semif.sf[i].team_name<<endl;
	}
	cout<<endl;
	xxx2=semif.winner2(semif.sf[0],semif.sf[2]);
	if(xxx2.qwerty[0].winning_attribute==1)
		finalf.set_finals_team(xxx2.qwerty[0]);
	else
		finalf.set_finals_team(xxx2.qwerty[1]);
	
	xxx2=semif.winner2(semif.sf[1],semif.sf[3]);
	if(xxx2.qwerty[0].winning_attribute==1)
		finalf.set_finals_team(xxx2.qwerty[0]);
	else
		finalf.set_finals_team(xxx2.qwerty[1]);
	
}
void group_display(const grp_A t1,const grp_B t2,const grp_C t3,const grp_D t4)
{
	cout<<"                                                 GROUP A"<<endl;
	cout<<t1.a.team_name<<endl<<t1.b.team_name<<endl<<t1.c.team_name<<endl<<t1.d.team_name<<endl;
	cout<<"                                                 GROUP B"<<endl;
	cout<<t2.a.team_name<<endl<<t2.b.team_name<<endl<<t2.c.team_name<<endl<<t2.d.team_name<<endl;
	cout<<"                                                 GROUP C"<<endl;
	cout<<t3.a.team_name<<endl<<t3.b.team_name<<endl<<t3.c.team_name<<endl<<t3.d.team_name<<endl;
	cout<<"                                                 GROUP D"<<endl;
	cout<<t4.a.team_name<<endl<<t4.b.team_name<<endl<<t4.c.team_name<<endl<<t4.d.team_name<<endl;
	cout<<endl<<endl<<endl<<endl;
	
}
void team_display(char str[20])
{
	ii i,j;
	for(i=0;i<16;i++)
	{
		if(strcmp(obp[i].team_name,str)==0)
		{
			for(j=0;j<11;j++)
			{
				cout<<obp[i].pp[j].player_name<<"       "<<obp[i].pp[j].overall<<endl;
			}
	
		}
	}
	
}
void start();
void play_tgif()
{
	FILE *fp;
	fp=fopen("team_name.txt","r");
	char str[20];
	ii i=0;
	while(i<16)
	{
		fscanf(fp,"%s",str);
		cout<<str<<endl;
		i++;
	}
	fclose(fp);
	cout<<"Want to choose a team press 1"<<endl;
	int value;
	cin>>value;
	if(value==1)
	{
		cout<<"Enter the name of the team you want to choose"<<endl;
		cin>>str;
		strcpy(user_team,str);
		team_display(str);
	}
	else
		start();
}


void team_comp()
{
	char ss1[20],ss2[20],counter=0;
	cout<<"Enter name of team1"<<endl;
	cin>>ss1;
	cout<<"Enter name of team2"<<endl;
	cin>>ss2;
	for(ii i=0;i<16;i++)
	{
		if(strcmp(obp[i].team_name,ss1)==0||strcmp(obp[i].team_name,ss2)==0)
		{
			cout<<"TEAM NAME IS "<<obp[i].team_name<<endl;
			cout<<"TOTAL MATCHES PLAYED ARE "<<obp[i].team_matches_played<<endl;
			cout<<"TOTAL MATCHES WON ARE "<<obp[i].team_matches_won<<endl;
			cout<<"TEAM CONFIDENCE IS "<<obp[i].team_confidence<<endl;
			cout<<"TEAM RANK IS "<<obp[i].team_rank<<endl;
			cout<<"TEAM POPULARITY IS "<<obp[i].team_popularity<<endl;
			cout<<"TEAM RATING IS "<<obp[i].team_rating<<endl;
			cout<<"ATTACK "<<obp[i].attack<<endl;
			cout<<"MIDDLE "<<obp[i].mid<<endl;
			cout<<"DEFENCE "<<obp[i].defence<<endl;
			counter++;
		}
	}
	if(counter!=2)
		cout<<"OOPS !!! NO such teams Exits"<<endl;
	start();
}

void player_comp()
{
	char ss1[20],ss2[20],counter=0;
	cout<<"Enter name of player1"<<endl;
	cin>>ss1;
	cout<<"Enter name of player2"<<endl;
	cin>>ss2;
	for(ii i=0;i<16;i++)
	{
		for(ii j=0;j<11;j++)
		{
			
			if(strcmp(obp[i].pp[j].player_name,ss1)==0||strcmp(obp[i].pp[j].player_name,ss2)==0)
			{
				cout<<"PLAYER NAME IS "<<obp[i].pp[j].player_name<<endl;
				cout<<"TEAM NAME IS "<<obp[i].team_name<<endl;
				cout<<"PLAYER AGE IS "<<obp[i].pp[j].player_age<<endl;
				cout<<"SQUAD NUMBER IS "<<obp[i].pp[j].player_jersy_no<<endl;
				cout<<"OVERALL RATING IS "<<obp[i].pp[j].overall<<endl;
				cout<<"DRIBBLING IS "<<obp[i].pp[j].ball_control<<endl;
				cout<<"PASSING IS "<<obp[i].pp[j].passing<<endl;
				cout<<"SHOOTING IS "<<obp[i].pp[j].shooting<<endl<<endl<<endl;
				counter++;
			}
		
		}
	}
	if(counter!=2)
		cout<<"OOPS!!! No such player Exits"<<endl;
	start();
}


void start()
{
	ii value;
	cout<<"1) PLAY TGIF"<<endl<<endl<<endl;
	cout<<"2) PLAYER COMPARISION"<<endl<<endl<<endl;
	cout<<"3) TEAM COMPARISION"<<endl<<endl<<endl;
	
	cin>>value;
	if(value==1)
		play_tgif();
	if(value==2)
		player_comp();
	if(value==3)
		team_comp();
	
}

void assign(grp_A &t1,grp_B &t2,grp_C &t3,grp_D &t4)
{
	int s,k,r[20]={0},count=0,arr[16],store[16]={0},count1=0;
	srand(time(NULL));
	k=17;
	while(k!=1)
	{
		s=rand()%16+0;
		if(r[s]==0)
		{	//count1++;
		//	cout<<s<<endl;
			if(store[s]==0){
			//	cout<<s<<" ";
			arr[count++]=s;
			k--;
			r[s]=1;
			store[s]++;
			}
		}
		
		
	}
//	cout<<count1;
	int i;
i=0;
	t1.a=obp[arr[i++]];
	//cout<<obp[arr[i-1]].team_name;
	strcpy(t1.team_name[0],obp[arr[i-1]].team_name);
	//cout<<obp[arr[i-1]]<<endl;
//	cout<<t1.team_name[0]<<endl;
	t1.b=obp[arr[i++]];
	strcpy(t1.team_name[1],obp[arr[i-1]].team_name);
//	cout<<t1.team_name[1]<<endl;
	t1.c=obp[arr[i++]];
	strcpy(t1.team_name[2],obp[arr[i-1]].team_name);
//	cout<<t1.team_name[2]<<endl;
	t1.d=obp[arr[i++]];
	strcpy(t1.team_name[3],obp[arr[i-1]].team_name);
//	cout<<t1.team_name[3]<<endl;
	t2.a=obp[arr[i++]];
	strcpy(t2.team_name[0],obp[arr[i-1]].team_name);
//	cout<<t2.team_name[0]<<endl;
	t2.b=obp[arr[i++]];
	strcpy(t2.team_name[1],obp[arr[i-1]].team_name);
//	cout<<t2.team_name[1]<<endl;
	t2.c=obp[arr[i++]];
	strcpy(t2.team_name[2],obp[arr[i-1]].team_name);
//	cout<<t2.team_name[2]<<endl;
	t2.d=obp[arr[i++]];
	strcpy(t2.team_name[3],obp[arr[i-1]].team_name);
//	cout<<t2.team_name[3]<<endl;
	t3.a=obp[arr[i++]];
	strcpy(t3.team_name[0],obp[arr[i-1]].team_name);
//	cout<<t3.team_name[0]<<endl;
	t3.b=obp[arr[i++]];
	strcpy(t3.team_name[1],obp[arr[i-1]].team_name);
//	cout<<t3.team_name[1]<<endl;
	t3.c=obp[arr[i++]];
	strcpy(t3.team_name[2],obp[arr[i-1]].team_name);
//	cout<<t3.team_name[2]<<endl;
	t3.d=obp[arr[i++]];
	strcpy(t3.team_name[3],obp[arr[i-1]].team_name);
//	cout<<t3.team_name[3]<<endl;
	t4.a=obp[arr[i++]];
	strcpy(t4.team_name[0],obp[arr[i-1]].team_name);
//	cout<<t4.team_name[0]<<endl;
	t4.b=obp[arr[i++]];
	strcpy(t4.team_name[1],obp[arr[i-1]].team_name);
//	cout<<t4.team_name[1]<<endl;
	t4.c=obp[arr[i++]];
	strcpy(t4.team_name[2],obp[arr[i-1]].team_name);
//	cout<<t4.team_name[2]<<endl;
	t4.d=obp[arr[i++]];
	strcpy(t4.team_name[3],obp[arr[i-1]].team_name);
//	cout<<t4.team_name[3]<<endl;
	t1.a.id=1;
	t1.b.id=2;
	t1.c.id=3;
	t1.d.id=4;
	t2.a.id=1;
	t2.b.id=2;
	t2.c.id=3;
	t2.d.id=4;
	t3.a.id=1;
	t3.b.id=2;
	t3.c.id=3;
	t3.d.id=4;
	t4.a.id=1;
	t4.b.id=2;
	t4.c.id=3;
	t4.d.id=4;
}
int main()
{
	X x_final;
	grp_A ob;
	grp_B ob1;
//	ob1.input();

	grp_C ob2;
//	ob2.input();

	grp_D ob3;
//	ob3.input();
	project_read();
	
	l:start();
	assign(ob,ob1,ob2,ob3);
	string ss;
	cout<<"Press P to Play"<<endl;
	cin>>ss;
	if(ss=="P")
		group_display(ob,ob1,ob2,ob3);
	else
		goto l;
	cout<<"Press C to continue"<<endl;
	cin>>ss;
	if(ss=="c" || ss=="C")
	{
		ob.input();
		ob1.input();
		ob2.input();
		ob3.input();
	}
	else
	{
		goto l;
	}
	Quater_FINAL_MATCHES();
	SEMI_FINAL_MATCHES();
	for(ii i=0;i<2;i++)
	{
		cout<<finalf.f[i].team_name<<endl;
	}
	cout<<endl;
	x_final=finalf.winner3(finalf.f[0],finalf.f[1]);
	if(x_final.qwerty[0].winning_attribute==1)
	{
		
		cout<<x_final.qwerty[0].team_name<<"is Winner"<<endl;
	}
	else
	{
		cout<<x_final.qwerty[1].team_name<<"is Winner"<<endl;
	}
	
	return 0;
}