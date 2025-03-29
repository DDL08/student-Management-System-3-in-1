#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student 
{
	int age;
	int sno;
	char sname[20];
	char gender[8];
	char nation[20];
};
struct node 
{
	student data;
	node *next;
};
//menu
void one_menu(node*,node* );//副菜单-2.阅览，遍历
void two_menu(node*,node* );//副菜单-3.排序
void three_menu(node*,node* );//副菜单-4.统计
void fourth_menu(node*,node* );//副菜单-5.修改
void main_menu(node*,node* );//主菜单
//inset
void creatfile();//单纯写，直接堆在文件中
void readfile();//读并输出文件中内容
void Convert_link(node*,node*);//转化为链表，单纯输出，
//sort
void sort_byname(node*,node*);//根据sname(姓名)的值从小到大的排序
void sort_bysno(node*phead,node*ptial);//根据sno(学号)的值从小到大的排序
void sort_byage(node*phead,node*ptial);//根据age(年龄)的值从小到大的排序
void sort_bygender(node*phead,node*ptial);//根据gender(性别)的值从小到大的排序
void sort_bynation(node*phead,node*ptial);//根据nation(民族)的值从小到大的排序
//statistics
void statistics_byage(node*phead,node*ptial);//输入年龄以获取人数
void statistics_bynation(node*phead,node*ptial);//输入民族以获取人数
void statistics_bygender(node*phead,node*ptial);//输入性别以获取人数
//delete
void sdelete_student_info_bysno(node*,node*);//通过学生学号删除信息
void wFile(node*phead,node*ptial);
//change
void modify_student_info_bysno(node*phead,node*ptial);//通过学生学号修改该学生信息
//find
void find_student_sno(node*,node*);//通过学号查找学生
void find_student_sname(node*,node*);//通过姓名查找学生
void find_student_age(node*,node*);//通过年龄查找学生
void find_student_gender(node*,node*);//通过性别查找学生
void find_student_nation(node*,node*);//通过民族查找学生
//free
void release(node*,node*);//释放空间
int main(void) 
{
	node *phead=(node*)malloc(sizeof(node));
	phead->next=NULL;
	
	node *ptial=(node*)malloc(sizeof(node));
	ptial->next=NULL;
	phead->next=ptial;
	while(1) 
	{
		main_menu(phead,ptial);
		
	}
free(phead);
free(ptial);
}


void creatfile()   
{
	FILE *fp;
	fp=(fopen("student.txt","ab"));
	int i=1;
	struct student pnew;
	while(i!=0) 
	{
		printf("输入学号：");
		scanf("%d",&pnew.sno);
		printf("输入年龄：");
		scanf("%d",&pnew.age);
		fflush(stdin);
		printf("输入姓名：");
		gets(pnew.sname);
		printf("输入性别：");
		gets(pnew.gender);
		printf("输入民族:");
		gets(pnew.nation);
		fwrite(&pnew,sizeof(student),1,fp);
		printf("输入1继续，输入0结束");
		scanf("%d",&i);
	}
	fclose(fp);
	system("cls");
}


void readfile() 
{

	student pnew;
	FILE*fp;
	fp=fopen("student.txt","rb");
	if(fp==NULL)printf("no");
	if(fread(&pnew,sizeof(student),1,fp) == 1)printf("姓名:%s\t学号:%d\t年龄:%d\t性别:%s\t民族:%s\n",pnew.sname,pnew.sno,pnew.age,pnew.gender,pnew.nation);
	else printf("/n文件里面啥也没有！！！！！！请输入后再查看！！！！\n");
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		printf("姓名:%s\t学号:%d\t年龄:%d\t性别:%s\t民族:%s\n",pnew.sname,pnew.sno,pnew.age, pnew.gender,pnew.nation);
	}
	
	fclose(fp);system("pause");
}

