#include "nodes_LLoLL.h"
#include "cnPtrQueue.h"
#include <iostream>
using namespace std;

namespace CS3358_SP2023_A5P2
{
	
   // do breadth-first (level) traversal and print data
   void ShowAll_BF(PNode* pListHead, ostream& outs){
       cnPtrQueue queue;
       while(pListHead != 0){
           if(pListHead->data != 0){
               queue.push(pListHead->data);
           }
           pListHead = pListHead->link;
       }
       while(!queue.empty()){
           CNode* cNodePtr = queue.front();
           queue.pop();
           outs << cNodePtr->data << "  ";
           if(cNodePtr->link !=0){
               queue.push(cNodePtr->link);
           }
       }
   }
   
   void Destroy_cList(CNode*& cListHead)
   {
      int count = 0;
      CNode* cNodePtr = cListHead;
      while (cListHead != 0)
      {
         cListHead = cListHead->link;
         delete cNodePtr;
         cNodePtr = cListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " CNodes freed"
           << endl;
   }

   void Destroy_pList(PNode*& pListHead)
   {
      int count = 0;
      PNode* pNodePtr = pListHead;
      while (pListHead != 0)
      {
         pListHead = pListHead->link;
         Destroy_cList(pNodePtr->data);
         delete pNodePtr;
         pNodePtr = pListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " PNodes freed"
           << endl;
   }

   // do depth-first traversal and print data
   void ShowAll_DF(PNode* pListHead, ostream& outs)
   {
      while (pListHead != 0)
      {
         CNode* cListHead = pListHead->data;
         while (cListHead != 0)
         {
            outs << cListHead->data << "  ";
            cListHead = cListHead->link;
         }
         pListHead = pListHead->link;
      }
   }
}
