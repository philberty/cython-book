#ifndef __CPPCODE_H__
#define __CPPCODE_H__

namespace mynamespace {
  template <class T>
  class LinkedList
  {
  private:
    struct ListNode {
      T value;
      ListNode * next;
      ListNode (T value1, ListNode * next1 = NULL) {
	value = value1;
	next = next1;
      }
    };
    ListNode * head;
    ListNode * tail;
    int length;

  public:
    LinkedList() {
      head = tail = NULL;
      length = 0;
    }

    void append (T);
    int getLength (void);
    void remove (int);
    void printList (void);
  };
}
#endif //__CPPCODE_H__