void main_menu(node*phead,node*ptial) 
{
	int section;
	printf("			学生管理系统--------------\n");
	printf("			菜单如下：\n");
	printf("			1.输入学生信息\n");
	printf("			2.阅览,遍历,查找\n");
	printf("			3.排序\n");
	printf("			4.统计\n");
	printf("			5.修改\n");		
	scanf("%d",&section);
	switch(section) 
	{	case 1:
			creatfile();break;					
		case 2:
			system("cls");one_menu(phead,ptial);system("cls");break;//副菜单-2.遍历		
		case 3:
			system("cls");two_menu(phead,ptial);system("pause");system("cls");break;//副菜单-3.排序
		case 4:
			system("cls");three_menu(phead,ptial);system("pause");system("cls");break;//副菜单-4.统计
		case 5:
			system("cls");fourth_menu(phead,ptial);system("pause");system("cls");break;//副菜单-5.修改
		
			
	}
}


void Convert_link(node *phead,node *ptial)
{
	
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	if(fp==NULL)return;
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
			
		}
		


	}

	node*p=phead->next;printf("信息如下：\n");
	while(p!=NULL) 
	{
		
		printf("学号:%d",p->data.sno);
		printf("\t年龄:%d",p->data.age);
		printf("\t姓名:%s",p->data.sname);
		//puts(p->data.sname);
		printf("\t性别:%s",p->data.gender);
		//puts(p->data.gender);
		printf("\t民族:%s\n",p->data.nation);
		//puts(p->data.nation);
		p=p->next;

	}
	fclose(fp);
}





void sort_byname(node*phead,node*ptial)//根据sname(姓名)的值从小到大的排序
{
		student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
			
		}
	}		
	
	node *pt1, *pt2, *pt;
	
	for ( pt1=phead->next;pt1->next!=NULL;pt1=pt1->next)
	{
		for (pt2=pt1->next;pt2!=NULL;pt2=pt2->next)
		{
			if (strcmp(pt1->data.sname,pt2->data.sname)>0)
				{
				pt->data=pt1->data;
				pt1->data=pt2->data;
				pt2->data =pt->data;
				}
		}
	}
		printf("信息如下：\n");
	node*p=phead->next;
	while(p!=NULL) 
	{
	
		printf("\n学号:%d",p->data.sno);
		printf("\t年龄:%d",p->data.age);
		printf("\t姓名:%s",p->data.sname);
		printf("\t性别%s",p->data.gender);
		printf("\t民族:%s",p->data.nation);
		p=p->next;

	}
	fclose(fp);
}


void sort_bysno(node*phead,node*ptial)//根据sno(学号)的值从小到大的排序
{
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
			
		}
	}		
	
	node *pt1, *pt2, *pt;
	
	for ( pt1=phead->next;pt1->next!=NULL;pt1=pt1->next)
	{
		for (pt2=pt1->next;pt2!=NULL;pt2=pt2->next)
		{
			if (pt1->data.sno>pt2->data.sno)
				{
				pt->data=pt1->data;
				pt1->data=pt2->data;
				pt2->data =pt->data;
				}
		}
	}
			printf("信息如下：\n");
	node*p=phead->next;
	while(p!=NULL) 
	{

		printf("\n学号:%d",p->data.sno);
		printf("\t年龄:%d",p->data.age);
		printf("\t姓名:%s",p->data.sname);
		printf("\t性别%s",p->data.gender);
		printf("\t民族:%s",p->data.nation);
		p=p->next;

	}
	fclose(fp);
}


void sort_byage(node*phead,node*ptial)//根据age(年龄)的值从小到大的排序
{
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		
		}
	}		
	
	node *pt1, *pt2, *pt;
	
	for ( pt1=phead->next;pt1->next!=NULL;pt1=pt1->next)
	{
		for (pt2=pt1->next;pt2!=NULL;pt2=pt2->next)
		{
			if (pt1->data.age>pt2->data.age)
				{
				pt->data=pt1->data;
				pt1->data=pt2->data;
				pt2->data =pt->data;
				}
		}
	}
			printf("信息如下：\n");
	node*p=phead->next;
	while(p!=NULL) 
	{

		printf("\n学号:%d",p->data.sno);
		printf("\t年龄:%d",p->data.age);
		printf("\t姓名:%s",p->data.sname);
		printf("\t性别%s",p->data.gender);
		printf("\t民族:%s",p->data.nation);
		p=p->next;

	}
	fclose(fp);
}

