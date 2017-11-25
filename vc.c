//This is a model program for coloring a certain no. of nodes such that connected nodes are not colored with same colors
//and using minimum number of colors.
#include<stdio.h>
#include<math.h>
int m[10][10];  //defined a matrix using arrays of arrays
int deg[11],w[11]={0,1,2,3,4,5,6,7,8,9,10};  //deg stores degrees of vertices while 'w' stores vertices sorted in descending order of degrees
int i=1,j=1,v,c=0;
char color[8]={0,'v','i','b','g','y','o','r'};  //stored initials of colors
void vertexcolor()
{
	int cdeg[7]; 	//cdeg is assigned value 1 to vertices already colored while 0 to others
	cdeg[0]=0;
	for(i=1;i<=v;i++)
	{
		if(cdeg[i]!=1)
		{
			printf("the color of %d is %c\n",w[i],color[i]);
			cdeg[1]=1;			
		}
		for(j=1;i+j<=v;j++)
		{  //checks connectivity with previous vertex and cdeg value
			if(m[w[i]][w[i+j]]==0 && cdeg[i+j]!=1)
			{
				printf("the color of %d is %c\n",w[i+j],color[i]);
				cdeg[i+j]=1;
			}
		}
	}
}
int sort(int v) //sorting vertices in descending order of degrees using recurrsion
{
	i=1;
	if(v==1)
	{
		return 0;
	}
	while(i<v)
	{
		if(deg[w[i]]<deg[w[i+1]])
		{
			c=w[i];
			w[i]=w[i+1];
			w[i+1]=c;
		}
		i++;
	}
	sort(v-1);
}
void display()
{
	i=1;
	while(i<=v)
	{
		printf("%d",w[i]);
		i++;
	}
}
int main()
{
printf("we'll take input from you in the form of a matrix of vertices x vertices,\n"
	"where in the value 1 for a combination means there exists an\nundirected edge between those two vertices.\nEnter the number of vertices:");
scanf("%d",&v);
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			m[i][j]=-1;
		}
	}
	i=1,j=1;
	for(;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(m[i][j]==-1) //accepts value only if combination doesn't have connectivity.
			{
				printf("\nenter the edge value for %d,%d in binary:",i,j);
				scanf("%d",&m[i][j]);
				m[j][i]=m[i][j]; //undirected graph condition
			}
			if(m[i][j]==1 && i!=j) //counts degree of vertex excluding connectivity of a vertex with itself
			{
				c++;
			}
		}
		deg[i]=c;
		c=0;
	}
	printf("\nthe sorted array is:");
	sort(v);
	display();
	printf("\n");
	vertexcolor();
}
