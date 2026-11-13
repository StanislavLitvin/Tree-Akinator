#include "Tree.h"

struct Tree_Node_t* Creat_Node(Tree_Elem_t New_Data)
{
  Tree_Node_t* New_Node = (Tree_Node_t*)calloc(1, sizeof(Tree_Node_t));
  if (New_Node == NULL)
  {
    printf("ERROR: cannot creat new node!\n");
    return NULL;
  }

  New_Node->Data = New_Data;
  New_Node->Left = NULL;
  New_Node->Right = NULL;
  New_Node->Parent = NULL;

  return New_Node;
}

void Destroy_Node(struct Tree_Node_t* Node)
{
  assert(Node);

  Node->Data = NULL_VALUE;
  Node->Left = NULL;
  Node->Right = NULL;
  Node->Parent = NULL;

  free(Node);

  return;
}

struct Tree_t* Tree_Init(void)
{
  struct Tree_t* Tree = (struct Tree_t*)calloc(1, sizeof(struct Tree_t));
  if (Tree == NULL)
  {
    printf("ERROR: cannot creat new tree!\n");
    return NULL;
  }

  Tree->Number_Nodes = 0;
  Tree->Top = NULL;

  return Tree;
}

void Tree_Destroy(struct Tree_t* Tree)
{
  if (Tree == NULL) return;

  if (Tree->Top != NULL)
    Tree_Destroy_Recursive(Tree->Top);

  Tree->Number_Nodes = 0;
  free(Tree);

  return;
}

void Tree_Destroy_Recursive(struct Tree_Node_t* Top_Node)
{
  if (Top_Node == NULL) return;

  if (Top_Node->Left != NULL)
    Tree_Destroy_Recursive(Top_Node->Left);

  if (Top_Node->Right != NULL)
    Tree_Destroy_Recursive(Top_Node->Right);

  Destroy_Node(Top_Node);

  return;
}

enum Tree_Error_Status Link_To_Tree(struct Tree_Node_t* Node,
                                    struct Tree_Node_t* Passed_Parent,
                                    Tree_Branch Branch, struct Tree_t* Tree)
{
  assert(Node);
  assert(Tree);

  if (Tree->Number_Nodes == 0)
  {
    Tree->Top = Node;
    Tree->Number_Nodes++;
    return EVERYTHING_GOOD;
  }

  assert(Passed_Parent);

  if (Branch == LEFT_BRANCH)
    Passed_Parent->Left = Node;

  else if (Branch == RIGHT_BRANCH)
    Passed_Parent->Right = Node;

  else
  {
    printf("ERROR: invalid value of branch\n");
    return INVALID_BRANCH;
  }

  Node->Parent = Passed_Parent;

  Tree->Number_Nodes++;

  return EVERYTHING_GOOD;
}

enum Tree_Error_Status Dump_Tree(struct Tree_t* Tree)
{
  assert(Tree);
  assert(Tree->Top && "Error in Tree->Top. Check it is NULL!!!\n");

  FILE* Dump_File = fopen(FILE_FOR_DUMP, "w");
  if (Dump_File == NULL)
  {
    printf("ERROR: dump file cannot open\n");
    return ERROR_OPENING_FILE;
  }

  fprintf(Dump_File, "digraph Tree_Dump_Graphviz\n"
                     "{\n"
                     "\trankdir=TB;\n"
                     "\tnode [shape=Mrecord, fontcolor=\"#220808\"];\n"
                     "\tbgcolor=\"#EADF9D\";\n"
                     "\tmargin=0.2;\n"
                     "\tpad=0.2;\n\n");

  Dump_Tree_Nodes(Dump_File, Tree->Top, 0);
  fprintf(Dump_File, "\n");

  Dump_Tree_Arrows(Dump_File, Tree->Top, 0);
  fprintf(Dump_File, "\n");

  Dump_Tree_Ranks(Dump_File, Tree->Top, 0);

  fprintf(Dump_File, "}");

  if (fclose(Dump_File) != 0)
    printf("WARNING: dump file cannot close\n");

  system("dot MEOW_MEOW.txt -Tpng -o MEOW_MEOW.png");
  system("start MEOW_MEOW.png");
  getchar();

  return EVERYTHING_GOOD;
}

void Dump_Node(FILE* Dump_File, const struct Tree_Node_t* Node, int Index)
{
  assert(Node);

  const char* Color = (Node->Parent == NULL) ? "#CE86F8" :
                      (Node->Left == NULL && Node->Right == NULL) ? "#93C996" : "#3EB8D7";

  fprintf(Dump_File, "\tnode_%d [label=\"{INDEX: %d | VALUE: " SPECIFIER "}\", "
                      "style=filled, fillcolor=\"%s\"];\n",
          Index, Index, Node->Data, Color);

  return;
}

int Dump_Tree_Nodes(FILE* Dump_File, struct Tree_Node_t* Node, int Index)
{
  if (Node == NULL) return 0;

  Dump_Node(Dump_File, Node, Index);

  int Left_Count = Dump_Tree_Nodes(Dump_File, Node->Left, Index + 1);

  int Right_Count = Dump_Tree_Nodes(Dump_File, Node->Right, Index + 1 + Left_Count);

  return 1 + Left_Count + Right_Count;
}

int Dump_Tree_Arrows(FILE* Dump_File, struct Tree_Node_t* Node, int Index)
{
  if (Node == NULL) return 0;

  if (Node->Left != NULL)
  {
    int Left_Index = Index + 1;
    fprintf(Dump_File, "\tnode_%d -> node_%d;\n", Index, Left_Index);
  }

  int Left_Count = Dump_Tree_Arrows(Dump_File, Node->Left, Index + 1);

  if (Node->Right != NULL)
  {
    int Right_Index = Index + 1 + Left_Count;
    fprintf(Dump_File, "\tnode_%d -> node_%d;\n", Index, Right_Index);
  }

  int Right_Count = Dump_Tree_Arrows(Dump_File, Node->Right, Index + 1 + Left_Count);

  return 1 + Left_Count + Right_Count;
}

int Dump_Tree_Ranks(FILE* Dump_File, struct Tree_Node_t* Node, int Index)
{
  if (Node == NULL) return 0;

  int Left_Count = Dump_Tree_Ranks(Dump_File, Node->Left, Index + 1);
  int Right_Count = Dump_Tree_Ranks(Dump_File, Node->Right, Index + 1 + Left_Count);

  if (Node->Left != NULL || Node->Right != NULL)
  {
    fprintf(Dump_File, "\t{ rank=same; ");

    if (Node->Left != NULL)  fprintf(Dump_File, "node_%d; ", Index + 1);
    if (Node->Right != NULL) fprintf(Dump_File, "node_%d; }\n", Index + 1 + Left_Count);
  }

  return 1 + Left_Count + Right_Count;
}

void Print_Tree(const struct Tree_Node_t* Top_Node)
{
  assert(Top_Node);

  printf("(");

  printf(SPECIFIER, Top_Node->Data);
  
  if (Top_Node->Left)
    Print_Tree(Top_Node->Left);

  if (Top_Node->Right)
    Print_Tree(Top_Node->Right);

  printf(")");
}