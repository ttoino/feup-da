# 3rd Lab Class – Part B – Dynamic Programming applied to graphs

**IMPORTANT**: The template *Graph* class provided already implements some single-source shortest path algorithms, such as Dijkstra’s.
Since the STL does not support mutable priority queues, you can explore and use the *MutablePriorityQueue* class also included, as follows:

- To create a queue: `MutablePriorityQueue<Vertex<T>> q;`
- To insert vertex pointer *v*: `q.insert(v);`
- To extract the element with minimum value (*dist*): `v = q.extractMin();`
- To notify that thee key (*dist*) of *v* was decreased:: `q.decreaseKey(v);`

## 1. Single-source shortest path using Dynamic Programming: Bellman-Ford Algorithm

1. Implement the following public method in the *Graph* class:

   ```cpp
   void bellmanFordShortestPath(const T &origin)
   ```

   This method implements the Bellman-Ford algorithm to find the shortest paths from *v* (vertex which contains element *origin*) to all other vertices, in a given weighted graph.

2. Implement the following public member function in the class *Graph*:

   ```cpp
   vector<T> getPath(const T &origin, const T &dest)
   ```

   Considering that the *path* property of the graph’s vertices has been updated by invoking a shortest path algorithm from one vertex *origin* to all others, this function returns a vector with the sequence of the vertices of the path, from the *origin* to *dest*, inclusively (*dest* is the attribute info of the destination vertex of the path).
   It is assumed that a path calculation function, such as *unweightedShortestPath*, was previously called with the *origin* argument, which is the origin vertex.

## 2. All-pair shortest paths using Dynamic Programming: Floyd-Warshall Algorithm

Implement the following public method in the Graph class:

```cpp
void floydWarshallShortestPath()
```

This method implements the Floyd-Warshall algorithm to find the shortest paths between all pairs of vertices in the graph.

Additionally, you will also have to implement the following public method of the *Graph* class:

```cpp
vector<T> getfloydWarshallPath(const T &origin, const T &dest)
```

This method returns a vector with the sequence of elements in the graph in the path from *origin* to *dest* (where *origin* and *dest* are the values of the *info* member of the origin and destination vertices, respectively).
