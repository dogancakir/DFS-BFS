#include<iostream>
#include<fstream>
#include <list>
#include<cmath>

using namespace std;
ifstream file;
ofstream ofile;

int dpth()			//this function is used to determine row of matrix
{
	file.open("input.txt");			
	int counter=0;
	while(!file.eof())
	{
		counter++;
		int taken;
		file>>taken;
	}
	file.close();
	return sqrt(counter);	 //counter = row * column


}
void read(int depth,int **matrix)	//This matrix is used to copy input matrix to
{
	file.open("input.txt");
	for(int i=0;i<depth;i++)
	{
		for(int j=0;j<depth;j++)
		{
			int taken;
			file>>taken;
			matrix[i][j]=taken;
		}
	}

	file.close();
}

void DFS(int **gr,int depth)		//DFS method to find cycle and bipartite
{
	int **parent = new int *[depth];  //parent matrix holds connections between nodes.
	int *visited = new int[depth];	  //visited is used to send a node to stack just one time
	for(int i=0;i<depth;i++) parent[i] = new int [depth];
	for(int i=0;i<depth;i++) for(int j=0;j<depth;j++) parent[i][j]=-1;  //firstly there arent any connections
	for(int i=0;i<depth;i++) visited[i]=-1; //any node is sent to stack
	visited[0]=1; //root is already visited
	int *noOfParent = new int[depth];	//noOfParent array holds the number of connection of for each node 
	for(int i=0;i<depth;i++) noOfParent[i] = 0;	
	int *stack = new int[depth*depth];
	int element =1;	//element number of stack. Firstly, it is 1 to begin while loop
	bool visit = false;	//whether it is find a loop or not
	int i=0;	// it is the element which is popped from stack, firstly root is popped.
	while(element != 0)
	{
		element--;	//element in stack is decreased
		for(int j=0;j<depth;j++)	
		{
			if(gr[i][j]==1&&parent[j][0]==-1&& j!=i) //ýf there is a connection between 2 nodes, nodes push to stack
			{
				stack[element]=j;	//connected element is sent to stack as last element
				element++;			
				parent[j][0]=i;		//using node is sent to connected element's connection matrix
				noOfParent[j]++;	
				visited[j]=1;	
			}
			else if(gr[i][j]==1 && j!=i)
			{
				
				parent[j][noOfParent[j]]=i;
				noOfParent[j]++;
				
			}
		}
		i=stack[element-1];		//element is popped
		
		
	for(int i=0;i<depth;i++) {		//this loops are used to look for cycle
		for(int j=0;j<noOfParent[i];j++)
		{
			for(int k = 0;k<noOfParent[parent[i][j]];k++) 
				{
					for(int l=0;l<noOfParent[parent[parent[i][j]][k]];l++)
						if(parent[i][0]!=-1)
				if(i==parent[parent[parent[i][j]][k]][l] && !visit)		//if parent of parent of parent of a node is equal to itself, there is a cycle.
							{
								cout<<"DFS: "<<i+1<<" "<<parent[i][j]+1<<" "<<parent[parent[i][j]][k]+1<<endl;
								ofile<<"DFS: "<<i+1<<" "<<parent[i][j]+1<<" "<<parent[parent[i][j]][k]+1<<endl;
								visit = true;
								
							}
				}
		}
	}
		
	}
	cout<<"according to DFS: ";
	ofile<<"according to DFS: ";
	if(visit)	//If there is a cycle which have 3 elements, it is NOT bipartite 
	{
		ofile<<"NOT BIPARTITE"<<endl;
		cout<<"NOT BIPARTITE"<<endl;
	}
	else
	{
		cout<<"BIPARTITE because there are NOT any cycle which has 3 element."<<endl;
		ofile<<"BIPARTITE because there are NOT any cycle which has 3 element."<<endl;
	}
}

void BFS(int **gr,int depth)		//In this method, just queue is used instead of stack. Other parts but queue is same as DFS
{
	int **parent = new int *[depth];
	int *visited = new int[depth];
	for(int i=0;i<depth;i++) parent[i] = new int [depth];
	for(int i=0;i<depth;i++) for(int j=0;j<depth;j++) parent[i][j]=-1;
	for(int i=0;i<depth;i++) visited[i]=-1;
	visited[0]=1;
	int *noOfParent = new int[depth];
	for(int i=0;i<depth;i++) noOfParent[i] = 0;
	int *queue = new int[depth*depth];	
	int element =1;
	bool visit = false;
	int i=0;
	while(element != 0)
	{
		element--;
		for(int j=0;j<depth;j++)
		{
			if(gr[i][j]==1&&parent[j][0]==-1 && j!=i)
			{
				queue[element]=j;
				element++;
				parent[j][0]=i;
				noOfParent[j]++;
				visited[j]=1;
			}
			else if(gr[i][j]==1 && j!=i)
			{
				
				parent[j][noOfParent[j]]=i;
				noOfParent[j]++;
				
			}
		}
		i=queue[0];			//using element is the first element which is pushed to queue firstly.
		
		for(int j = 0;j<element;j++) queue[j]= queue[j+1];	//shifting the elements.
		
				for(int i=0;i<depth;i++) {
		for(int j=0;j<noOfParent[i];j++)
		{
			for(int k = 0;k<noOfParent[parent[i][j]];k++) 
				{
					for(int l=0;l<noOfParent[parent[parent[i][j]][k]];l++)
						if(parent[i][0]!=-1)
							if(i==parent[parent[parent[i][j]][k]][l] && !visit)
							{
								cout<<"BFS: "<<i+1<<" "<<parent[i][j]+1<<" "<<parent[parent[i][j]][k]+1<<endl;
								ofile<<"BFS: "<<i+1<<" "<<parent[i][j]+1<<" "<<parent[parent[i][j]][k]+1<<endl;
								visit = true;
							}
				}
		}
	}
		
	}
	cout<<"according to BFS: ";
	ofile<<"according to BFS: ";
	if(visit)
	{
		ofile<<"NOT BIPARTITE"<<endl;
		cout<<"NOT BIPARTITE"<<endl;
	}
	else
	{
		cout<<"BIPARTITE because there are NOT any cycle which has 3 element."<<endl;
		ofile<<"BIPARTITE because there are NOT any cycle which has 3 element."<<endl;
	}

}
int main()
{	
	int depth = dpth();			//depth = number of rows or columns

	int **gr=new int *[depth];		//gr holds the input matrix
	for(int i=0;i<depth;i++) gr[i]= new int [depth];

	read(depth,gr);		//input matrix is copied to gr
	ofile.open("output.txt");	//output file is created
	BFS(gr,depth);				
	DFS(gr,depth);
	ofile.close();
	cout<<"Output file is created!!"<<endl;
	return 0;
}