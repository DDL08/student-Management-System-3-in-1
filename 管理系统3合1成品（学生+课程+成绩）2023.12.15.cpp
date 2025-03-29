#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
//产品源码介绍：
//由主菜单menu进入三个系统分支（学生menu1/课程menu2/成绩menu3）
//菜单menu12后缀数字代表菜单1的2号选项分支（功能）
char filename1[]="Student_File.dat";
char filename2[]="Course_File.dat";
char filename3[]="SC_File.dat";
struct Student
{
    int sno;
    char sname[10];
    char gender[3]; 
    char nation[10]; 
    int age;
};
struct Course{
    int cno;         
    char cname[10];  
    float  credit;  
};
struct SC{
	int sno;
	int cno;
	float score;
};
struct Node{
	void *data;
	Node *next;
};
Node *createHead();    //建立链表的头结点 
Node *addAll(Node *phead,int n,Node*(*pFunc)(Node*));  //增加链表结点
Node*inputStudent(Node*pk);    //按格式输入学生数据 
Node*inputCourse(Node*pk);     //按格式输入课程数据 
Node*inputSC(Node*pk);		   //按格式输入成绩数据 
void traversal(Node* phead,void(*pFunc)(Node*));  //遍历链表 
void showStudent(Node*pk);     //按格式输出学生数据 
void showCourse(Node*pk);      //按格式输出课程数据 
void showSC(Node*pk);      	   //按格式输出成绩数据 
void release(Node *phead);        //释放链表 
int size_List(Node*phead);//统计数据 
int size_gender(Node*phead,char*point);//统计学生性别数据 
int size_nation(Node*phead,char*point);//统计学生民族数据 
int size_age(Node*phead,int point);//统计学生年龄数据 
int size_average_score(Node*phead,Node*phead2);//统计平均成绩节点数据
int size_fail(Node*phead,int point,Node*phead2);//统计单科不及格学生信息
int size_under_point_people(Node*phead,Node*phead2,int point);//统计低于该学生的学生数据
Node*get_sno(Node*phead,int point);//获取学生学号
Node*get_age(Node*phead,int point);//获取学生年龄
Node*get_sname(Node*phead,char*point);//获取学生姓名
Node*get_nation(Node*phead,char*point);//获取学生民族
Node*get_gender(Node*phead,char*point);//获取学生性别
Node*get_first(Node*phead);//获取头节点
Node*get_last(Node*phead);//获取尾节点
Node*get_cno(Node*phead,int point);//课程号获取
Node*get_credit(Node*phead,float point);//学分获取
Node*get_cname(Node*phead,char*point);//课程名获取
Node*get_by_scno(Node*phead,int point,Node*phead2,int point2);//成绩管理输入学号课程号
Node*get_by_scname(Node*phead,char*point,Node*phead2,char*point2,Node*phead3);//成绩管理输入学生名课程名
int get_Corse_crose_bysno(Node*phead,Node*phead2,int point);//
int get_most_average_score(Node*phead,Node*phead2);//求平均成绩最高的学生
void sort_sno(Node*phead);//靠学号排序
void sort_age(Node*phead);//靠年龄排序
void sort_sname(Node*phead);//靠姓名排序
void sort_nation(Node*phead);//靠民族排序
void sort_credit(Node*phead);//靠学分排序
int scort_average_byscore(Node*phead,Node*phead2);//排序平均成绩节点数据 
void addFirst(Node*phead,Node*(*pFunc)(Node*));//插入在头节点
void addLast(Node*phead,Node*(*pFunc)(Node*));//插入在尾节点
void deleteFirst(Node*phead);//删除头节点（第一个学生/课程/成绩）
void deleteLast(Node*phead);//删除最后一个节点（最后一个学生/课程/成绩）
void deletepoint_bysno(Node*phead,int point);//删除指定节点（一个学生/课程/成绩）
void deletepoint_bycno(Node*phead,int point);//删除指定节点（一个学生/课程/成绩）
void deletepoint_bysno_cno(Node*phead,int point,int point2);//
void modify_bysno(Node*phead,Node*(*pFunc)(Node*),int point);//修改信息
void modify_bycno(Node*phead,Node*(*pFunc)(Node*),int point);//修改信息
void modify_bysno_cno(Node*phead,Node*(*pFunc)(Node*),int point,int point2);//修改信息
void read_infotofile(Node*head,char *filename,int bythecount);
void write_infotofile(Node*head,char*filename,int bythecount);
void menu();//两个系统管理选择
void menu1();//学生系统
void menu13(Node*phead);//学生管理系统-统计
void menu14(Node*phead);//学生管理系统-查询
void menu15(Node*phead);//学生管理系统-排序
void menu16(Node*phead);//学生管理系统-插入
void menu17(Node*phead);//学生管理系统-删除修改
void menu2();//课程管理
void menu24(Node*phead);//课程管理系统-查询
void menu3();//成绩管理
void menu33(Node*phead,Node*phead2);//成绩管理系统-统计
void menu34(Node*phead,Node*phead2,Node*phead3);//成管理系统-查询
int main(){

	menu();

 	return 0;
}

Node *createHead(){    
Node*phead=(Node*)malloc(sizeof(Node));
phead->next=NULL;
      //建立链表头结点（为方便处理链表， 引入头结点） 
    //填写代码 
	return phead;
}

Node *addAll(Node* phead,int n,Node*(*pFunc)(Node*)){  

 //增加链表结点 	
	for(int i = 0; i < n; i++){
		Node *pnew = (Node*)malloc(sizeof(Node));
		pnew=pFunc(pnew);
		//给pnew->data赋值
		//填写代码  
		pnew->next =phead->next;
		phead->next=pnew;

		
		//填写代码 
	}
	return phead;
} 
Node *addtofirst(Node* phead,void*data){  
 //增加链表结点 	
		Node *pnew = (Node*)malloc(sizeof(Node));
		pnew->data=(Student*)data;
		//给pnew->data赋值
		//填写代码  
		pnew->next =phead->next;
		phead->next=pnew;		
		//填写代码 
		return phead;
} 
Node*inputCourse(Node*pk){
	Course*pnew=(Course*)malloc(sizeof(Course));
	printf("输入课程号");
	scanf("%d",&pnew->cno); 
	printf("输入课程名");
	scanf("%s",pnew->cname); 
	printf("输入课程分");
	scanf("%f",&pnew->credit);
	pk->data=pnew;
	return pk;
	//填写代码  
}

