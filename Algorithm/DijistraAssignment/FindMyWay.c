#include<stdio.h>
#include<string.h>
#define INFINITY 999
#define MAX 10
#define BLACK 1
#define WHITE 2
// Declare node as Structure
struct NODE
{
    int parent;
    int time;
    int color;
} pathInfo[MAX];
// Prototype of relaxation function
void relax(int adjacency[MAX][MAX],int sourceNode,int vertices);
//  Declare pointer of character array
char *VertexName[MAX];
// function to find shortest path
int findShortestPath(int adjacency[MAX][MAX],int vertices,int source, int destination,int shortestPath[MAX],int *time)
{
    int i =0,nodes = 0,k = 0,sourceNode = 0,mintime = 0,tempPath[MAX];
    *time = 0;
    // initialization
    // set initially INFINITY for all vertices
    for(i = 1; i<vertices+1; i++)
    {
        pathInfo[i].parent = 0;
        pathInfo[i].time = INFINITY;
        pathInfo[i].color = WHITE;
    }
    // Initialize source vertex
    pathInfo[source].parent = 0;
    pathInfo[source].time = 0;
    pathInfo[source].color = BLACK;
    sourceNode = source;

    do
    {
        // calling relax function
        relax(adjacency,sourceNode,vertices);
        mintime = INFINITY;
        sourceNode = 0;
        for(i = 1; i<vertices+1; i++)
        {
            if( (pathInfo[i].color == WHITE) && (pathInfo[i].time < mintime))
            {
                mintime = pathInfo[i].time;
                sourceNode = i;
            }
        }
        if(sourceNode == 0)
        {
            return 0;
        }
        pathInfo[sourceNode].color = BLACK;
    }
    while(sourceNode != destination);
    sourceNode = destination;
    do
    {
        nodes = nodes + 1;
        tempPath[nodes] = sourceNode;

        sourceNode = pathInfo[sourceNode].parent;

    }
    while(sourceNode != 0);
    for(i = 1; i<nodes + 1; i++)
    {
        shortestPath[i] = tempPath[nodes-i+1];


    }

    for(i = 1; i<nodes; i++)
    {

        *time = *time + adjacency[shortestPath[i]][shortestPath[i+1]];


    }

    return nodes;
}

//Relaxation Function
void relax(int adjacency[MAX][MAX],int sourceNode,int vertices)
{
    int i;
    for(i = 1; i<vertices+1; i++)
    {
        if((adjacency[sourceNode][i]>0) && (pathInfo[i].color == WHITE))
        {
            if((pathInfo[sourceNode].time + adjacency[sourceNode][i])< pathInfo[i].time)
            {
                pathInfo[i].parent = sourceNode;
                pathInfo[i].time = pathInfo[sourceNode].time + adjacency[sourceNode][i];

            }
        }

    }
}

int main()
{
    int i = 0,j=0,n =0,to = 0,from = 0,nodes = 0,length = 0,shortestPath[MAX],adjacent[MAX][MAX];
    printf("Enter your number of Vertices:  ");
    scanf("%d", &n); // number of vertices
    fflush(stdin); // Function to remove string Buffer
    char temp[20];
    printf("Enter Your Vartices Name: \n");
    for( i = 0;i<n;i++)
    {
        gets(temp);
        VertexName[i] = strdup(temp);

    }
    char str1[20],str2[20],flag = 0;
    printf("\nEnter Delay time for edges of vertices: ");
    // Input edges weight (times)
    for(i = 1; i<n+1; i++)
    {
        printf("\n");
        for(j = 1; j<n+1; j++)
        {
            printf("Weight of EDGE from %s to %s is: ",*(VertexName+i-1),*(VertexName+j-1));
            fflush(stdin);
            scanf("%d",&adjacent[i][j]);

        }
    }
    fflush(stdin);
    printf("\n\nFind Shortest Path: \n");
    printf("    Type Place name is given format: Source Vertex: ");
    gets(str1); // Take input source vertex
    for(i=0; i<n; i++)
    {
        if(strcmp(str1,*(VertexName+i))==0) // Compare String
        {
            j = i+1;
            flag = 1;
            break;
        }

    }
    if(flag == 0)
    {
        printf("Enter Valid Area name");
    }
    from = j;

    printf("   Type Place name is given format: Destination Vertex: ");
    gets(str2); // Take input Destination vertex
    for(i=0; i<n; i++)
    {
        if(strcmp(str2,*(VertexName+i))==0) // Compare String
        {
            j= i+1;
            flag = 1;
            break;
        }

    }
    if(flag == 0)
    {
        printf("Enter Valid Area name");
    }
    to = j;

    nodes = findShortestPath(adjacent,n,from,to,shortestPath,&length);
    //Print Path from source to destination vertex
    if(length)
    { // find shortest time from source to destination
        printf("\nMinimum Time from source to each vertices: \n");
        for(i=1; i<=n; i++)
        {
            printf("From %s to %s =  %d\n",str1,*(VertexName+i-1),pathInfo[i].time);

        }
        printf("    Shortest Path: %s",str1);
        for(i = 2; i<nodes + 1; i++)
        {
            j = shortestPath[i];
            printf("-> %s ",*(VertexName+j-1));
        }


        // print minimum delay information from source to destination vertex
        printf("\n\n%s to %s Minimum delay time: %d",str1,str2,length);
    }

    else
    {
        printf("\n\nNo Path is Available");
    }
    return 0;

}

