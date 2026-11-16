#ifndef TREE_H
#define TREE_H

typedef int Tree_Elem_t;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define SPECIFIER "%d"
#define FILE_FOR_DUMP "MEOW_MEOW.txt"
#define FILE_FOR_PREORDER "PREORDER_FORM.txt"

const Tree_Elem_t NULL_VALUE = 0;
const size_t MAX_LENGTH_PREORDER = 512;

struct Tree_Node_t
{
  Tree_Elem_t  Data;
  Tree_Node_t* Left;
  Tree_Node_t* Right;
  Tree_Node_t* Parent;
};

struct Tree_t
{
  Tree_Node_t* Top;//Root
  int Number_Nodes;
};

enum Tree_Error_Status
{
  EVERYTHING_GOOD = 0,
  INVALID_BRANCH = -1,
  ERROR_OPENING_FILE = -2,
  ERROR_DUMPING_TREE = -3
};

enum Tree_Branch
{
  LEFT_BRANCH  = 100,
  RIGHT_BRANCH = 200
};

struct Tree_Node_t* Creat_Node(Tree_Elem_t New_Data);
void Destroy_Node(struct Tree_Node_t* Node);
struct Tree_t* Tree_Init(void);
void Tree_Destroy(struct Tree_t* Tree);
void Tree_Destroy_Recursive(struct Tree_Node_t* Top_Node);

enum Tree_Error_Status Link_To_Tree(struct Tree_Node_t* Node,
                                    struct Tree_Node_t* Passed_Parent,
                                    Tree_Branch Branch, struct Tree_t* Tree);
//TODO написать сраный Verify_Tree

enum Tree_Error_Status Dump_Tree(const struct Tree_t* Tree);
void Dump_Node(FILE* Dump_File, const struct Tree_Node_t* Node, int Index);
int Dump_Tree_Nodes(FILE* Dump_File, struct Tree_Node_t* Node, int Index);
int Dump_Tree_Arrows(FILE* Dump_File, struct Tree_Node_t* Node, int Index);
int Dump_Tree_Ranks(FILE* Dump_File, struct Tree_Node_t* Node, int Index);

void Print_Tree(const struct Tree_Node_t* Top_Node);
void Print_Tree_Wrap(const struct Tree_Node_t* Top_Node, int* Recursion_Deep);

struct Tree_t* Reading_Preorder(void);
struct Tree_Node_t* Reading_Recursive(const char** Str, struct Tree_t* Tree);
void Skipping_Space(const char** Str);

#endif