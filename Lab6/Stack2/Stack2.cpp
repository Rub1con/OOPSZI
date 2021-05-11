#include <iostream>
using namespace std;
template<typename T>
class Base
{
public:
	virtual void Push(const T &element) = 0;
	virtual T Pop() = 0;
	virtual int GetSize() const = 0;
	virtual T Peek() const = 0;
	virtual ~Base() {}

};
template<typename T>
class StackTemp : Base<T>
{
public:
	StackTemp()
	{
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
	}
	StackTemp(const StackTemp& other)
	{
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		Node<T>* temp = new Node<T>();
		while (temp->pNext_ != other.tail_)
		{
			PushBack(temp->data_);
			temp = temp->pNext_;
		}
		PushBack(temp->data_);
	}
	StackTemp(StackTemp&& other)
	{
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		Node<T>* temp = new Node<T>();
		while (temp->pNext_ != other.tail_)
		{
			PushBack(other.Stack());
			temp = temp->pNext_;
		}
		PushBack(temp->data_);
	}
	~StackTemp()
	{
		while (size_)
			Pop();
	}
	int GetSize() const
	{
		return size_;
	}

	void Push(const T &element)
	{
		if (head_ == NULL)
		{
			head_ = new Node<T>(element);
			tail_ = head_;
		}
		else
		{
			tail_->pNext_ = new Node<T>(element, NULL, tail_);
			tail_ = tail_->pNext_;
		}
		size_++;
	}

	T Pop()
	{
		Node<T>* temp = tail_; 
		tail_ = tail_->pPrev_; 
		tail_->pNext_ = NULL;
		delete temp; 
		size_--;
		return 0;
	}

	T Peek() const
	{
		return tail_->data_;
	}
	StackTemp<T>& operator=(const StackTemp<T>& other)
	{
		if (this == &other)
			return *this;
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		Node<T>* temp = new Node<T>();
		while (temp->pNext_ != other.tail_)
		{
			PushBack(temp->data_);
			temp = temp->pNext_;
		}
		PushBack(temp->data_);
	}
	StackTemp<T>& operator=(StackTemp<T>&& other)
	{
		if (this == &other)
			return *this;
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		Node<T>* temp = new Node<T>();
		while (temp->pNext_ != other.tail_)
		{
			PushBack(other.PopFront());
			temp = temp->pNext_;
		}
		PushBack(temp->data);
	}
	friend ostream& operator<<(ostream& out, StackTemp& q)
	{
		Node<T>* temp = q.head_;
		while (temp->pNext_ != NULL)
		{
			int test = temp->data_;
			out << temp->data_ << " ";
			temp = temp->pNext_;
		}
		out << temp->data_ << " ";
		return out;
	}
private:
	template<typename T>
	class Node
	{
	public:
		Node(T data, Node* pNext = NULL, Node* pPrev = NULL)
		{
			data_ = data;
			pNext_ = pNext;
			pPrev_ = pPrev;
		}
		Node* pNext_;
		Node* pPrev_;
		T data_;
	};
	Node<T>* head_;
	Node<T>* tail_;
	int size_;
};