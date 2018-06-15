#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct node
{
	int info;
	struct node *pNext;
	struct node *pPrev;
};
typedef struct node NODE;

struct bigint
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct bigint BIGINT;

NODE *GetNode(int x);
void InIt(BIGINT &bi);
void AddHead(BIGINT &bi, NODE *p);
void AddTail(BIGINT &bi, NODE *p);
void Input(BIGINT &bi);
void Output(BIGINT bi);
BIGINT PLus(BIGINT b1, BIGINT b2);
BIGINT operator + (BIGINT b1, BIGINT b2);

BIGINT Minus(BIGINT b1, BIGINT b2);
BIGINT operator -(BIGINT b1, BIGINT b2);
BIGINT SmallMul(BIGINT b1, long x);
void Remove_0(BIGINT &bi);
BIGINT Mul(BIGINT b1, BIGINT b2);
BIGINT operator * (BIGINT b1, BIGINT b2);
void Input(BIGINT & bi, string Filename);