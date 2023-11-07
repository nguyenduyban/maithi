#pragma once
#include<iostream>
using namespace std;
struct MTK {
	int dinh = 0;
	int DS[20][20];
};
bool docFile(const char* tenFile, MTK& x);
void xuat(MTK x);
bool ghiFIle(const char* tenFile, MTK x);
void nhap(MTK& x);
void menu(MTK x);
void nhapDinh(MTK& x);
void init(MTK& x);


#include"Header.h"
bool docFile(const char* tenFile, MTK& x)
{
	FILE* f;
	fopen_s(&f, tenFile, "rt");
	if (f == NULL)return false;
	fscanf_s(f, "%d", &x.dinh);
	for (int i = 0; i < x.dinh; i++)
	{
		for (int j = 0; j < x.dinh; j++)
		{
			fscanf_s(f, "%d", &x.DS[i][j]);
		}
	}
	fclose(f);
	return true;
}
void xuat(MTK x) {
	for (int i = 0; i < x.dinh; i++) {
		cout << "\n";
		for (int j = 0; j < x.dinh; j++)
		{
			cout << x.DS[i][j] << " ";
		}
	}
}
bool ghiFIle(const char* tenFile, MTK x)
{
	FILE* f;
	fopen_s(&f, tenFile, "wt");
	if (f == NULL)return false;
	fprintf(f, "%d", x.dinh);
	fprintf(f, "\n");
	for (int i = 0; i < x.dinh; i++)
	{
		fprintf(f, "\n");
		for (int j = 0; j < x.dinh; j++)
		{
			fprintf(f, "%d", x.DS[i][j]);
			fprintf(f, " ");
		}
	}
	fclose(f);
	return true;
}
void init(MTK& x) {
	for (int i = 0; i < x.dinh; i++)
		for (int j = 0; j < x.dinh; j++)
			x.DS[i][j] = 0;
}
void nhapDinh(MTK& x) {
	cout << "\nNhap Dinh";
	cin >> x.dinh;
}
void nhap(MTK& x)
{
	do
	{
		int i, j, a;
		cout << "\n Nhap (i-j,u):";
		cin >> i >> j >> a;
		if (i == 0 && j == 0)break;
		x.DS[i][j] = a;
	} while (true);
}
void menu(MTK x)
{
	do
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "0.Break";
		cout << "\n1.DocFile";
		cout << "\n2.Xuat";
		cout << "\n3.Ghi File";
		cout << "\n4.Nhap MT";
		cout << "\nVui long nhap lua chon:";

		int ok;
		cin >> ok;
		if (ok == 0)break;
		switch (ok)
		{
		case 1:
			if (docFile("CoHuong.txt", x) == true)
				cout << "\nDoc File Thanh COng";
			else
				cout << "\nDoc File THat Bai";
			break;
		case 2:
			xuat(x);
			break;
		case 3:
			if (ghiFIle("Text.txt", x) == true)
				cout << "\nGhi File Thanh COng";
			else
				cout << "\nGhi file that bai:";
			break;
		case 4:
			nhapDinh(x);
			init(x);
			nhap(x);
			break;
		}
	} while (true);
}



#include"Header.h"
void main() {
	MTK x;
	menu(x);
}
