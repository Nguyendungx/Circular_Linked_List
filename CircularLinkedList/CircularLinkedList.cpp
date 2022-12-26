#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "graphics.h"

using namespace std;

struct NODE
{
    int data;
    NODE* next;
};
NODE* createNODE(int x)
{
    NODE* temp = new NODE;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

NODE* addElement(NODE* p, int x)
{
    NODE* temp = createNODE(x);
    p->next = temp;
    return temp;
}

NODE* addBegin(NODE* last, int x)
{
    NODE* temp = new NODE;
    temp->data = x;
    temp->next = last;
    last = temp;
    return last;
}

NODE* addAfter(NODE* last, int k, int x)
{
    NODE* p = last;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    NODE* temp = new NODE;
    temp->data = x;
    temp->next = p->next;
    p->next = temp;

    return last;
}

NODE* addEnd(NODE* last, int x)
{
    NODE* p = last;
    while (p->next != NULL)
    {
        p = p->next;
    }
    NODE* temp = new NODE;
    temp->data = x;
    temp->next = NULL;
    p->next = temp;
    return last;
}

NODE* deleteBegin(NODE* last)
{
    NODE* p = last;
    p = p->next;
    delete(last);
    return p;
}

NODE* deleteEnd(NODE* last)
{
    NODE* p = last;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    delete(p->next);
    p->next = NULL;
    return last;
}

NODE* deleteAfter(NODE* last, int k)
{
    NODE* p = last;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    NODE* temp = p->next;
    p->next = p->next->next;
    delete(temp);
    return last;
}


void dem(int n, int& t)
{
    while (n != 0)
    {
        t++;
        n = n / 10;
    }
}

void printList(NODE* l)
{
    system("cls");
    int t = 0;
    NODE* a = l;
    NODE* p = l;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
        t++;
    }

    setcolor(1);
    for (int i = 0; i < t; i++)
    {
        rectangle(400 + i * 90, 300, 470 + i * 90, 360);
        drawText(460 + i * 90, 300, "->");
    }

    for (int j = 0; j < t; j++)
    {
        char temp[5];
        int n = a->data;
        int q = 0;
        dem(n, q);
        for (int i = q - 1; i >= 0; i--)
        {
            temp[i] = (n % 10) + 48;
            n = n / 10;
        }
        temp[q] = '\0';
        drawText(420 + (j) * 90, 300, temp);
        a = a->next;
    }

    setcolor(3);
    rectangle(400, 250, 470, 290);
    drawText(405, 245, "Head");
    drawText(425, 270, "|");
    line(445, 295, 440, 300);
    line(440, 300, 430, 295);
    line(482 + (t - 1) * 90, 265, 482 + (t - 1) * 90, 325);
    line(470, 265, 482 + (t - 1) * 90, 265);

}

void Insert(NODE* last, NODE* p, int n)
{
    int k, x;
    cout << "Nhap vi tri ban muon chen (0 la vi tri cua Head): ";
    cin >> k;
    cout << "Nhap gia tri phan tu ban muon chen: ";
    cin >> x;
    if (k == 0)
        last = addBegin(last, x);
    else if (k == n)
        last = addEnd(last, x);
    else
        last = addAfter(last, k, x);
    printList(last);
}

void Delete(NODE* last, int n)
{
    int k;
    cout << "Nhap vi tri phan tu ban muon xoa: ";
    cin >> k;
    if (k == 0)
        last = deleteBegin(last);
    else if (k == n - 1)
        last = deleteEnd(last);
    else
        last = deleteAfter(last, k);
    printList(last);
}


void menu(NODE* last, NODE* p, int n)
{
    cout << "\n1. Insert\n";
    cout << "2. Delete\n";
    cout << "Nhap lua chon cua ban: ";
    int t;
    cin >> t;

    if (t == 1)
    {
        Insert(last, p, n);
        menu(last, p, n);
    }

    else if (t == 2)
    {
        Delete(last, n);
        menu(last, p, n);
    }

    else
    {
        system("cls");
        menu(last, p, n);
    }
}

int main()
{
    initgraph();
    _getch();
    int n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    cout << "Nhap gia tri tung phan tu: ";
    cin >> x;
    NODE* last = createNODE(x);
    NODE* p = last;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = addElement(p, x);
    }
    menu(last, p, n);
    return 0;
}