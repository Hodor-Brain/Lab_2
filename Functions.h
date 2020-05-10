#pragma once

#include <iostream>
#include <conio.h>

using namespace std;

void flush();

struct Node
{
	int number = 0;
	int pow = 0;
	Node* next = NULL;
};

struct NodeList
{
	Node* head = NULL;
	int size = 0;

	//NodeList();
	//~NodeList();

	void push_back(int num,int power);
	void Print();
	//void SwapAndPow();
	void AddTheStruct();
};



//void PrintTheRest(NodeList a);

long long Number(NodeList a);

int menu();



//-----// Переробити , щоб записувати коефіцієнт і степінь , В рандомному порядку , з відсортованим списком + вводиться число n , остачу від якого ми будемо шукати