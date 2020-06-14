# AO-STAR-algorithm

Above code is the implementation of AO STAR algorithm in AI domain.

## Language used 

C++

## input

I have provided 2 input files named input1 and input2. You can use that input file and also you can use your own input.


## Prerequisites:

First I will recommend you to know what is AND-OR Graph.
Also u must have knowledge of A* algorithm

## Representation of AND-OR Graph:

Graph : vector of vector of struct node. 
Struct node :
 index //represent index of child
edge //edge cost of visiting this child from current node
gate //different gate number for different OR gate and same gate number for same AND gate

We are given start node and graph
We have to travel and reach goal node (leaf node) with minimum cost of travelling
It is guided search technique, so every node has heuristic value( h(x) ) giving as estimate of cost of reaching  goal node from current node.	
Heuristic value is always underestimated, So AO* algorithm only works is heuristic values are under-estimated 


## Algorithm:

Call fun(0) until it return 1
fun(current){
If( we reach leaf node)
{ then mark its node.index as -5
// denoting that it is solved 
then return 1;
}
Call utility function min_node;
//min_node will return 3 values 
// it will return minimum f(x) among its children
// f(x)=h(x)+edge
// other two values will give information about minimum children choosen 
If (minimum f(x) value returned by min_node  is not equal to current h(x) ){
Update current]-&gt;h(x) with value returned by min_node
return 0;
}
Travel to all minimum nodes  by calling fun(index of child)
If( All travelled children returned 1)
{	Update current with minimum 
	Mark as visited 
	Return 1
}
else {
Update current with minimum and return 0;
}
 