void sort_bygender(node*phead,node*ptial)//根据gender(性别)的值从小到大的排序
{
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		}
	}		
	
	node *pt1, *pt2, *pt;
	
	for ( pt1=phead->next;pt1->next!=NULL;pt1=pt1->next)
	{
		for (pt2=pt1->next;pt2!=NULL;pt2=pt2->next)
		{
			if (strcmp(pt1->data.gender,pt2->data.gender)>0)
				{
				pt->data=pt1->data;
				pt1->data=pt2->data;
				pt2->data =pt->data;
				}
		}
	}
		printf("信息如下：\n");
	node*p=phead->next;
	while(p!=NULL) 
	{
	
		printf("\n学号:%d",p->data.sno);
		printf("\t年龄:%d",p->data.age);
		printf("\t姓名:%s",p->data.sname);
		printf("\t性别%s",p->data.gender);
		printf("\t民族:%s",p->data.nation);
		p=p->next;

	}
	fclose(fp);
}


void sort_bynation(node*phead,node*ptial)//根据nation(民族)的值从小到大的排序
{
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		}
	}		
	
	node *pt1, *pt2, *pt;
	
	for ( pt1=phead->next;pt1->next!=NULL;pt1=pt1->next)
	{
		for (pt2=pt1->next;pt2!=NULL;pt2=pt2->next)
		{
			if (strcmp(pt1->data.nation,pt2->data.nation)>0)
				{
				pt->data=pt1->data;
				pt1->data=pt2->data;
				pt2->data =pt->data;
				}
		}
	}
	printf("信息如下：\n");
	node*p=phead->next;
	while(p!=NULL) 
	{
		
		printf("\n学号:%d",p->data.sno);
		printf("\t年龄:%d",p->data.age);
		printf("\t姓名:%s",p->data.sname);
		printf("\t性别%s",p->data.gender);
		printf("\t民族:%s",p->data.nation);
		p=p->next;

	}
	fclose(fp);
}


void statisticsbyage(node*phead,node*ptial)
{
	
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	if(fp==NULL)return;
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		}
		


	}

	node*p=phead->next;
	int a,b=0;
	printf("/n输入你要查询的学生年龄以统计人数\n");
	scanf("%d",&a);
	while(p!=NULL) 
	{if(p->data.age==a)b++;
		
		
		p=p->next;

	}
	printf("人数：%d\n",b);
	fclose(fp);
}

void statistics_byage(node*phead,node*ptial)
{
	
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	if(fp==NULL)return;
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
		phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		}
		


	}

	node*p=phead->next;
	int a,b=0;
	printf("/n输入你要查询的学生年龄以统计人数\n");
	scanf("%d",&a);
	while(p!=NULL) 
	{if(p->data.age==a)b++;
		
		
		p=p->next;

	}
	printf("人数：%d\n",b);
	fclose(fp);
}

void statistics_bynation(node*phead,node*ptial)
{
	
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	if(fp==NULL)return;
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		}
		


	}

	node*p=phead->next;
	int b=0;
	char a[8];
	printf("/n输入你要查询的学生民族以统计人数\n");
	fflush(stdin);
	gets(a);
	while(p!=NULL) 
	{if(strcmp(p->data.nation,a)==0)b++;
		
		
		p=p->next;

	}
	printf("人数：%d\n",b);
	fclose(fp);
}


void statistics_bygender(node*phead,node*ptial)
{
	
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		}
		


	}

	node*p=phead->next;
	int b=0;
	char a[8];
	printf("/n输入你要查询的学生性别以统计人数\n");
	fflush(stdin);
	gets(a);
	while(p!=NULL) 
	{if(strcmp(p->data.gender,a)==0)b++;
		
		
		p=p->next;

	}
	printf("人数：%d\n",b);
	fclose(fp);
}

void sdelete_student_info_bysno(node*phead,node*ptial)//通过学生学号删除信息
{
FILE*fp;phead->next=NULL;ptial->next=NULL;phead->next=ptial;
fp=(fopen("student.txt","rb"));
struct student pnew;int i=0;
phead->next=ptial;
while ( fread(&pnew,sizeof(struct student),1,fp) == 1 ) 
{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		}
	
	
}
	
	printf("输入你要删除的学生学号：");
	int a;fflush(stdin);
    scanf("%d",&a);
	fp=(fopen("student.txt","wb"));
	 node*p=phead->next;
	 student pneww;
	while(p!=NULL)
	{			
			if(p->data.sno==a){if(p->next==NULL)break;else p=p->next;}
			pneww=p->data;
			printf("姓名：%s\n学号：%d\n年龄：%d\n性别：%s\n民族：%s\n",pneww.sname,pneww.sno,pneww.age,pneww.gender,pneww.nation);		
		 	printf("1");			 
			fwrite(&pneww,sizeof(student),1,fp);printf("3");
			p=p->next;
			printf("4");
		

	}

	fclose(fp);
	
}

