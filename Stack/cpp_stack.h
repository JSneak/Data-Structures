/*mystack.h*/


#pragma once


#include <iostream>

#include <queue>

#include <exception>

#include <stdexcept>


using namespace std;


template<typename T>

class mystack

{

private:

	queue<T>  Q;


public:

	// default constructor: 

	mystack()

	{

		/*nothing, Q already created*/ 

	}


	size_t size() const

	{

		return Q.size();

	}


	bool empty() const

	{

		return Q.empty();

	}

	


	T& top()

	{   queue<T>  temp;

		T* top;

		if (!Q.empty()){

		 while (Q.size() > 1){

		 temp.push(Q.front());

		 Q.pop();

		 }

		 top = &Q.front();

		 while(!temp.empty()){

		 Q.push(temp.front());

		 temp.pop();

		 }

		 return *top;

		}

		else

		{

		throw runtime_error("Top of the empty stack");

		}

	}


	void pop()

	{

		queue<T>  temp;

		T top;

		if (!Q.empty()){

		top = Q.front();

		Q.pop();

		while (!Q.empty()) 

		{

		temp.push(top);

		Q.pop();

		top = Q.front();

		}

		Q = temp;

		}

	}


	void push(T element)

	{

	Q.push(element);

	}

};