Node*inputStudent(Node*pk){
	Student*pnew=(Student*)malloc(sizeof(Student));	
	printf("输入学号：");
		scanf("%d",&pnew->sno);
		printf("输入年龄：");
		scanf("%d",&pnew->age);
		fflush(stdin);
		printf("输入姓名：");
		gets(pnew->sname);
		printf("输入性别：");
		gets(pnew->gender);
		printf("输入民族：");
		gets(pnew->nation);
		pk->data=pnew;
		return pk;
  //填写代码 
} 

Node*inputSC(Node*pk){
	SC*pnew=(SC*)malloc(sizeof(SC));
	printf("输入学号");
	scanf("%d",&pnew->sno);
	printf("输入课程号");
	scanf("%d",&pnew->cno);  
	printf("输入成绩");
	scanf("%f",&pnew->score);
	pk->data=pnew;
	return pk;
	//填写代码  
}
void traversal(Node *phead,void(*pFunc)(Node*)){Node* p = phead->next;
	while(p!=NULL){
		pFunc(p);
		//调用函数，显示结点p数据域 
		p = p->next;
	}  //遍历链表 
    //填写代码 
}
void showStudent(Node*pk){
	Student*pnew=(Student*)malloc(sizeof(Student));
	pnew=(Student*)pk->data;
		printf("学号:%d",pnew->sno);
		printf("\t年龄:%d",pnew->age);
		printf("\t姓名:%s",pnew->sname);
		printf("\t性别:%s",pnew->gender);
		printf("\t民族:%s\n",pnew->nation);
	
    //填写代码 
}
void showCourse(Node*pk){
	Course*pnew=(Course*)malloc(sizeof(Course));
	pnew=(Course*)pk->data;
	printf("课程号：%d",pnew->cno);
	printf("课程名：%s",pnew->cname);
	printf("课程分：%.1f\n",pnew->credit);
	 //填写代码 
}

void showSC(Node*pk){
	SC*pnew=(SC*)malloc(sizeof(SC));
	pnew=(SC*)pk->data;
	printf("学号：%d",pnew->sno);
	printf("课程号：%d",pnew->cno);
	printf("成绩：%.1f\n",pnew->score);
	 //填写代码 
}
void release(Node* phead){  
Node*p=phead->next;
	while(p!=NULL){
	free(phead);
	phead=p;
	p=p->next;
	} free(phead); //释放链表 
 //填写代码 
	return;
}
 
void menu()//两个系统管理选择
{				printf("\n\t\t系统选择模块\n");
       		 	printf("\t-----------------------------\n");
       			printf("\t\t1---学生管理系统\n"); 
       			printf("\t\t2---课程管理系统\n"); 
       			printf("\t\t3---成绩管理系统\n");
        		printf("\t\t0---退出\n");  
        		printf("\t-----------------------------\n");
        		printf("\t   请输入数字(0 - 3):");
				printf("请输入选择："); 
int a;scanf("%d",&a);
switch(a){
	case 1:	 {
			menu1();
		break;
		
	}
	case 2:	{
			menu2();
		break;
	} 
	case 3:	{
			menu3();
		break;
	}
	default:
		break;
}
}

