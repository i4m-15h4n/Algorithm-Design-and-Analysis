#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <bits/stdc++.h>
using namespace std;
#define SIZE 20

struct data {
    	int intItem;
    	double doubleItem;
    	string stringItem;
};

struct DataItem {
    data dataItem;
    int key;
};

struct DataItem* dataList[SIZE];
struct DataItem* singleItem;
struct DataItem* item;

int getHashCode(int key) {
    return key%SIZE;
}

struct DataItem *search(int key) {
    //get the hash
    int hashIndex = getHashCode(key);
    //move in array until an empty
    while(dataList[hashIndex]!=NULL) {
        if(dataList[hashIndex]->key==key)
            return dataList[hashIndex];
        //go to next cell
        ++hashIndex;
        //wrap around the table
        hashIndex %= SIZE;
    }
    return NULL;
};

void insert(int key,struct data dataItem) {
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->dataItem.intItem=dataItem.intItem;
    item->dataItem.doubleItem=dataItem.doubleItem;
    item->dataItem.stringItem=dataItem.stringItem;
    item->key = key;

    //get the hash
    int hashIndex = getHashCode(key);

    //move in array until an empty or deleted cell
    while(dataList[hashIndex] != NULL && dataList[hashIndex]->key != -1) {
        //goto next call
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }
    dataList[hashIndex] = item;
}

struct DataItem* del(struct DataItem* item) {
    int key = item->key;

    //get the hash
    int hashIndex = getHashCode(key);

    //move in array until an empty
    while(dataList[hashIndex] != NULL) {
        if(dataList[hashIndex]->key ==key) {
            struct DataItem* temp = dataList[hashIndex];

            //assign a dummy item at deleted position
            dataList[hashIndex] = singleItem;
            return temp;
        }
        //go to next cell
        ++hashIndex;
        //wrap around the table
        hashIndex %= SIZE;
    }
    return NULL;
};

void display() {
    int i=0;
    for(i=0;i<SIZE;++i) {
        if(dataList[i] != NULL)
        	cout<<"(" << dataList[i]->key << "=>" << dataList[i]->dataItem.intItem << ", " <<dataList[i]->dataItem.doubleItem 
        << ", " << dataList[i]->dataItem.stringItem << ") ";
        else printf("-- ");
    }
    printf("\n");
}

int main() {
    singleItem = (struct DataItem*) malloc(sizeof(struct DataItem*));
    singleItem->dataItem.intItem = -1;
    singleItem->dataItem.doubleItem = -1;
    singleItem->dataItem.stringItem = -1;
    singleItem->key = -1;

    insert(1,(data){20,20.1,"This"});
    insert(2,(data){203,2340.1,"World"});
    insert(43,(data){2430,20.1,"is"});
    insert(23,(data){42,20.1,"Soo"});
    insert(53,(data){3220,43320.1,"Beautiful"});
    insert(12,(data){320,4320.1,"Do"});
    insert(24,(data){230,20.1,"You"});
    insert(28,(data){230,203.1,"Know"});

    display();
    item = search(23);
    if(item!= NULL) {
        printf("Element found: %d\n",item->key);
        cout << item->dataItem.intItem << " " << item->dataItem.doubleItem << " " << item->dataItem.stringItem << endl;
    } else {
        printf("Element not found\n");
    }

}
