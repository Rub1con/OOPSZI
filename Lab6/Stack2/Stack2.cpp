#include <iostream>
using namespace std;
template<typename T>
class Base
{
public:
	virtual void PushBack(T element) {}
	virtual void PopBack() { }
	virtual int GetSize() { return 0; }
	virtual T PeekBack() { return 0; }
	virtual void GetFirst() {}
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
			PopBack();
	}
	int GetSize()
	{
		return size_;
	}
	void PushFront(T element)
	{
		if (head_ == NULL)
		{
			head_ = new Node<T>(element);
			tail_ = head_;
		}
		else
		{
			head_->pPrev_ = new Node<T>(element, head_, NULL);
			head_ = head_->pPrev_;
		}
		size_++;
	}
	void PushBack(T element)
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

	void PopBack()
	{
		Node<T>* temp = tail_; // Запоминаем адрес хвостового элемента
		tail_ = tail_->pPrev_; // Смещаем хвост списка на предыдущий узел
		tail_->pNext_ = NULL;
		delete temp; // Удаляем следующий за хвостом узел
		size_--;
	}

	T PeekBack()
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