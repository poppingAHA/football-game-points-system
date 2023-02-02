#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <String.h>
#define N 16
struct dz{	//记录单场比赛信息 
	int dsID;//对手ID
	int mydf;//我方得分
	int dsdf;//对手得分 
};
struct fbteam{
	int ID;//球队编号 
    char name[10];//球队名称
    int score;//球队积分
    int jsqs;//净胜球数
    int zjqs;//总进球数
    double pxf;//排序分
    char fz; //分组
    struct dz dz_score[N];//记录每场比赛各球队的比分 
    int score2;
    int jsqs2;
    int zjqs2;
}ft[N];
int n=0;//球队的个数
void add(){  //增加球队
    n++;
    getchar();
    printf("请输入第%d支球队的名称：",n);
    gets(ft[n].name);
    printf("请输入所在的小组：（如第一组输入1）\n");
    scanf("%c",&ft[n].fz);
    ft[n].ID=n;
}
int lookup(char qdstr[]){  //查找球队
    int i;
    for(i=1;i<=n;i++){
        if(strcmp(ft[i].name,qdstr)==0){
            return i;
        }
    }
    return 0;
}
void myprint(int i){   //输出某球队信息
    printf("\n球队名称 积分 净胜球数 总进球数 小组\n");
    printf("%s\t%d\t%d\t%d\t%c\n",ft[i].name,ft[i].score,ft[i].jsqs,ft[i].zjqs,ft[i].fz);
}
void print() {	//输出所有球队信息 
	printf("\n球队名称 积分 净胜球数 总进球数 小组\n");
	for(int i=1;i<=n;i++){
		printf("%s\t%d\t%d\t%d\t%c\n",ft[i].name,ft[i].score,ft[i].jsqs,ft[i].zjqs,ft[i].fz);
	}
}
void mod(){    //修改球队
    int i,j;
    int x=0,y=0;    //比分
    int t;  //用来比较两支球队的比分
    int a;  //查找要修改的球队的下标 
    int k; //用来选择修改的球队信息 
    int m; //用来选择对战球队的编号 
    char qdstr[20];
    getchar();
    printf("请输入要修改的球队名称：");
    gets(qdstr);
    a=lookup(qdstr);
    if(a!=0){
        myprint(a);
        printf("请选择要修改的信息：\n");
        printf("1、球队名称 2、得分情况 \n");
        scanf("%d",&k);
        switch(k){
            case 1:
                printf("请输入球队的新名称：");
                scanf("%s",ft[a].name);
                break;
            case 2:
                printf("请选择要修改与哪支球队之间的比分：\n");
                for(i=1;i<=n;i++){
                	if(ft[a].dz_score[i].dsID!=0){
                		printf("编号%d球队\t",ft[a].dz_score[i].dsID);
					}
				}
				printf("\n请输入球队编号：");
				scanf("%d",&m);
				for(i=1;i<=n;i++){
					if(ft[a].dz_score[i].dsID==m){
						printf("\n原来比分为：%d-%d\n",ft[a].dz_score[i].mydf,ft[a].dz_score[i].dsdf);
						t=ft[a].dz_score[i].mydf-ft[a].dz_score[i].dsdf;
						ft[a].jsqs = ft[a].jsqs-t;
						ft[m].jsqs = ft[m].jsqs-(-t);
						ft[a].zjqs = ft[a].zjqs-ft[a].dz_score[i].mydf;
						ft[m].zjqs = ft[m].zjqs-ft[a].dz_score[i].dsdf;
						if(t>0){
							ft[a].score=ft[a].score-3;
						}else if(t==0){
							ft[a].score=ft[a].score-1;
							ft[m].score=ft[m].score-1;
						}else{
							ft[m].score=ft[m].score-3;
						}
						printf("请输入两球队的比分(如2-3)：");
						scanf("%d-%d",&x,&y);
						ft[a].dz_score[i].mydf=x;
						ft[a].dz_score[i].dsdf=y;
						ft[i].dz_score[a].dsdf=x;
						ft[i].dz_score[a].mydf=y;
						t=x-y;
						ft[a].jsqs=ft[a].jsqs+t;
						ft[m].jsqs=ft[m].jsqs+(-t);
						ft[a].zjqs=ft[a].zjqs+x;
						ft[m].zjqs=ft[m].zjqs+y;
						if(t>0){   
		                    ft[a].score=ft[a].score+3;     
		                }else if(t==0){     
		                    ft[m].score=ft[m].score+1;      
		                    ft[a].score=ft[a].score+1;
		                }else{       
		                    ft[m].score=ft[m].score+3;      
		                }
					}
				}
                break;			
            default:
                printf("已取消修改！\n");
                break;
        }
        print();
    }else{
        printf("找不到该球队信息！\n");
    }
}
void del(){  //删除球队
    int i,j;
    int k;  //选择是否删除
    int a;   //所要删除的球队的下标
    int t;  //比较两球队的比分 
    int x=0,y=0; //记录比分 
    char qdstr[20];
    getchar();
    printf("请输入要删除的球队名称：");
    gets(qdstr);
    a=lookup(qdstr);
    if(a!=0){
        myprint(a);
        printf("请确认是否删除：1、是 2、否\n");
        scanf("%d",&k);
        switch(k){
            case 1:
            	for(i=1;i<=n;i++){
            		if(ft[a].fz==ft[i].fz && a!=i){
            			for(j=1;j<=n;j++){
            				if(ft[a].dz_score[j].dsID==i){
            					x=ft[a].dz_score[j].mydf;
			            		y=ft[a].dz_score[j].dsdf;
			            		t=x-y;
			            		ft[a].jsqs = ft[a].jsqs - t;
			            		ft[i].jsqs = ft[i].jsqs -(-t);
			            		ft[a].zjqs = ft[a].zjqs - x;
			            		ft[i].zjqs = ft[i].zjqs - y;
			            		if(t>0){
			            			ft[a].score=ft[a].score - 3;
								}else if(t==0){
									ft[a].score=ft[a].score - 1;
									ft[i].score=ft[i].score - 1;
								}else{
									ft[i].score=ft[i].score - 3;
								}
							} 
	            					
						}
					}
				}
				for(i=a;i<=n;i++){
					ft[i]=ft[i+1];
				}
				for(i=1;i<=n;i++){
					for(j=1;j<=n;j++){
						if(ft[i].dz_score[j].dsID==a){
							ft[i].dz_score[j].dsID=0;	
							break;
						}
					}
				}
				n--;
                printf("删除成功！\n");
                break;
            case 2:
                printf("已取消删除！\n");
                break;
            default:
                break;
        }
        print();
    }else{
        printf("找不到该球队信息！\n");
    }
}
void input(){    //成绩输入
    int i,j;
    int x=0,y=0;    //比分
    int t;  //用来比较两支球队的比分
    int p=1,q=1;
    if(n>=2){
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(ft[i].fz==ft[j].fz){
                    printf("请输入%s队和%s队的比分（如2-3）：",ft[i].name,ft[j].name);
                    scanf("%d-%d",&x,&y);
                    t=x-y;
                    ft[i].jsqs+=t;
					ft[i].zjqs+=x;
					ft[j].jsqs+=(-t);
					ft[j].zjqs+=y;
					ft[i].dz_score[p].dsID=j;
					ft[i].dz_score[p].mydf=x;
					ft[i].dz_score[p].dsdf=y;
					ft[j].dz_score[q].dsID=i;
					ft[j].dz_score[q].mydf=y;
					ft[j].dz_score[q].dsdf=x;
                    if(t>0){       
                        ft[i].score+=3;                                
                    }else if(t==0){    
                        ft[i].score+=1;      
                        ft[j].score+=1;
                    }else{     
                        ft[j].score+=3;      
                	} 
				    if(j!=n){
				    	p++;
					}                   
                }	
            } 
            p=i+1;
			q=i+1; 
        } 
        printf("各球队对战情况如下:\n");
        for(i=1;i<=n;i++){
        	for(j=1;j<=n;j++){
        		if(ft[i].dz_score[j].dsID>0){
        			printf("编号%d队 vs 编号%d队:%d-%d\n",i,ft[i].dz_score[j].dsID,ft[i].dz_score[j].mydf,ft[i].dz_score[j].dsdf);	
				}
			}
		}
    }else{
        printf("请先增加球队!(至少增加两支球队)\n");
    }
}
void rank(){    //排序
    int i,j,k;
    int a;//记录相同排序分的球队的下标 
    struct fbteam temp;
    int x=0,y=0;//记录排序分相等的球队相互之间比赛的得分 
    int t;//比较排序分相等的球队之间比赛的比分 
    for(i=1;i<=n;i++){
        ft[i].pxf=ft[i].score+ft[i].jsqs*0.01+ft[i].zjqs*0.0001;
    }
    for(i=1;i<=n-1;i++){
        for(j=1;j<=n-i;j++){
            if(ft[j].pxf<ft[j+1].pxf){
               temp=ft[j];
               ft[j]=ft[j+1];
               ft[j+1]=temp;
            }else if(ft[j].pxf==ft[j+1].pxf){
				for(k=1;k<=n;k++){
					if(ft[j].dz_score[k].dsID==ft[j+1].ID){
						a=ft[j+1].ID;
						ft[j].zjqs2=ft[j].dz_score[k].mydf;
						ft[a].zjqs2=ft[j].dz_score[k].dsdf;
						t=ft[j].zjqs2-ft[a].zjqs2;
						ft[j].jsqs2=t;
						ft[a].jsqs2=(-t);
						if(t>0){
							ft[j].score2=3;
						}else if(t==0){
							ft[j].score2=1;
							ft[a].score2=1;
						}else{
							ft[a].score2=3;
						}
					}
				}
				if(ft[j].fz==ft[j+1].fz){
	            	if(ft[j].score2<ft[a].score2){	 //排序分相等，比较相互之间比赛的得分高低 
	            		temp=ft[j];
	            		ft[j]=ft[j+1];
	            		ft[j+1]=temp;
					}else if(ft[j].score2==ft[a].score2){	//相互之间比赛得分相等，比较相互之间比赛的净胜球数 
						if(ft[j].jsqs2<ft[a].jsqs2){	 
							temp=ft[j];
	            			ft[j]=ft[j+1];
	            			ft[j+1]=temp;
						}else if(ft[j].jsqs2==ft[a].jsqs2){	//相互之间比赛净胜球数相等，比较相互之间比赛的进球数 
							if(ft[j].zjqs2<ft[a].zjqs2){
								temp=ft[j];
	            				ft[j]=ft[j+1];
	            				ft[j+1]=temp;
							}else if(ft[j].zjqs2==ft[a].zjqs2){	//相互之间比赛的进球数相等，进行抽签 
				                int r;
				                srand((unsigned)time(NULL));
				                k=rand()%10+1;
				                if(r%2==0){
				                    temp=ft[j];
				                    ft[j]=ft[j+1];
				                    ft[j+1]=temp;
				                }else{
				                    break;
				                }					
							}
						}
					}            	         					
				}else{	//排序分相等但不同组的球队进行抽签 
	                int r;
		            srand((unsigned)time(NULL));
				    k=rand()%10+1;
				    if(r%2==0){
				    temp=ft[j];
				    ft[j]=ft[j+1];
				    ft[j+1]=temp;
				    }else{
				        break;
				    }								
				}	       	                     
            }
        }
    }
    printf("球队名称 积分 净胜球数 总进球数 小组 排名\n");
    for(i=1;i<=n;i++){
        printf("%s\t%d\t%d\t%d\t%c\t%d\n",ft[i].name,ft[i].score,ft[i].jsqs,ft[i].zjqs,ft[i].fz,i);
    }
}
int main(){
    int choice,i;
    while(1){
        //菜单：球队的增加、查找、修改、删除，比赛成绩输入，积分排名
        printf("\n\t\t**********足球小组赛积分管理系统**********\n");
		printf("\t\t\t\t1.增加球队\n");
        printf("\t\t\t\t2.查找球队\n");
        printf("\t\t\t\t3.修改球队\n");
        printf("\t\t\t\t4.删除球队\n");
        printf("\t\t\t\t5.成绩输入\n");
        printf("\t\t\t\t6.积分排名\n");
        printf("\t\t\t\t0.退出系统\n");
        printf("\t\t******************************************\n");
        printf("请选择：");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add();
                break;
            case 2:
                char qdstr[20];
                getchar();
                printf("请输入查找球队的名称：");
                gets(qdstr);
                i=lookup(qdstr);
                if(i!=0){
                   myprint(i);
                }else{
                    printf("找不到该球队信息！\n");
                }
                break;
            case 3:
                mod();
                break;
            case 4:
                del();
                break;
            case 5:
                input();
                break;
            case 6:
                rank();
                break;
            case 0:
                exit(0);
        }
    }
    return 0;
}
