#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5  // Maximum number of vertices in the graph

// Define a structure for a graph vertex
struct Vertex {
    char label;    // Label to identify the vertex (e.g., 'A', 'B', etc.)
    bool visited;  // Flag to check if the vertex has been visited during DFS
};

// Stack implementation
int stack[MAX];  // Array to hold the stack elements
int top = -1;    // Variable to keep track of the top of the stack

// Array of pointers to hold all the vertices of the graph
struct Vertex* lstVertices[MAX];

// Adjacency matrix to represent the graph connections
int adjMatrix[MAX][MAX];

// Number of vertices currently in the graph
int vertexCount = 0;

// Function to push an item onto the stack
void push(int item) {
    stack[++top] = item;  // Increment top and add the item to the stack
}

// Function to pop an item from the stack
int pop() {
    return stack[top--];  // Return the top item and then decrement top
}

// Function to get the item on the top of the stack without removing it
int peek() {
    return stack[top];
}

// Function to check if the stack is empty
bool isStackEmpty() {
    return top == -1;
}

// Function to add a vertex to the graph
void addVertex(char label) {
    // Allocate memory for a new vertex
    struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    vertex->label = label;      // Set the label of the vertex
    vertex->visited = false;    // Initialize as not visited
    lstVertices[vertexCount++] = vertex;  // Add the vertex to the list and increment count
}

// Function to add an edge (connection) between two vertices in the graph
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;  // Set the connection from start to end
    adjMatrix[end][start] = 1;  // Set the connection from end to start (since the graph is undirected)
}

// Function to display the label of a vertex given its index
void displayVertex(int vertexIndex) {
    printf("%c ", lstVertices[vertexIndex]->label);
}

// Function to get the index of an adjacent, unvisited vertex of a given vertex
int getAdjUnvisitedVertex(int vertexIndex) {
    for(int i = 0; i < vertexCount; i++) {
        // Check if there's an edge between vertexIndex and i, and if i is unvisited
        if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
            return i;  // Return the index of the adjacent unvisited vertex
        }
    }
    return -1;  // Return -1 if no unvisited adjacent vertices are found
}

// Function to perform Depth-First Search starting from the first vertex
void depthFirstSearch() {
    // Mark the first vertex as visited and display it
    lstVertices[0]->visited = true;
    displayVertex(0);

    // Push the index of the first vertex onto the stack
    push(0);

    // Loop until the stack is empty
    while(!isStackEmpty()) {
        // Get the adjacent unvisited vertex of the vertex at the top of the stack
        int unvisitedVertex = getAdjUnvisitedVertex(peek());

        if(unvisitedVertex == -1) {
            // If no adjacent unvisited vertices, pop the stack
            pop();
        } else {
            // If there's an unvisited adjacent vertex, mark it as visited
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);  // Display the vertex
            push(unvisitedVertex);  // Push it onto the stack
        }
    }

    // Reset the visited flag for all vertices for future operations
    for(int i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = false;
    }
}

// Main function to set up the graph and perform DFS
int main() {
    // Initialize the adjacency matrix to 0 (no connections)
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Add vertices to the graph
    addVertex('S'); // 0
    addVertex('A'); // 1
    addVertex('B'); // 2
    addVertex('C'); // 3
    addVertex('D'); // 4

    // Add edges (connections) between vertices
    addEdge(0, 1); // S - A
    addEdge(0, 2); // S - B
    addEdge(0, 3); // S - C
    addEdge(1, 4); // A - D
    addEdge(2, 4); // B - D
    addEdge(3, 4); // C - D

    // Perform Depth-First Search
    printf("Depth First Search: ");
    depthFirstSearch();

    return 0;  // Exit the program
}