void menu1()//学生管理系统
{   Node* phead_S =createHead();
		read_infotofile(phead_S,filename1,sizeof(Student));
     while (1)
    {	
		system("cls");
        printf("\n\t\t学生管理软件主菜单\n");        
        printf("\t-----------------------------\n");
        printf("\t\t1---输入数据\n");
        printf("\t\t2---输出数据\n");
        printf("\t\t3---统计数据\n");
        printf("\t\t4---查询数据\n");
        printf("\t\t5---数据排序\n");
        printf("\t\t6---数据插入\n");
        printf("\t\t7---数据删除或修改\n"); 
        printf("\t\t0---退出\n");  
        printf("\t-----------------------------\n");
        printf("\t   请输入数字(0 - 7):");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {   
            case 0:  return; 
            case 1:{//增加节点
				int a=1; 
				printf("请输入几个节点："); 
				scanf("%d",&a);
				phead_S=addAll(phead_S,a,inputStudent);
				write_infotofile(phead_S,filename1,sizeof(Student));
				break;
            }
            case 2://遍历
            {	printf("\n\n学生信息：\n"); 
 				traversal(phead_S,showStudent);                
                break;
            }
            case 3://统计数据 
            {    menu13(phead_S);                 
                break;
            }
            case 4://查询数据
            {	menu14(phead_S);               
                break;
            }

            case 5://排序模板
            {	menu15(phead_S);
				break;
            }
            case 6://插入
            {   menu16(phead_S);
            write_infotofile(phead_S,filename1,sizeof(Student));
                break;
            }
            case 7://数据删除和修改
            {   menu17(phead_S);
            write_infotofile(phead_S,filename1,sizeof(Student));
                break;
            }                    
            default: continue;
        }
        system("pause");
    } release(phead_S);
    return;
}
void menu13(Node*phead)//学生管理系统-统计
{   
     while (1)
    {
        system("cls");
        printf("\n\t\t学生3统计页面\n");
        printf("\t-----------------------------\n");
        printf("\t\t1---性别统计\n");
        printf("\t\t2---民族统计\n");
        printf("\t\t3---年龄统计\n");
        printf("\t\t4---年龄对应学生\n");
        printf("\t\t5---民族对应学生\n");
        printf("\t\t6---学生总人数统计\n");
        printf("\t\t0---退出\n");  
        printf("\t-----------------------------\n");
        printf("\t   请输入数字(0 - 6):");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {   
            case 0:  return; 
            case 1:{//统计学生性别数据
				char point[5];
            	printf("输入要统计的性别:\n");
            	fflush(stdin);
            	gets(point);
				size_gender(phead,point); 
				break;
            }
            case 2://统计学生民族数据
            {	char point[5];
            	printf("输入要统计的民族:\n");
            	fflush(stdin);
            	gets(point);
				size_nation(phead,point);      
                break;
            }
            case 3://统计学生年龄数据
            {   int point;
            	printf("输入要统计的年龄:\n");
            	fflush(stdin);
            	scanf("%d",&point);
				size_age(phead,point);               
                break;
            }
            case 4:
            {	  
                break;
            }

            case 5://
            {	
				break;
            }
            case 6://总人数统计
            {   size_List(phead);
                break;
            }
            case 7:
            {   
                break;
            }                    
            default: continue;
        }
        system("pause");
    } 
    return;
}
void menu14(Node*phead)//学生管理系统-查询
{
     while (1)
    {
        system("cls");
        printf("\n\t\t学生4查询页面\n");
        printf("\t-----------------------------\n");
        printf("\t\t1---性别查询\n");
        printf("\t\t2---民族查询\n");
        printf("\t\t3---年龄查询\n");
        printf("\t\t4---学号查询\n");
        printf("\t\t5---姓名查询\n");
        printf("\t\t6---获取头节点\n");
        printf("\t\t7---获取尾节点\n");
        printf("\t\t0---退出\n");  
        printf("\t-----------------------------\n");
        printf("\t   请输入数字(0 - 7):");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {   
            case 0:  return; 
            case 1:{//查询学生性别
				char point[5];
            	printf("输入要查询的性别:\n");
            	fflush(stdin);
            	gets(point);
				get_gender(phead,point); 
				break;
            }
            case 2://查询学生民族
            {	char point[8];
            	printf("输入要查询的民族:\n");
            	fflush(stdin);
            	gets(point);
				get_nation(phead,point);      
                break;
            }
            case 3://查询学生年龄
            {   int point;
            	printf("输入要查询的年龄:\n");
            	fflush(stdin);
            	scanf("%d",&point);
				get_age(phead,point);               
                break;
            }
            case 4://查询学生学号
            {	int point;
            	printf("输入要查询的学号:\n");
            	fflush(stdin);
            	scanf("%d",&point);
				get_sno(phead,point);
                break;
            }

            case 5://查询学生姓名
            {	char point[10];
            	printf("输入要查询的姓名:\n");
            	fflush(stdin);
            	gets(point);
				get_sname(phead,point);
				break;
            }
            case 6://获取头节点
            {   get_first(phead);
                break;
            }
            case 7:
            {   get_last(phead);
                break;
            }                    
            default: continue;
        }
        system("pause");
    } 
    return;
}
void menu15(Node*phead)//学生管理系统-排序
{   
     while (1)
    {
        system("cls");
        printf("\n\t\t学生5排序页面\n");
        printf("\t-----------------------------\n");
        printf("\t\t1---学号排序\n");
        printf("\t\t2---年龄排序\n");
        printf("\t\t3---姓名排序\n");
        printf("\t\t4---民族排序\n");
        printf("\t\t0---退出\n");  
        printf("\t-----------------------------\n");
        printf("\t   请输入数字(0 - 4):");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {   
            case 0:  return; 
            case 1:{//学号排序
				sort_sno(phead);
				break;
            }
            case 2://年龄排序
            {	sort_age(phead);     
                break;
            }
            case 3://姓名排序
            {   sort_sname(phead);               
                break;
            }
            case 4://民族排序
            {	sort_nation(phead);
                break;
            }

            case 5://
            {	
				break;
            }
            case 6://
            {   
                break;
            }
            case 7:
            {   
                break;
            }                    
            default: continue;
        }
        system("pause");
    } 
    return;
}
void menu16(Node*phead)//学生管理系统-插入
{   
     while (1)
    {
        system("cls");
        printf("\n\t\t学生6插入页面\n");
        printf("\t-----------------------------\n");
        printf("\t\t1---插入在头节点\n");
        printf("\t\t2---插入在尾节点\n");
        printf("\t\t3---插入指定学生前\n");
        printf("\t\t0---退出\n");  
        printf("\t-----------------------------\n");
        printf("\t   请输入数字(0 - 3):");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {   
            case 0:  return; 
            case 1:{//插入在头节点
				addFirst(phead,inputStudent);
				break;
            }
            case 2://插入在尾节点
            {	addLast(phead,inputStudent);    
                break;
            }
            case 3://
            {                  
                break;
            }
            case 4://
            {	
                break;
            }

            case 5://
            {	
				break;
            }
            case 6://
            {   
                break;
            }
            case 7:
            {   
                break;
            }                    
            default: continue;
        }
        system("pause");
    } 
    return;
}
void menu17(Node*phead)//学生管理系统-删除修改
{   
     while (1)
    {
        system("cls");
        printf("\n\t\t学生7删改页面\n");
        printf("\t-----------------------------\n");
        printf("\t\t1---删除第一个学生\n");
        printf("\t\t2---删除最后一个学生\n");
        printf("\t\t3---按学号删除指定学生\n");
        printf("\t\t4---按学号修改指定学生\n");
        printf("\t\t0---退出\n");  
        printf("\t-----------------------------\n");
        printf("\t   请输入数字(0 - 4):");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {   
            case 0:  return; 
            case 1:{//头节点
				deleteFirst(phead);
				break;
            }
            case 2://尾节点
            {	deleteLast(phead);    
                break;
            }
            case 3://删除指定节点（一个学生/课程/成绩）
            {   int point;printf("请输入学号来删除：");
            	scanf("%d",&point);
				deletepoint_bysno(phead,point);               
                break;
            }
            case 4://修改信息通过学号
            {	int point;printf("请输入学号来修改：");
            	scanf("%d",&point);
				modify_bysno(phead,inputStudent,point);
                break;
            }

            case 5://
            {	
				break;
            }
            case 6://
            {   
                break;
            }
            case 7:
            {   
                break;
            }                    
            default: continue;
        }
        system("pause");
    } 
    return;
}
void menu2()//课程管理
{   Node* phead_C =createHead();phead_C->next=NULL;
	read_infotofile(phead_C,filename2,sizeof(Course));
     while (1)
    {
        system("cls");
        printf("\n\t\t课程管理软件主菜单\n");
        printf("\t-----------------------------\n");
        printf("\t\t1---输入数据\n");
        printf("\t\t2---输出数据\n");
        printf("\t\t3---统计数据\n");
        printf("\t\t4---查询数据\n");
        printf("\t\t5---数据排序（学分排序）\n");
        printf("\t\t6---数据插入(插入到第一门课程前)\n");
        printf("\t\t7---数据删除(根据课程号)\n"); 
        printf("\t\t8---数据修改(根据课程号)\n");
        printf("\t\t0---退出\n");  
        printf("\t-----------------------------\n");
        printf("\t   请输入数字(0 - 7):");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {   
            case 0:  return; 
            case 1:{//增加节点
				int a=1; 
				printf("请输入几个节点："); 
				scanf("%d",&a);
				phead_C=addAll(phead_C,a,inputCourse);
				write_infotofile(phead_C,filename2,sizeof(Course));
				break;
            }
            case 2://遍历
            {	printf("\n\n课程信息：\n"); 
 				traversal(phead_C,showCourse);                 
                break;
            }
            case 3://统计数据 
            {   size_List(phead_C);             
                break;
            }
            case 4://查询数据
            {	menu24(phead_C);//课程管理系统-查询          
                break;
            }

            case 5://排序模板
            {	sort_credit(phead_C);//靠学分排序
				break;
            }
            case 6://插入到第一门课程前
            {   addFirst(phead_C,inputCourse);
                break;
            }
            case 7:
            { 	int point;printf("请输入课程号来删除：");
            	scanf("%d",&point);
				deletepoint_bycno(phead_C,point);
				write_infotofile(phead_C,filename2,sizeof(Course));
                break;
            }  
			case 8:
            { 	int point;printf("请输入课程号号来修改：");
            	scanf("%d",&point);
				modify_bysno(phead_C,inputCourse,point);
				write_infotofile(phead_C,filename2,sizeof(Course));
                break;
            }                   
            default: continue;
        }
        system("pause");
    } release(phead_C);
    return;
}
void menu24(Node*phead)//课程管理系统-查询
{
     while (1)
    {
        system("cls");
        printf("\n\t\t课程4查询页面\n");
        printf("\t-----------------------------\n");
        printf("\t\t1---课程名查询\n");
        printf("\t\t2---课程号查询\n");
        printf("\t\t3---学分查询\n");
        printf("\t\t0---退出\n");  
        printf("\t-----------------------------\n");
        printf("\t   请输入数字(0 - 3):");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {   
            case 0:  return; 
            case 1:{//查询课程名
				char point[5];
            	printf("输入要查询的课程名:\n");
            	fflush(stdin);
				gets(point);         	
            	get_cname(phead,point);
				break;
            }
            case 2://查询课程号
            {	int point;
            	printf("输入要查询的课程号:\n");
            	fflush(stdin);
            	scanf("%d",&point);
				get_cno(phead,point);      
                break;
            }
            case 3://查询学分
            {   float point;
            	printf("输入要查询的课程分:\n");
            	fflush(stdin);
            	scanf("%f",&point);
				get_credit(phead,point);               
                break;
            }                              
            default: 
			continue;
        }
        system("pause");
    } 
    return;
}
void menu3()//成绩管理
{   Node* phead_SC =createHead();phead_SC->next=NULL;
	read_infotofile(phead_SC,filename3,sizeof(SC));
	Node* phead_C =createHead();phead_C->next=NULL;
	read_infotofile(phead_C,filename2,sizeof(Course));
	Node* phead_S =createHead();phead_S->next=NULL;
	read_infotofile(phead_S,filename1,sizeof(Student));
     while (1)
    {
        system("cls");
        printf("\n\t\t成绩管理软件主菜单\n");
        printf("\t-----------------------------\n");
        printf("\t\t1---输入数据\n");
        printf("\t\t2---输出数据\n");
        printf("\t\t3---统计数据\n");
        printf("\t\t4---查询数据\n");
        printf("\t\t5---数据排序\n");
        printf("\t\t6---数据插入\n");
        printf("\t\t7---数据删除\n");
		printf("\t\t8---数据修改\n"); 
        printf("\t\t0---退出\n");  
        printf("\t-----------------------------\n");
        printf("\t   请输入数字(0 - 7):");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {   
            case 0:  return; 
            case 1:{//增加节点
				int a=1; 
				printf("请输入几个节点："); 
				scanf("%d",&a);
				phead_SC=addAll(phead_SC,a,inputSC);
				write_infotofile(phead_SC,filename3,sizeof(SC));
				break;
            }
            case 2://遍历
            {	printf("\n\n成绩信息：\n"); 
 				traversal(phead_SC,showSC);                 
                break;
            }
            case 3://统计数据 
            {   menu33(phead_SC,phead_S);            
                break;
            }
            case 4://查询数据
            {	menu34(phead_S,phead_C,phead_SC);//成管理系统-查询              
                break;
            }

            case 5://排序模板按平均成绩排序（降序），输出学号、姓名、平均成绩、次序号
            {	scort_average_byscore(phead_SC,phead_S);//排序平均成绩节点数据 
				break;
            }
            case 6://插入
            {   addFirst(phead_SC,inputSC);//插入在头节点
            	write_infotofile(phead_SC,filename3,sizeof(SC));
                break;
            }
            case 7://给定学号和课程号， 删除对应的记录
            { 	int point; 
				printf("请输入学号："); 
				scanf("%d",&point);
				int point2; 
				printf("请输入课程号："); 
				scanf("%d",&point2);
				deletepoint_bysno_cno(phead_SC,point,point2);
				write_infotofile(phead_SC,filename3,sizeof(SC));
                break;
            }  
			case 8://数据修改
            { 	int point; 
				printf("请输入学号："); 
				scanf("%d",&point);
				int point2; 
				printf("请输入课程号："); 
				scanf("%d",&point2);
				modify_bysno_cno(phead_SC,inputSC,point,point2);
				write_infotofile(phead_SC,filename3,sizeof(SC));
                break;
            }                  
            default: continue;
        }
        system("pause");
    } release(phead_S);
    release(phead_C);
    release(phead_SC);
    return;
}

