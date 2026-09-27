#include <stdio.h>
#include <stdlib.h>

#define MAX 6

char vertices[MAX] = {'A', 'B', 'C', 'D', 'E', 'F'};

int matrix[MAX][MAX] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 0}
};

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *list[MAX] = {NULL};

struct Node* createNode(int v) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    struct Node *newNode = createNode(v);
    newNode->next = list[u];
    list[u] = newNode;

    newNode = createNode(u);
    newNode->next = list[v];
    list[v] = newNode;
}

void displayMatrix() {
    int i, j;
    printf("\nADJACENCY MATRIX\n\n   ");
    for (i = 0; i < MAX; i++) printf("%c ", vertices[i]);
    printf("\n");
    for (i = 0; i < MAX; i++) {
        printf("%c  ", vertices[i]);
        for (j = 0; j < MAX; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void displayList() {
    int i;
    struct Node *temp;
    printf("\nADJACENCY LIST\n\n");
    for (i = 0; i < MAX; i++) {
        printf("%c -> ", vertices[i]);
        temp = list[i];
        while (temp != NULL) {
            printf("%c ", vertices[temp->vertex]);
            temp = temp->next;
        }
        printf("-> NULL\n");
    }
}

void BFSMatrix(int start) {
    int queue[MAX], visited[MAX] = {0};
    int front = 0, rear = 0, current, i, operations = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("\nBFS using Adjacency Matrix: ");
    while (front < rear) {
        current = queue[front++];
        printf("%c ", vertices[current]);
        for (i = 0; i < MAX; i++) {
            operations++;
            if (matrix[current][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\nBFS operations = %d\n", operations);
}

void BFSList(int start) {
    int queue[MAX], visited[MAX] = {0};
    int front = 0, rear = 0, current, operations = 0;
    struct Node *temp;
    queue[rear++] = start;
    visited[start] = 1;
    printf("\nBFS using Adjacency List: ");
    while (front < rear) {
        current = queue[front++];
        printf("%c ", vertices[current]);
        temp = list[current];
        while (temp != NULL) {
            operations++;
            if (visited[temp->vertex] == 0) {
                queue[rear++] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\nBFS operations = %d\n", operations);
}

void DFSMatrix(int current, int visited[], int *operations) {
    int i;
    visited[current] = 1;
    printf("%c ", vertices[current]);
    for (i = 0; i < MAX; i++) {
        (*operations)++;
        if (matrix[current][i] == 1 && visited[i] == 0)
            DFSMatrix(i, visited, operations);
    }
}

void DFSList(int current, int visited[], int *operations) {
    struct Node *temp;
    visited[current] = 1;
    printf("%c ", vertices[current]);
    temp = list[current];
    while (temp != NULL) {
        (*operations)++;
        if (visited[temp->vertex] == 0)
            DFSList(temp->vertex, visited, operations);
        temp = temp->next;
    }
}

void searchVertex(char key) {
    int i, operations = 0;
    for (i = 0; i < MAX; i++) {
        operations++;
        if (vertices[i] == key) {
            printf("Vertex %c found after %d comparisons\n", key, operations);
            return;
        }
    }
    printf("Vertex %c not found\n", key);
}

void edgeCheckMatrix(char u, char v) {
    int i, j;
    for (i = 0; i < MAX; i++) if (vertices[i] == u) break;
    for (j = 0; j < MAX; j++) if (vertices[j] == v) break;
    if (matrix[i][j] == 1) printf("Matrix: %c-%c exists\n", u, v);
    else printf("Matrix: %c-%c does not exist\n", u, v);
    printf("Edge check operations = 1\n");
}

void edgeCheckList(char u, char v) {
    int i, j;
    struct Node *temp;
    for (i = 0; i < MAX; i++) if (vertices[i] == u) break;
    for (j = 0; j < MAX; j++) if (vertices[j] == v) break;
    temp = list[i];
    while (temp != NULL) {
        if (temp->vertex == j) {
            printf("List: %c-%c exists\n", u, v);
            printf("Edge check operations = 2\n");
            return;
        }
        temp = temp->next;
    }
    printf("List: %c-%c does not exist\n", u, v);
    printf("Edge check operations = 2\n");
}

int main() {
    int visited[MAX], operations, i;

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(4, 5);

    printf("SOCIAL NETWORK GRAPH\n");
    printf("====================\n");
    printf("\nConnections:\n");
    printf("A-B  A-C  B-D  B-E  C-F  E-F\n");

    displayMatrix();
    displayList();

    BFSMatrix(0);
    BFSList(0);

    for (i = 0; i < MAX; i++) visited[i] = 0;
    operations = 0;
    printf("\nDFS using Adjacency Matrix: ");
    DFSMatrix(0, visited, &operations);
    printf("\nDFS operations = %d\n", operations);

    for (i = 0; i < MAX; i++) visited[i] = 0;
    operations = 0;
    printf("\nDFS using Adjacency List: ");
    DFSList(0, visited, &operations);
    printf("\nDFS operations = %d\n", operations);

    printf("\nVERTEX SEARCH\n-------------\n");
    searchVertex('E');

    printf("\nEDGE CHECKING\n-------------\n");
    edgeCheckMatrix('E', 'F');
    edgeCheckList('E', 'F');

    return 0;
}
