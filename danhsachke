#pragma once
#include<iostream>
using namespace std;
struct Node {
	int DinhKe;
	int TrongSo;
	Node* link;
};
typedef Node* Nodeptr;
struct DSK
{
	Nodeptr DS[20];
	int n;
};
void init(DSK& x);
void nhapDinh(DSK& x);
void themCuoi(Nodeptr& list, int DinhKe, int TrongSo);
bool docFile(const char* tenFile, DSK& x);
bool ghiFile(const char* tenFile, DSK x);
void nhapCoHuong(DSK& x);
void nhapVoHuong(DSK& x);
void xuat(DSK x);
void menu(DSK x);




#include"Header.h"
void init(DSK& x)
{
	for (int i = 0; i < x.n; i++)
		x.DS[i] = NULL;
}
void nhapDinh(DSK& x)
{
	cout << "\nNhap So DInh:";
	cin >> x.n;
}
void themCuoi(Nodeptr& list, int DinhKe, int TrongSo)
{
	Nodeptr p = new Node;
	p->DinhKe = DinhKe;
	p->TrongSo = TrongSo;
	p->link = NULL;
	if (list == NULL)
		list = p;
	else
	{
		Nodeptr q = list;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
bool docFile(const char* tenFile, DSK& x)
{
	FILE* f;
	fopen_s(&f, tenFile, "rt");
	if (f == NULL)return false;
	fscanf_s(f, "%d", &x.n);
	init(x);
	for (int i = 0; i < x.n; i++)
	{
		int SoDinhKe;
		fscanf_s(f, "%d", &SoDinhKe);
		for (int j = 0; j < SoDinhKe; j++)
		{
			int DinhKe, TrongSo;
			fscanf_s(f, "%d", &DinhKe);
			fscanf_s(f, "%d", &TrongSo);
			themCuoi(x.DS[i], DinhKe, TrongSo);
		}
	}
	fclose(f);
	return true;
}
bool ghiFile(const char* tenFile, DSK x)
{
	FILE* f;
	fopen_s(&f, tenFile, "wt");
	if (f == NULL)return false;
	fprintf(f, "%d \n", x.n);
	for (int i = 0; i < x.n; i++)
	{
		int count = 0;
		Nodeptr q = x.DS[i];
		while (q != NULL)
		{
			q = q->link;
			count++;
		}
		fprintf(f, "%d ", count);
		while (x.DS[i] != NULL)
		{
			fprintf(f, "%d ", x.DS[i]->DinhKe);
			fprintf(f, "%d ", x.DS[i]->TrongSo);
			x.DS[i] = x.DS[i]->link;
		}
		fprintf(f, "\n");
	}
	fclose(f);
	return true;
}
void nhapCoHuong(DSK& x)
{
	do {
		cout << "\nNhap(U-v,x):";
		int u, v, a;
		cin >> u >> v >> a;
		if (u == 0 && v == 0)break;
		themCuoi(x.DS[u], v, a);
	} while (1);
}
void nhapVoHuong(DSK& x)
{
	do {
		cout << "\nNhap(U-v,x):";
		int u, v, a;
		cin >> u >> v >> a;
		if (u == 0 && v == 0)break;
		if (u < v) {
			themCuoi(x.DS[u], v, a);
			themCuoi(x.DS[v], u, a);
		}
	} while (1);
}
void xuat(DSK x)
{
	for (int i = 0; i < x.n; i++)
	{
		if (x.DS[i] == NULL)
			cout << "\nDinh" << i << "khong co dinh ke";
		else
		{
			cout << "\nDinh" << i << ":";
			while (x.DS[i] != NULL)
			{
				cout << "(" << x.DS[i]->DinhKe << "," << x.DS[i]->TrongSo << ")";
				x.DS[i] = x.DS[i]->link;
			}
		}
	}
}

void menu(DSK x)
{
	do
	{
		cout << "\n0.Break";
		cout << "\n1.DocFile";
		cout << "\n2.GhiFile";
		cout << "\n3.Nhap Co Huong";
		cout << "\n4.Nhap Vo Huong";
		cout << "\n5.Xuat";
		cout << "\n6.Tinh bac Dinh u";
		cout << "\nVui long nhap lua chon:";
		int ok;
		cin >> ok;
		if (ok == 0)break;
		switch (ok)
		{
		case 1:
			if (docFile("Text.txt", x) == true)
				cout << "\nTc";
			else
				cout << "\nTB";
			break;
		case 2:
			if (ghiFile("Text.txt", x) == true)
				cout << "\nTc";
			else
				cout << "\nTB";
			break;
		case 3:
			nhapDinh(x);
			init(x);
			nhapCoHuong(x);
			break;
		case 4:
			nhapDinh(x);
			init(x);
			nhapVoHuong(x);
			break;
		case 5:
			xuat(x);
			break;
		}
	} while (true);
}



#include"Header.h"
void main()
{
	DSK x;
	init(x);
	menu(x);
}