void menu33(Node*phead,Node*phead2)//成绩管理系统-统计
{   
     while (1)
    {
        system("cls");
        printf("\n\t\t成绩3统计页面\n");
        printf("\t-----------------------------\n");
        printf("\t\t1---统计平均成绩\n");
        printf("\t\t2---统计单科不及格学生信息\n");
        printf("\t\t3---给定一个学生，查询平均成绩低于该学生的其他学生信息\n");
        printf("\t\t0---退出\n");  
        printf("\t-----------------------------\n");
        printf("\t   请输入数字(0 - 3):");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {   
            case 0:  return; 
            case 1:{//统计平均成绩节点数据
				size_average_score(phead,phead2);
				break;
            }
            case 2://统计单科不及格学生信息
            {	printf("输入课程号：");
				int point;
            	scanf("%d",&point);
				size_fail(phead,point,phead2);
                break;
            }
            case 3://给定一个学生，查询平均成绩低于该学生的其他学生信息
            {   printf("输入学号：");
				int point;
            	scanf("%d",&point);
				size_under_point_people(phead,phead2,point);             
                break;
            }                 
            default: continue;
        }
        system("pause");
    } 
    return;
}
void menu34(Node*phead,Node*phead2,Node*phead3)//成管理系统-查询
{
     while (1)
    {
        system("cls");
        printf("\n\t\t课程4查询页面\n");
        printf("\t-----------------------------\n");
        printf("\t\t1---输入学生号课程号查询\n");
        printf("\t\t2---输入学生名课程名查询\n");
        printf("\t\t3---输入学生号查询\n");//课程号、课程名、成绩、平均成绩和总成绩，以及排名（排名选做！）
        printf("\t\t4---查询平均成绩最高的学生信息\n");//平均成绩，输出学号、姓名、民族和平均成绩
        printf("\t\t0---退出\n");
        printf("\t-----------------------------\n");
        printf("\t   请输入数字(0 - 3):");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {   
            case 0:  return; 
            case 1:{//查询
            	printf("\n");
            	int point;
            	printf("输入要查询的学生号:\n");
            	fflush(stdin);
            	scanf("%d",&point);
            	int point2;
            	printf("输入要查询的课程号:\n");
            	fflush(stdin);
            	scanf("%d",&point2);
				get_by_scno(phead,point,phead2,point2);//获取学生学号
				Node*p=phead3->next;
				while(p!=NULL){
				SC*pmove=(SC*)p->data;
				if(pmove->cno==point2&&pmove->sno==point){
				printf("成绩：%.1f\n",pmove->score);	
					
					}
				p=p->next;
					}		
				break;
            }
            case 2://查询
            {	printf("\n");
            	char point[10];
            	printf("输入要查询的学生名:\n");
            	fflush(stdin);
            	scanf("%s",&point);
            	char point2[10];
            	printf("输入要查询的课程名:\n");
            	fflush(stdin);
            	scanf("%s",&point2);
				get_by_scname(phead,point,phead2,point2,phead3);//获取学生学号		
				break;
            }
            case 3://查询
            {   printf("输入学号获取信息:\n");
            	int point;
            	scanf("%d",&point);
				get_Corse_crose_bysno(phead3,phead2,point);//
                break;
            }    
			case 4://查询
            {   get_most_average_score(phead3,phead);//求平均成绩最高的学生               
                break;
            }                            
            default:
			continue;
        }
        system("pause");
    } 
    return;
}
int size_List(Node*phead)//统计链表节点数据 
{	Node*p=phead->next;
int i=0;
	while(p!=NULL){
		i++;p=p->next;
	}
	printf("节点个数为：%d\n",i);return i;
	
}
int size_gender(Node*phead,char*point)//统计学生性别数据 
{	Node*p=phead->next;
int i=0;
	while(p!=NULL){Student*pmove=(Student*)p->data;
		if(strcmp(pmove->gender,point)==0)i++;
		p=p->next;
	}
	printf("节点个数为：%d\n",i);return 0;
	
}
int size_nation(Node*phead,char*point)//统计学生民族数据 
{	Node*p=phead->next;
int i=0;
	while(p!=NULL){Student*pmove=(Student*)p->data;
		if(strcmp(pmove->nation,point)==0)i++;
		p=p->next;
	}
	printf("节点个数为：%d\n",i);return 0;
	
}
int size_age(Node*phead,int point)//统计学生年龄数据 
{	Node*p=phead->next;
int i=0;
	while(p!=NULL){Student*pmove=(Student*)p->data;
		if(pmove->age==point)i++;
		p=p->next;
	}
	printf("节点个数为：%d\n",i);return 0;
	
}
int size_average_score(Node*phead,Node*phead2)//统计平均成绩节点数据 
{	int i=size_List(phead);
printf("不及格学生信息如下：\n");
	int j=0,k=0,e=0;
	int a[i]={'\0'};//学号
	float b[i];//成绩总分
	int c[i]={0};//报课程数量
	Node*p=phead->next;
	while(p!=NULL){SC*temp=(SC*)p->data;k=0;e=0;
		while(a[k]!=NULL){
			if(temp->sno==a[k]){c[k]++;b[k]+=temp->score;e++;break;}
			else k++;
		}if(e==0){a[k]=temp->sno;c[k]=c[k]+1;b[k]=b[k]+temp->score;}
		p=p->next;
	}
	
	int z=0;
	while(a[z]!=NULL){
		float pp=b[z]/(float)c[z];
		if(pp<60.0){printf("平均成绩为:%.1f",b[z]/(float)c[z]);get_sno(phead2,a[z]);
		}
		z++;
	}return 0;
}
int size_fail(Node*phead,int point,Node*phead2)//统计单科不及格学生信息
{	Node*p=phead->next;
	int i=0;
	printf("课程号:%d不及格学生信息如下：\n",point);
	while(p!=NULL){SC*pmove=(SC*)p->data;\
		if(pmove->cno==point){
		if(pmove->score<60){printf("成绩:%d",pmove->cno);
		get_sno(phead2,pmove->sno);
		}
		}
		p=p->next;
	}
	return 0;
	
}
int size_under_point_people(Node*phead,Node*phead2,int point)//统计低于该学生的学生数据
{	int i=size_List(phead);
int bb=0,cc=0;float aa;Node*p2=phead->next;
while(p2!=NULL){SC*temp2=(SC*)p2->data;if(temp2->sno){
	bb+=temp2->score;cc++;
}p2=p2->next;
}aa=(float)bb/(float)cc;
printf("学号为%d的学生的成绩为%.1f\n",point,aa);
printf("成绩第于学号为%d的学生信息如下：\n\n",point);
	int j=0,k=0,e=0;
	int a[i]={'\0'};//学号
	float b[i];//成绩总分
	int c[i]={0};//报课程数量
	Node*p=phead->next;
	while(p!=NULL){SC*temp=(SC*)p->data;k=0;e=0;
		while(a[k]!=NULL){
			if(temp->sno==a[k]){c[k]++;b[k]+=temp->score;e++;break;}
			else k++;
		}if(e==0){a[k]=temp->sno;c[k]=c[k]+1;b[k]=b[k]+temp->score;}
		p=p->next;
	}
	int z=0;
	while(a[z]!=NULL){
		float pp=b[z]/(float)c[z];
		if(pp<aa){printf("平均成绩为:%.1f",b[z]/(float)c[z]);get_sno(phead2,a[z]);
		}
		z++;
	}
	return 0;
}
Node*get_gender(Node*phead,char*point)//获取学生性别
{	Node*p=phead->next;
	while(p!=NULL){
		Student*pmove=(Student*)p->data;
		if(strcmp(pmove->gender,point)==0){
			printf("学号:%d",pmove->sno);
			printf("\t年龄:%d",pmove->age);
			printf("\t姓名:%s",pmove->sname);
			printf("\t性别:%s",pmove->gender);
			printf("\t民族:%s\n",pmove->nation);
		}
		p=p->next;
	}
	return 0;
	
}
Node*get_nation(Node*phead,char*point)//获取学生民族
{	Node*p=phead->next;
	while(p!=NULL){
		Student*pmove=(Student*)p->data;
		if(strcmp(pmove->nation,point)==0){
			printf("学号:%d",pmove->sno);
			printf("\t年龄:%d",pmove->age);
			printf("\t姓名:%s",pmove->sname);
			printf("\t性别:%s",pmove->gender);
			printf("\t民族:%s\n",pmove->nation);
		}
		p=p->next;
	}
	return 0;
	
}
Node*get_age(Node*phead,int point)//获取学生民族
{	Node*p=phead->next;
	while(p!=NULL){
		Student*pmove=(Student*)p->data;
		if(pmove->age==point){
			printf("学号:%d",pmove->sno);
			printf("\t年龄:%d",pmove->age);
			printf("\t姓名:%s",pmove->sname);
			printf("\t性别:%s",pmove->gender);
			printf("\t民族:%s\n",pmove->nation);
		}
		p=p->next;
	}
	return 0;
	
}
Node*get_sno(Node*phead,int point)//获取学生学号
{	Node*p=phead->next;
	while(p!=NULL){
		Student*pmove=(Student*)p->data;
		if(pmove->sno==point){
			printf("学号:%d",pmove->sno);
			printf("\t年龄:%d",pmove->age);
			printf("\t姓名:%s",pmove->sname);
			printf("\t性别:%s",pmove->gender);
			printf("\t民族:%s\n",pmove->nation);
		}
		p=p->next;
	}
	return 0;
	
}
Node*get_by_scno(Node*phead,int point,Node*phead2,int point2)//
{	Node*p=phead->next;
	while(p!=NULL){
		Student*pmove=(Student*)p->data;
		if(pmove->sno==point){
			printf("学号:%d",pmove->sno);
			printf("\t姓名:%s",pmove->sname);
		}
		p=p->next;
	}
	Node*p2=phead2->next;
	while(p2!=NULL){
		Course*pmove2=(Course*)p2->data;
		if(pmove2->cno==point2){
			printf("课程号：%d",pmove2->cno);
			printf("课程名：%s",pmove2->cname);
		}
		p2=p2->next;
	}
	return 0;
	
}
Node*get_by_scname(Node*phead,char*point,Node*phead2,char*point2,Node*phead3)//
{	int ptemp1=0,ptemp2=0;
	Node*p=phead->next;
	while(p!=NULL){
		Student*pmove=(Student*)p->data;
		if(strcmp(pmove->sname,point)==0){
			ptemp1=pmove->sno;
			printf("学号:%d",pmove->sno);
			printf("\t姓名:%s",pmove->sname);
		}
		p=p->next;
	}
	Node*p2=phead2->next;
	while(p2!=NULL){
		Course*pmove2=(Course*)p2->data;
		if(strcmp(pmove2->cname,point2)==0){
			ptemp2=pmove2->cno;
			printf("课程号：%d",pmove2->cno);
			printf("课程名：%s",pmove2->cname);
		}
		p2=p2->next;
	}
	Node*p3=phead3->next;
				while(p3!=NULL){
				SC*pmove=(SC*)p3->data;
				if(pmove->cno==ptemp1&&pmove->sno==ptemp2){
				printf("成绩：%.1f\n",pmove->score);	
					
					}
				p3=p3->next;
					}
	return 0;
	
}
int get_Corse_crose_bysno(Node*phead,Node*phead2,int point)//
{	printf("该学生所选课程信息如下：\n");
	int i=size_List(phead);
	Node*ptemp2=phead->next;
	while(ptemp2!=NULL){SC*pmove=(SC*)ptemp2->data;
		if(pmove->sno==point){
		
	Node*p2=phead->next;
	while(p2!=NULL){
		Course*pmove2=(Course*)p2->data;
		if(pmove2->cno==pmove->cno){
			printf("课程号：%d",pmove2->cno);
			printf("课程名：%s",pmove2->cname);
		}
		p2=p2->next;
	}	printf("成绩:%.1f\n",pmove->score);
		}
		ptemp2=ptemp2->next;
	}	
	int j=0,k=0,e=0;
	int a[i]={'\0'};//学号
	float b[i];//成绩总分
	int c[i]={0};//报课程数量
	Node*p=phead->next;
	while(p!=NULL){SC*temp=(SC*)p->data;k=0;e=0;
		while(a[k]!=NULL){
			if(temp->sno==a[k]){c[k]++;b[k]+=temp->score;e++;break;}
			else k++;
		}if(e==0){a[k]=temp->sno;c[k]=c[k]+1;b[k]=b[k]+temp->score;}
		p=p->next;
	}
	int z=0;int m=0;int w=0;
	while(a[z]!=NULL){if(a[z]==point){m=z;break;}else z++;}
z=0;	while(a[z]!=NULL){if(b[z]/(float)c[z]>b[m]/(float)c[m])w++;z++;}
z=0;	while(a[z]!=NULL){
		float pp=b[z]/(float)c[z];
		if(a[z]==point){printf("平均成绩为:%.1f排名:%d总成绩为:%.1f\n",b[z]/(float)c[z],w+1,b[z]);
		}
		z++;
	}
	return 0;
}
int get_most_average_score(Node*phead,Node*phead2)//求平均成绩最高的学生
{	int i=size_List(phead);
printf("分数最高学生信息如下：\n");
	int j=0,k=0,e=0;
	int a[i]={'\0'};//学号
	float b[i];//成绩总分
	int c[i]={0};//报课程数量
	int maxsno;float maxscore;
	Node*p=phead->next;
	while(p!=NULL){SC*temp=(SC*)p->data;k=0;e=0;
		while(a[k]!=NULL){
			if(temp->sno==a[k]){c[k]++;b[k]+=temp->score;e++;break;}
			else k++;
		}if(e==0){a[k]=temp->sno;c[k]=c[k]+1;b[k]=b[k]+temp->score;}
		p=p->next;
	}
	int z=0;maxscore=b[z]/(float)c[z];
	while(a[z]!=NULL){
		float pp=b[z]/(float)c[z];
		if(pp>maxscore){maxscore=pp;
		}
		z++;
	}
	z=0;
	while(a[z]!=NULL){
		float pp=b[z]/(float)c[z];
		if(pp==maxscore){printf("平均成绩为:%.1f",pp);get_sno(phead2,a[z]);
		}
		z++;
	}
	return 0;
}
Node*get_sname(Node*phead,char*point)//获取学生姓名
{	Node*p=phead->next;
	while(p!=NULL){
		Student*pmove=(Student*)p->data;
		if(strcmp(pmove->sname,point)==0){
			printf("学号:%d",pmove->sno);
			printf("\t年龄:%d",pmove->age);
			printf("\t姓名:%s",pmove->sname);
			printf("\t性别:%s",pmove->gender);
			printf("\t民族:%s\n",pmove->nation);
		}
		p=p->next;
	}
	return 0;
	
}
Node*get_first(Node*phead)//获取头节点
{Node*p=phead->next;
	
			Student*pmove=(Student*)p->data;
			printf("学号:%d",pmove->sno);
			printf("\t年龄:%d",pmove->age);
			printf("\t姓名:%s",pmove->sname);
			printf("\t性别:%s",pmove->gender);
			printf("\t民族:%s\n",pmove->nation);
			p=p->next;
	
	return 0;
}
Node*get_last(Node*phead)//获取尾节点
{Node*p=phead->next;
	while(p!=NULL){
		if(p->next==NULL){Student*pmove=(Student*)p->data;
			printf("学号:%d",pmove->sno);
			printf("\t年龄:%d",pmove->age);
			printf("\t姓名:%s",pmove->sname);
			printf("\t性别:%s",pmove->gender);
			printf("\t民族:%s\n",pmove->nation);
		}
		p=p->next;
	}
	return 0;
}
Node*get_cno(Node*phead,int point)//课程号获取信息
{	Node*p=phead->next;
	while(p!=NULL){
		Course*pmove=(Course*)p->data;
		if(pmove->cno==point){
			printf("课程号：%d",pmove->cno);
			printf("课程名：%s",pmove->cname);
			printf("课程分：%.1f\n",pmove->credit);
		}
		p=p->next;
	}
	return 0;
	
}

