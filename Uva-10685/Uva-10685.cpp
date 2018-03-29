#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char string[100],creature1[32],creature2[32];
struct creature_node{
	int ID;
	struct creature_node* next;
	struct creature_node* pre;
};
struct creature{
	char name[32];
	int ID;
};
struct creature_node *first = NULL,*new_node = NULL;
struct creature_node *ptr = (struct creature_node *)malloc(5001*sizeof(struct creature_node));
struct creature chain[5001];
struct creature_node* make_bond(int big,int small);
int main(void)
{
   int cre_num,bond_num;
	int i,j;
	int num1,num2;
	char buffer[5];
	while(1)
	{
		scanf("%d %d",&cre_num,&bond_num);
		if(cre_num + bond_num == 0)
		break;
		fgets(buffer,sizeof(buffer),stdin);
		for(i=1;i<=cre_num;i++)
		{
			
			fgets(chain[i].name,sizeof(chain[i].name),stdin);
			chain[i].ID = i;
			for(int y=0;y<=31;y++)
			{
				if(chain[i].name[y]=='\n')
				{
					chain[i].name[y] = '\0';
					break;
				}
				
			}		
		}
		for(j=0;j<bond_num;j++)
		{
			fgets(string,sizeof(string),stdin);
			sscanf(string,"%s %s",creature1,creature2);
			for(int k=1;k<=cre_num;k++)
			{
				if(strcmp(chain[k].name,creature1)==0)
				{
					num1 = chain[k].ID;
				}
				if(strcmp(chain[k].name,creature2)==0)
				{
					num2 = chain[k].ID;
				}
			}
				if((ptr+num1)->next == NULL)
				(ptr+num1)->next = make_bond(num1,num2);
				else
				{
				for(first = ptr+num1;first!=NULL;first = first->next)
				{
					 if(first->next ==NULL)
						{
							new_node =(struct creature_node*) malloc(sizeof(struct creature_node));
							new_node->ID = num2;
							first->next = new_node;
						}
				}
				}
				
				
				
			
			
		}
		int num=0,max;
		max = num;
		for(int x=1;x<=cre_num;x++)
		{
			
			
			for(first = (ptr+x),num =0;first!=NULL;first = first->next)
			{
				num++;	
			}
			if(max <num)
			{
				max = num;
			}
			
			
		}
		printf("%d\n",max);
		
		
		
		
	}
	return 0;
}
struct creature_node* make_bond(int big,int small)
{
	struct creature_node *header;
	struct creature_node *new_node;
	new_node = (struct creature_node*)malloc(sizeof(struct creature_node));
	
	new_node->ID = big;
	header = new_node;
	new_node = (struct creature_node*)malloc(sizeof(struct creature_node));
	new_node->ID = small;
	new_node->pre = header;
	header->next = new_node;

	return header;
	
}
