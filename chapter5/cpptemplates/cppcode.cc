#include <iostream>
#include "cppcode.h"

using namespace std;

template <class T>
void mynamespace::LinkedList<T>::append (T value)
{
   if (head == NULL)
     {
       head = new ListNode (value);
       tail = head;
     }
   else
     {
       tail->next = new ListNode (value);
       tail = tail->next;
     }
   length++;
}

template <class T>
void mynamespace::LinkedList<T>::printList (void)
{
  if (head != NULL)
    {
      ListNode * it = head;
      while (it != NULL)
	{
	  cout << it->value << endl;
	  it = it->next;
	}
    }
}

template <class T>
int mynamespace::LinkedList<T>::getLength (void)
{
  return length;
}

template <class T>
void mynamespace::LinkedList<T>::remove (int idx)
{
  if (head != NULL)
    {
      // invalid element to remove...
      if (idx < 0 || idx > length)
	return;

      if (idx == 0)
	{
	  ListNode * tmp = head;
	  head = tmp->next;
	  delete tmp;
	  length--;
	}
      else
	{
	  ListNode * it = head;
	  ListNode * parent = it;

	  int i;
	  bool found = false;

	  for (i = 0; i < length; ++i)
	    {
	      if (i == idx)
		{
		  found = true;
		  break;
		}
	      parent = it;
	      it = parent->next;
	    }

	  if (found)
	    {
	      parent->next = it->next;
	      delete it;
	      length--;
	    }
	}
    }
}

#ifdef TEST
int main (int argc, char **argv)
{
  mynamespace::LinkedList<string> list;
  list.append ("derp1");
  list.append ("derp2");
  list.append ("derp3");
  list.printList ();

  cout << "------" << endl;

  list.remove (-7);
  list.printList ();

  return 0;
}
#endif
