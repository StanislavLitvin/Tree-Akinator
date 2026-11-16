/*#include "Tree.h"
#include "Tree_Functions.cpp"

int main()
{
  struct Tree_Node_t* T10 = Creat_Node(10);
  struct Tree_Node_t* T20 = Creat_Node(20);
  struct Tree_Node_t* T30 = Creat_Node(30);
  struct Tree_Node_t* T50 = Creat_Node(50);
  struct Tree_Node_t* T52 = Creat_Node(52);
  struct Tree_Node_t* T60 = Creat_Node(60);
  struct Tree_Node_t* T67 = Creat_Node(67);

  struct Tree_t* Tree = Tree_Init();

  Link_To_Tree(T50, NULL, LEFT_BRANCH, Tree);
  Link_To_Tree(T20, T50, LEFT_BRANCH, Tree);
  Link_To_Tree(T60, T50, RIGHT_BRANCH, Tree);
  Link_To_Tree(T10, T20, LEFT_BRANCH, Tree);
  Link_To_Tree(T30, T20, RIGHT_BRANCH, Tree);
  Link_To_Tree(T52, T60, LEFT_BRANCH, Tree);
  Link_To_Tree(T67, T60, RIGHT_BRANCH, Tree);

  Dump_Tree(Tree);
  Print_Tree(Tree->Top);

  Tree_Destroy(Tree);

  struct Tree_t* New_Tree = Reading_Preorder();

  Dump_Tree(New_Tree);
  Print_Tree(New_Tree->Top);

  Tree_Destroy(New_Tree);

  return 0;
}*/


#include "Tree.h"
#include "Tree_Functions.cpp"

int main()
{
  struct Tree_Node_t* T1  = Creat_Node(1);
  struct Tree_Node_t* T2  = Creat_Node(2);
  struct Tree_Node_t* T3  = Creat_Node(3);
  struct Tree_Node_t* T4  = Creat_Node(4);
  struct Tree_Node_t* T5  = Creat_Node(5);
  struct Tree_Node_t* T6  = Creat_Node(6);
  struct Tree_Node_t* T7  = Creat_Node(7);
  struct Tree_Node_t* T8  = Creat_Node(8);
  struct Tree_Node_t* T9  = Creat_Node(9);
  struct Tree_Node_t* T10 = Creat_Node(10);
  struct Tree_Node_t* T11 = Creat_Node(11);
  struct Tree_Node_t* T12 = Creat_Node(12);
  struct Tree_Node_t* T13 = Creat_Node(13);
  struct Tree_Node_t* T14 = Creat_Node(14);
  struct Tree_Node_t* T15 = Creat_Node(15);

  struct Tree_t* Tree = Tree_Init();

  Link_To_Tree(T1,  NULL, LEFT_BRANCH,  Tree);

  Link_To_Tree(T2,  T1, LEFT_BRANCH,  Tree);
  Link_To_Tree(T3,  T1, RIGHT_BRANCH, Tree);

  Link_To_Tree(T4,  T2, LEFT_BRANCH,  Tree);
  Link_To_Tree(T5,  T2, RIGHT_BRANCH, Tree);
  Link_To_Tree(T6,  T3, LEFT_BRANCH,  Tree);
  Link_To_Tree(T7,  T3, RIGHT_BRANCH, Tree);

  Link_To_Tree(T8,  T4, LEFT_BRANCH,  Tree);
  Link_To_Tree(T9,  T4, RIGHT_BRANCH, Tree);
  Link_To_Tree(T10, T5, LEFT_BRANCH,  Tree);
  Link_To_Tree(T11, T5, RIGHT_BRANCH, Tree);
  Link_To_Tree(T12, T6, LEFT_BRANCH,  Tree);
  Link_To_Tree(T13, T6, RIGHT_BRANCH, Tree);
  Link_To_Tree(T14, T7, LEFT_BRANCH,  Tree);
  Link_To_Tree(T15, T7, RIGHT_BRANCH, Tree);

  Dump_Tree(Tree);
  Print_Tree(Tree->Top);

  Tree_Destroy(Tree);

  struct Tree_t* New_Tree = Reading_Preorder();

  Dump_Tree(New_Tree);
  Print_Tree(New_Tree->Top);

  Tree_Destroy(New_Tree);

  return 0;
}