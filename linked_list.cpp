#include <iostream>
#include <array>

template<typename TYPE>
struct linked_list
{
	static unsigned int count;
	static linked_list<TYPE>* head;
	static linked_list<TYPE>* rotating_previous;
	TYPE value;
	linked_list<TYPE>* next;
	linked_list<TYPE>* previous;	
	
	//ctors
	linked_list()
		: value {0}, next {nullptr}, previous {nullptr}
	{
		// determine previous obj ptr
		if (rotating_previous != nullptr)
		{
			// if there is already an item in the list -> assign previous obj pointer to current obj previous var
			previous  = rotating_previous; 
			rotating_previous -> next = this; // assign previous obj next ptr to current object
		}

		rotating_previous = this; // assign current pointer to static var for next ctor loop

		// check head
		if (head == nullptr)
			head = this;
	}

	linked_list(const int& to_be_val) 
		: linked_list()
	{ value = to_be_val; }

	// func to set values
	void set_value(const TYPE& to_be_value)
	{ value = to_be_value; } 
};

// initializing static struct variables
template <>
unsigned int linked_list<int>::count {0};
template <>
linked_list<int>* linked_list<int>::head {nullptr}; 
template <>
linked_list<int>* linked_list<int>::rotating_previous {nullptr};

int main()
{
	
	std::array<linked_list<int>, 5> linked_list_array;

	unsigned int num {0};
	for (auto& LL : linked_list_array)
	{
		LL.set_value(num++);
	}

	return 0;
}
