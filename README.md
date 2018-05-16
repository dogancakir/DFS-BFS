		1.A. Pseudo code of algorithm 
 
			Main function 
					Copy input file to gr which is 2D array ; 
					Run BFS function; 
					Run DFS function; 
						Return 0; 
 
			BFS(gr,depth)   
				depth<- number of row of gr 
				Create a 2D array parent[depth][depth]; 
				Create an array visited[depth]; 
				for(int i=0;i<depth;i++) visited[i]<- -1; 
				for(int i=0;i<depth;i++) for(int j=0;j<depth;j++) parent[i][j]<- -1; 
				Create an array noOfParent[depth]; 
				for(int i=0;i<depth;i++) noOfParent[i] <- 0; 
				Create an array queue[depth*depth]; 
				element <- 1; 
				visit <- false; 
				i <- 0 (root) 
				while loop until queue is empty. 
				{ 
				 element<-element-1; 
				 for loop until all connections between i and other nodes are found 
				 if there is a connection 
				  push this element to queue 
				  element<-element+1; 
				  parent[j][noOfParent[j]]<-i; 
				  noOfParent[j]<- noOfParent[j]+1; 
				  visited[j]<-1; 
				 exit if 
				exit for loop; 
				i <- pop from queue 
				if i = = parent[parent[parent[i]]] 
				 There is a cycle which have 3 nodes. 
				 visit <- true; 
				 exit if ; 
				exit while loop; 
				if visit<-true 
				 print “NOT BIPARTITE” 
				else 
				 print ”PARTITE” 
 
			DFS(gr,depth)   depth<- number of row of gr 
				Create a 2D array parent[depth][depth]; 
				Create an array visited[depth]; 
				for(int i=0;i<depth;i++) visited[i]<- -1; 
				for(int i=0;i<depth;i++) for(int j=0;j<depth;j++) parent[i][j]<- -1; 
				Create an array noOfParent[depth]; 
				for(int i=0;i<depth;i++) noOfParent[i] <- 0; 
				Create an array stack[depth*depth]; 
				element <- 1; 
				visit <- false; 
				i <- 0 (root) 
				while loop until stack  is empty. 
				{ 
				 element<-element-1; 
				 for loop until all connections between i and other nodes are found 
				 if there is a connection 
				  push this element to stack 
				  element<-element+1; 
				  parent[j][noOfParent[j]]<-i; 
				  noOfParent[j]<- noOfParent[j]+1; 
				  visited[j]<-1; 
				 exit if 
				exit for loop; 
				i <- pop from stack 
				if i = = parent[parent[parent[i]]] 
				 There is a cycle which have 3 nodes. 
				 visit <- true; 
				 exit if ; 
				exit while loop; 
				if visit<-true 
				 print “NOT BIPARTITE” 
				else 
				 print ”PARTITE” 
 
 
 
		1. B. Explaining of Methods 
		dpth()  is used to find how many row our input file have. Row number is used in all loops 
		read() is used to copy matrix from input file to our program.  
		BFS() is used to apply Breadth-First Search algorithm. In this method cycles which has 3 elements are found via Breadth-First Search algorithm and whether graph is partite or not. 
		DFS() is used to apply Depth-First Search algorithm. In this method cycles which has 3 elements are found via Depth-First Search algorithm and whether graph is partite or not. 
 
 
		2. A. Extra Complexity 
		There are 5 nested loops in my function so complexity of function is O(n5). 

		
		2. B. Complexity Of Adjacency List Representation 
		There can be just one loop so complexity of function would be O(n). There is a big difference between O(n) and O(n5). 
 

 
		3. Explaining the idea 
		If there is a cycle which has 3 elements, the graph can not be bipartite. So I just look  
	for cycle which has 3 elements. If there is a cycle, it is not bipartite else it is bipartite. 
	I use an array for queue to implement BFS. Array supplies the FIFO rule. 
	I use an array for stack to implement DFS. Array supplies the LIFO rule.  
	I explain all line of my codes using comments. 