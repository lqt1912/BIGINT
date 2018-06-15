#include "BigInt.h"

NODE * GetNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}

void InIt(BIGINT & bi)
{
	bi.pHead = NULL;
	bi.pTail = NULL;
}

void AddHead(BIGINT & bi, NODE * p)
{
	if (bi.pHead == NULL)
		bi.pHead = bi.pTail = p;
	else
	{
		p->pNext = bi.pHead;
		bi.pHead->pPrev = p;
		bi.pHead = p;
	}
}

void AddTail(BIGINT & bi, NODE * p)
{
	if (bi.pHead == NULL)
		bi.pHead = bi.pTail = p;
	else
	{
		bi.pTail->pNext = p;
		p->pPrev = bi.pTail;
		bi.pTail = p;
	}
}

void Input(BIGINT & bi)
{
	InIt(bi);
	do {
		int temp = (int)getchar();
		if (temp == 10)
			break;
		//Kiem tra nhap dung
		temp = temp - 48;
		NODE *p = GetNode(temp);
		if(p != NULL)
			AddTail(bi, p);
	} while (1);
}

void Output(BIGINT bi)
{
	NODE *p = bi.pHead;
	while (p != NULL)
	{
		cout << p->info;
		p = p->pNext;
	}
}

int Demnode(BIGINT l)
{
	{
		int dem = 0;
		for (NODE *k = l.pHead; k; k = k->pNext)
			dem++;
		return dem;

	}
}
BIGINT PLus(BIGINT b1, BIGINT b2)
{
	BIGINT res;
	InIt(res);
	int c1 = 0;
	int c2 = 0;
	for (NODE* t = b1.pHead; t != NULL; t=t->pNext)
		c1++;
	for (NODE* t = b2.pHead; t != NULL; t = t->pNext)
		c2++;
	if (c1 < c2)
	{
		BIGINT tmp = b1;
		b1 = b2;
		b2 = tmp;
	}
	NODE* p1 = b1.pTail;
	NODE* p2 = b2.pTail;
	int Nho = 0;
	NODE* NODE0 = GetNode(0);
	AddHead(b1, NODE0);
	AddHead(b2, NODE0);
	while (p1 != NULL)
	{
		if (p2 != NULL)
		{
			int t = p1->info + p2->info + Nho;
			if (t <= 9)
			{
				NODE* p = GetNode(t);
				AddHead(res, p);
				Nho = 0;
			}
			if (t > 9)
			{
				NODE* p = GetNode(t - 10);
				AddHead(res, p);
				Nho = t / 10;
			}
			p1 = p1->pPrev;
			p2 = p2->pPrev;
		}
		else
		{
			int t = p1->info + 0 + Nho;
			if (t <= 9)
			{
				NODE* p = GetNode(t);
				AddHead(res, p);
				Nho = 0;
			}
			if (t > 9)
			{
				NODE* p = GetNode(t - 10);
				AddHead(res, p);
				Nho = t / 10;
			}
			p1 = p1->pPrev;
			//p2 = p2->pPrev;
		}
	}
	Remove_0(res);
	return res;
}

BIGINT operator+(BIGINT b1, BIGINT b2)
{
	return PLus(b1, b2);
}

BIGINT Minus(BIGINT b1, BIGINT b2)
{
	BIGINT res;
	InIt(res);
	NODE* p1 = b1.pTail;
	NODE* p2 = b2.pTail;
	int carry = 0;
	while (p1 != NULL)
	{
		if (p2 != NULL)
		{
			if (p1->info >= p2->info + carry)
			{
				int t = p1->info - p2->info - carry;
				NODE* p = GetNode(t);
				AddHead(res, p);
				carry=0;
			}
			if (p1->info < p2->info + carry)
			{
				int t = p1->info + 10 - p2->info - carry;
				carry = 1;
				NODE* p = GetNode(t);
				AddHead(res, p);
			}
			p1 = p1->pPrev;
			p2 = p2->pPrev;
		}
		else
		{
			if (p1->info >= 0 + carry)
			{
				int t = p1->info - 0 - carry;
				NODE* p = GetNode(t);
				AddHead(res, p);
				carry = 0;
			}
			if (p1->info < 0 + carry)
			{
				int t = p1->info + 10 - 0 - carry;
				carry = 1;
				NODE* p = GetNode(t);
				AddHead(res, p);
			}
			p1 = p1->pPrev;
		}
	}
	Remove_0(res);
	return res;
}
void DelHead(BIGINT & l)
{
	if (l.pHead != NULL)
	{
		NODE *p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
BIGINT operator-(BIGINT b1, BIGINT b2)
{
	return Minus(b1, b2);
}
void DelTail(BIGINT & l)
{
	if (l.pHead->pNext == NULL)
	{
		DelHead(l);
		return;
	}
	NODE *p = l.pTail;
	(p->pPrev)->pNext = NULL;
	l.pTail = p->pPrev;
	delete p;
}
BIGINT SmallMul(BIGINT b1, long x)
{
	BIGINT res;
	InIt(res);
	for (int i = 0; i < x; i++)
	{
		res = res + b1;
	//Remove_0(res);
	}
	return res;
}

void Remove_0(BIGINT & bi)
{
	while (bi.pHead->info == 0) 
	{
		NODE* tmp = bi.pHead->pNext;
		bi.pHead->pNext = NULL;
		tmp->pPrev = NULL;
		delete bi.pHead;
		bi.pHead = tmp;
		
	} 
}

BIGINT Mul(BIGINT b1, BIGINT b2)
{
	BIGINT res;
	InIt(res);
	NODE* p = b2.pTail;
	int c =0 ;
	
	while (p != NULL)
	{
		BIGINT tmp = SmallMul(b1, p->info);
		for (int i = 0; i < c; i++)
		{
			NODE* d = GetNode(0);
			AddTail(tmp, d);
		}
		res = res + tmp;
		c++;
		p = p->pPrev;
	}
	return res;
}

BIGINT operator*(BIGINT b1, BIGINT b2)
{
	return Mul(b1, b2);
}

bool check(BIGINT b1, BIGINT b2)
{
	NODE *k = b1.pHead;
	NODE *h = b2.pHead;
	do
	{
		if (k < h)
			return true;
		else if (k > h)
			return false;
		else if (k = h)
		{
			k->pNext;
			h->pNext;
		}
	} while (k->pNext != NULL);
}

int IsSmaller(BIGINT b1, BIGINT b2)
{
	int k = Demnode(b1);
	int h = Demnode(b2);
	if (k < h)
		return 1;
	else if (h > h)
		return -1;
	else if (h = k)
	{
		if (check(b1, b2) == true)
			return 1;
		else if (check(b1, b2) == false)
			return -1;
	}
	return 0;
}

void Input(BIGINT & bi, string Filename)
{
	InIt(bi);
	ifstream ifs(Filename);
	if (!ifs)
	{
		cout << "Mo File that bai!" << endl;
		return;
	}
	string A;
	getline(ifs, A);
	int n = A.length();
	for (int i = 0; i < n; i++)
	{
		int Temp = A[i] - 48;
		NODE *p = GetNode(Temp);
		if (p != NULL)
			AddTail(bi, p);
	}
	ifs.close();
}