void modify_student_info_bysno(node*phead,node*ptial)//通过学生学号修改该学生信息
{
FILE*fp;
fp=(fopen("student.txt","rb"));
student pnew;int i=0;
while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
			
		}

	
}  
	printf("输入你要修改的学生学号：");int a;fflush(stdin);
    scanf("%d",&a);

	fp=(fopen("student.txt","wb"));

	node*p=phead->next;
	while(p!=NULL)
	{			fflush(stdin);
			if(p->data.sno==a){
				printf("输入更改后的学生学号:");
				scanf("%d",&p->data.sno);
				printf("输入更改后的学生年龄:");
				scanf("%d",&p->data.age);fflush(stdin);
				printf("输入更改后的学生姓名:");
				gets(p->data.sname);
				printf("输入更改后的学生性别:");
				gets(p->data.gender);
				printf("输入更改后的学生民族:");
				gets(p->data.nation);
			};
		
		student pk;
   	 		pk=p->data;
			fwrite(&pk,sizeof(student),1,fp);
			p=p->next;
		

	}

	fclose(fp);
}


void one_menu(node*phead,node*ptial )//副菜单-2遍历
{	printf("			请做出选择：\n");
	printf("			1.遍历，显示数据：\n");
	printf("			2.转为链表，类似于上边，没啥用：\n");
	printf("			3.通过民族查找学生\n");
	printf("			4.通过性别查找学生\n");
	printf("			5.通过姓名查找学生\n");
	printf("			6.通过学号查找学生\n");
	printf("			7.通过年龄查找学生\n");
	printf("			8.退出：\n");
	int section;
	scanf("%d",&section);
	switch(section)
	{
		case 1:
			readfile();break;
		case 2:
			Convert_link(phead,ptial);system("pause");break;
		case 3:
			find_student_nation(phead,ptial);break;
		case 4:
			find_student_gender(phead,ptial);break;
		case 5:
			find_student_sname(phead,ptial);break;
		case 6:
			find_student_sno(phead,ptial);break;
		case 7:
			find_student_age(phead,ptial);break;
		default:
			break;
			
	}
	
	
}


void two_menu(node*phead,node*ptial )//副菜单-3.排序
{	printf("			排序系统：\n");
	printf("			1.按性别排序：\n");
	printf("			2.按民族排序：\n");
	printf("			3.按年龄排序：\n");
	printf("			4.按姓名排序：\n");
	printf("			5.按学号排序：\n");
	printf("			6.退出：\n");
	int section;printf("			请做出选择：\n");
	scanf("%d",&section);
	switch(section)
	{
		case 1:
			sort_bygender(phead,ptial);break;
		case 2:
			sort_bynation(phead,ptial);break;
		case 3:
			sort_byage(phead,ptial);break;
		case 4:
			sort_byname(phead,ptial);break;
		case 5:
			sort_bysno(phead,ptial);break;
		default:
			break;
	}
	
	
}


void three_menu(node*phead,node*ptial )//副菜单-4.统计
{	printf("			统计系统：\n");
	printf("			1.按民族统计：\n");
	printf("			2.按性别统计：\n");
	printf("			3.按年龄统计：\n");
	printf("			4.退出：\n");
	printf("			请做出选择：\n");
	int section;
	scanf("%d",&section);
	switch(section)
	{
		case 1:
			statistics_bynation(phead,ptial);break;
		case 2:
			statistics_bygender(phead,ptial);break;
		case 3:
			statistics_byage(phead,ptial);break;
		default:
			break;
	}
	
	
}



