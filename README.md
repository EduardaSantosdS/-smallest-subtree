__Eduarda dos Santos da Silva__

O problema pede que você encontre a menor subárvore de uma árvore binária que contém todos os nós mais profundos da árvore original.

Como foi resolvido?
O código utiliza uma abordagem baseada em recursão para percorrer a árvore e determinar, para cada nó, a profundidade máxima dos seus descendentes e qual é o menor subárvore que contém todos os nós mais profundos.

Exemplos dados:
1-
    [6]<-[5]<-[3]->[1]->[8]
        |         |
        [2]       [0]
        / \
    [7]  [4]
    Input: root = [3,5,1,6,2,0,8,null,null,7,4]
    Output: [2,7,4]
    Explanation: We return the node with value 2, colored in yellow in the diagram.
    The nodes coloured in blue are the deepest nodes of the tree.
    Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.

2-
    Input: root = [1]
    Output: [1]
    Explanation: The root is the deepest node in the tree.

3-
    Input: root = [0,1,3,null,2]
    Output: [2]
    Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.

Resultado do teste no Dr.Memory:
"
DUPLICATE ERROR COUNTS:
	Error #   1:      2
	Error #   2:      2

SUPPRESSIONS USED:

ERRORS FOUND:
      0 unique,     0 total unaddressable access(es)
      3 unique,     5 total uninitialized access(es)
      0 unique,     0 total invalid heap argument(s)
      0 unique,     0 total GDI usage error(s)
      0 unique,     0 total handle leak(s)
      0 unique,     0 total warning(s)
      0 unique,     0 total,      0 byte(s) of leak(s)
      0 unique,     0 total,      0 byte(s) of possible leak(s)
ERRORS IGNORED:
      6 unique,     6 total,   4436 byte(s) of still-reachable allocation(s)
         (re-run with "-show_reachable" for details)
Details: C:\Users\Andre\AppData\Roaming\Dr. Memory\DrMemory-subarvores.exe.3236.000\results.txt
"