Node*get_credit(Node*phead,float point)//学分获取信息
{	Node*p=phead->next;
	while(p!=NULL){
		Course*pmove=(Course*)p->data;
		if(pmove->credit==point){
			printf("课程号：%d",pmove->cno);
			printf("课程名：%s",pmove->cname);
			printf("课程分：%.1f\n",pmove->credit);
		}
		p=p->next;
	}
	return 0;
	
}
Node*get_cname(Node*phead,char*point)//课程名获取
{	Node*p=phead->next;
	while(p!=NULL){
		Course*pmove=(Course*)p->data;
		if(strcmp(pmove->cname,point)==0){
			printf("课程号：%d",pmove->cno);
			printf("课程名：%s",pmove->cname);
			printf("课程分：%.1f\n",pmove->credit);
		}
		p=p->next;
	}
	return 0;
	
}
void sort_sno(Node*phead)//靠学号排序
{Node*p1;
Node*p2;
Node*p3=(Node*)malloc(sizeof(Node));
Student*pk1;
Student*pk2;
for(p1=phead->next;p1!=NULL;p1=p1->next)
{
for(p2=p1->next;p2!=NULL;p2=p2->next)
{pk1=(Student*)p1->data;pk2=(Student*)p2->data;if(pk1->sno>pk2->sno)
{p3->data=p1->data;
p1->data=p2->data;
p2->data=(Student*)p3->data;	
}
}
}
}
void sort_age(Node*phead)//靠年龄排序
{Node*p1;
Node*p2;
Node*p3=(Node*)malloc(sizeof(Node));
Student*pk1;
Student*pk2;
for(p1=phead->next;p1->next!=NULL;p1=p1->next)
{
for(p2=p1->next;p2!=NULL;p2=p2->next)
{pk1=(Student*)p1->data;pk2=(Student*)p2->data;if(pk1->age>pk2->age)
{p3->data=p1->data;
p1->data=p2->data;
p2->data=(Student*)p3->data;	
}
}
}
}
void sort_sname(Node*phead)//靠姓名排序
{Node*p1;
Node*p2;
Node*p3=(Node*)malloc(sizeof(Node));
Student*pk1;
Student*pk2;
for(p1=phead->next;p1->next!=NULL;p1=p1->next)
{
for(p2=p1->next;p2!=NULL;p2=p2->next)
{pk1=(Student*)p1->data;pk2=(Student*)p2->data;if(strcmp(pk1->sname,pk2->sname)>0)
{p3->data=p1->data;
p1->data=p2->data;
p2->data=(Student*)p3->data;	
}
}
}
}
void sort_nation(Node*phead)//靠民族排序
{Node*p1;
Node*p2;
Node*p3=(Node*)malloc(sizeof(Node));
Student*pk1;
Student*pk2;
for(p1=phead->next;p1->next!=NULL;p1=p1->next)
{
for(p2=p1->next;p2!=NULL;p2=p2->next)
{pk1=(Student*)p1->data;pk2=(Student*)p2->data;
if(strcmp(pk1->nation,pk2->nation)>0)
{p3->data=p1->data;
p1->data=p2->data;
p2->data=(Student*)p3->data;	
}
}
}
}
void sort_credit(Node*phead)//靠学分排序
{Node*p1;
Node*p2;
Node*p3=(Node*)malloc(sizeof(Node));
Course*pk1;
Course*pk2;
for(p1=phead->next;p1->next!=NULL;p1=p1->next)
{
for(p2=p1->next;p2!=NULL;p2=p2->next)
{pk1=(Course*)p1->data;pk2=(Course*)p2->data;
if(pk1->credit>pk2->credit)
{p3->data=p1->data;
p1->data=p2->data;
p2->data=(Course*)p3->data;	
}
}
}
}
int scort_average_byscore(Node*phead,Node*phead2)//排序平均成绩节点数据 
{	int i=size_List(phead);
printf("学生成绩排序结果如下：\n");
	int j=0,k=0,e=0;
	int a[i]={'\0'};//学号
	float b[i];//成绩总分
	int c[i]={0};//报课程数量
	Node*p=phead->next;
	while(p!=NULL){SC*temp=(SC*)p->data;k=0;e=0;
		while(a[k]!=NULL){
			if(temp->sno==a[k]){c[k]++;b[k]+=temp->score;e++;break;}
			else k++;
		}if(e==0){a[k]=temp->sno;c[k]=c[k]+1;b[k]=b[k]+temp->score;}
		p=p->next;
	}
	int ptemp;
	float ptemp2;
	for(int m=0;a[m]!=NULL;m++){
		for(int n=m+1;a[n]!=NULL;n++){
			if(b[m]/(float)c[m]<b[n]/(float)c[n]){
				ptemp=a[m];a[m]=a[n];a[n]=ptemp;
				ptemp=c[m];c[m]=c[n];c[n]=ptemp;
				ptemp2=b[m];b[m]=b[n];b[n]=ptemp2;
				
			}
		}
	}
	int z=0;
	while(a[z]!=NULL){
		float pp=b[z]/(float)c[z];
		printf("第%d名平均成绩为:%.1f",z+1,b[z]/(float)c[z]);get_sno(phead2,a[z]);
		
		z++;
	}
	return 0;
}
void addFirst(Node*phead,Node*(*pFunc)(Node*))//插入在头节点
{Node*pnew=(Node*)malloc(sizeof(Node));
pnew->next=NULL;
pnew=pFunc(pnew);
pnew->next=phead->next;
phead->next=pnew;
}
void addLast(Node*phead,Node*(*pFunc)(Node*))//插入在尾节点
{Node*pnew=(Node*)malloc(sizeof(Node));
pnew->next=NULL;
pnew=pFunc(pnew);
Node*p=phead->next;
if(p==NULL)return;
while(p->next!=NULL){
	p=p->next;
}p->next=pnew;
}
void deleteFirst(Node*phead)//删除头节点（第一个学生/课程/成绩）
{ phead->next=phead->next->next;
}
void deleteLast(Node*phead)//删除尾节点（最后一个学生/课程/成绩）
{Node*p=phead->next;
if(p==NULL)return;
while(p->next!=NULL){
	p=p->next;
}p=NULL;
}
void deletepoint_bysno(Node*phead,int point)//删除指定节点（一个学生/课程/成绩）
{Node*p=phead->next;
Node*p2=phead;
Student*temp;
if(p==NULL)return;
while(p!=NULL){temp=(Student*)p->data;
if(temp->sno==point)break;
	p=p->next;p2=p2->next;
}p2->next=p->next;
}
void deletepoint_bysno_cno(Node*phead,int point,int point2)//成绩系统删除指定节点（一个学生/课程/成绩）
{Node*p=phead->next;
Node*p2=phead;
SC*temp;
if(p==NULL)return;
while(p!=NULL){temp=(SC*)p->data;
if(temp->sno==point&&temp->cno==point2)break;
	p=p->next;p2=p2->next;
}p2->next=p->next;
}
void deletepoint_bycno(Node*phead,int point)//删除指定节点（一个学生/课程/成绩）
{Node*p=phead->next;
Node*p2=phead;
Course*temp;
if(p==NULL)return;
while(p!=NULL){temp=(Course*)p->data;
if(temp->cno==point)break;
	p=p->next;p2=p2->next;
}p2->next=p->next;
}
void modify_bysno(Node*phead,Node*(*pFunc)(Node*),int point)//修改信息
{Node*pnew=(Node*)malloc(sizeof(Node));
pnew->next=NULL;
pnew=pFunc(pnew);

Node*p=phead->next;
Node*p2=phead;
Student*temp;
if(p==NULL)return;
while(p!=NULL){temp=(Student*)p->data;
if(temp->sno==point)break;
	p=p->next;p2=p2->next;
}p2->next=pnew;
pnew->next=p->next;
}
void modify_bycno(Node*phead,Node*(*pFunc)(Node*),int point)//修改信息
{Node*pnew=(Node*)malloc(sizeof(Node));
pnew->next=NULL;
pnew=pFunc(pnew);
Node*p=phead->next;
Node*p2=phead;
Course*temp;
if(p==NULL)return;
while(p!=NULL){temp=(Course*)p->data;
if(temp->cno==point)break;
	p=p->next;p2=p2->next;
}p2->next=pnew;
pnew->next=p->next;
}
void modify_bysno_cno(Node*phead,Node*(*pFunc)(Node*),int point,int point2)//修改信息
{Node*pnew=(Node*)malloc(sizeof(Node));
pnew->next=NULL;
pnew=pFunc(pnew);
Node*p=phead->next;
Node*p2=phead;
SC*temp;
if(p==NULL)return;
while(p!=NULL){temp=(SC*)p->data;
if(temp->sno==point&&temp->cno==point2)break;
	p=p->next;p2=p2->next;
}p2->next=pnew;
pnew->next=p->next;
}
void read_infotofile(Node*head,char *filename,int bythecount)
{FILE*fp;fp=fopen(filename,"rb");
while(1){void*data=malloc(bythecount);		
		
	if(fread(data,bythecount,1,fp)==1)head=addtofirst(head,data);
	else break;
}fclose(fp);
}
void write_infotofile(Node*head,char*filename,int bythecount)
{FILE*fp;
Node*pmove=head->next;
fp=fopen(filename,"wb");
while(pmove)
{
fwrite(pmove->data,bythecount,1,fp);
pmove=pmove->next;
}fclose(fp);
}