void fourth_menu(node*phead,node*ptial)//副菜单-5.修改
{	printf("			修改系统：\n");
	printf("			1.按学号删除某个学生：\n");
	printf("			2.按学号修改某个学生的信息：\n");
	printf("			3.退出：\n");
	printf("			请做出你的选择：\n");
	int section;
	scanf("%d",&section);
	switch(section)
	{
		case 1:
			sdelete_student_info_bysno(phead,ptial);break;
		case 2:
			modify_student_info_bysno(phead,ptial);break;
		default:
			break;
	}
}


void find_student_nation(node*phead,node*ptial)//通过民族查找学生
{
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	if(fp==NULL)return;
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		}
		


	}

	node*p=phead->next;
	char a[8];
	printf("/n输入你要查询的学生民族以输出学生\n");
	fflush(stdin);
	gets(a);
	while(p!=NULL) 
	{if(strcmp(p->data.nation,a)==0)
	{printf("姓名：%s\t学号：%d\t年龄：%d\t性别：%s\t民族：%s\n",p->data.sname,p->data.sno,p->data.age,p->data.gender,p->data.nation);
	}				
		p=p->next;

	}
	fclose(fp);
	system("pause");
	
}

void find_student_gender(node*phead,node*ptial)//通过性别查找学生
{
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	if(fp==NULL)return;
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		}
		


	}

	node*p=phead->next;
	char a[8];
	printf("/n输入你要查询的学生性别以输出学生\n");
	fflush(stdin);
	gets(a);
	while(p!=NULL)
	{if(strcmp(p->data.gender,a)==0)
	{printf("姓名：%s\t学号：%d\t年龄：%d\t性别：%s\t民族：%s\n",p->data.sname,p->data.sno,p->data.age,p->data.gender,p->data.nation);
	}				
		p=p->next;

	}
	fclose(fp);
	system("pause");
	
}


void find_student_sname(node*phead,node*ptial)//通过姓名查找学生
{
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	if(fp==NULL)return;
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		}
		


	}

	node*p=phead->next;
	char a[8];
	printf("/n输入你要查询的学生姓名以输出学生\n");
	fflush(stdin);
	gets(a);
	while(p!=NULL) 
	{if(strcmp(p->data.sname,a)==0)
	{printf("姓名：%s\t学号：%d\t年龄：%d\t性别：%s\t民族：%s\n",p->data.sname,p->data.sno,p->data.age,p->data.gender,p->data.nation);
	}				
		p=p->next;

	}
	fclose(fp);
	system("pause");
	
}



void find_student_sno(node*phead,node*ptial)//通过学号查找学生
{
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=ptial;
	fp=fopen("student.txt","rb");
	if(fp==NULL)return;
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		}
		
	

	}

	node*p=phead->next;
	int a;
	printf("/n输入你要查询的学生学号以输出学生\n");
	fflush(stdin);
	scanf("%d",&a);
	while(p!=NULL) 
	{if(p->data.sno==a)
	{printf("姓名：%s\t学号：%d\t年龄：%d\t性别：%s\t民族：%s\n",p->data.sname,p->data.sno,p->data.age,p->data.gender,p->data.nation);
	}				
		p=p->next;

	}
	fclose(fp);
	system("pause");
	
}




void find_student_age(node*phead,node*ptial)//通过年龄查找学生
{
	student pnew;
	FILE*fp;
	int i=0;
	phead->next=NULL;ptial->next=NULL;phead->next=ptial;
	fp=fopen("student.txt","rb");
	if(fp==NULL)return;
	while ( fread(&pnew,sizeof(student),1,fp) == 1 ) 
	{
		if(i==0) 
		{
			phead->next->data=pnew;
			i++;
		} else 
		{   node *pnee=(node*)malloc(sizeof(node));
			pnee->data=pnew;
			pnee->next=NULL;
			ptial->next=pnee;
			ptial=ptial->next;
			ptial->next=NULL;
		
		}
		
	}


	node*p=phead->next;
	int a;
	printf("/n输入你要查询的学生年龄以输出学生\n");
	fflush(stdin);
	
	
	scanf("%d",&a);
	while(p!=NULL) 
	{
	
	if(p->data.age==a)
	{printf("姓名：%s\t学号：%d\t年龄：%d\t性别：%s\t民族：%s\n",p->data.sname,p->data.sno,p->data.age,p->data.gender,p->data.nation);
	}				
		p=p->next;

	}
	fclose(fp);
	system("pause");
	
	
}
