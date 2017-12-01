#ifndef TSTACK_H
#define TSTACK_H

#include <iostream>
#include <stack>

namespace fsu {
	template < typename T, size_t N = 100>
	class Stack {

	public:
		void Push(const T& t); //push data
		T Pop(); //pop data
		T& Top(); // copy constructor
		const T& Top() const; // const copy constructor
		size_t Size() const; // size of size_
		size_t Capacity() const; //size of N
		bool Empty() const; //bool check to see if data_ is empty
 		void Clear(); //clear entries

		Stack(); //default constructor
		Stack(char ofc, int dir); //argument constructor
		Stack(const Stack&); //object constructor
		~Stack(); //destructor
		Stack& operator = (const Stack&); // assignment operator

		void Display(std::ostream& os) const; //Display data based on ofc_ and dir_
		void SetOFC(char ofc); //setter for ofc_
		void SetDIR(int dir); //setter for dir_
		void Dump(std::ostream& os) const; //programming dump of the array of data_


	private:
		const size_t capacity_; //size of N
		T data_[N]; //make an array of elements
		size_t size_; // current size of the array
		char ofc_; // determines if it will be displayed with a new line, no space, tab, or space
		int dir_; // controls direction of stack to be displayed
	};
	
	template < typename T, size_t N >
	std::ostream& operator << (std::ostream& os, const Stack<T, N>& s)
	{
		s.Display(os);
		return os;
	}

	template <typename T, size_t N>
	Stack<T, N>& Stack<T, N>::operator= (const Stack& rStack) {
		if (&rStack != this) {
			size_ = rStack.size_;
			for (size_t i = 0; i < N; ++i) {
				data_[i] = rStack.data_[i];
			}
			return *this;
		}
	}

	template<typename T, size_t N>
	size_t Stack<T, N>::Size() const
	{
		return size_;
	}

	template<typename T, size_t N>
	inline size_t Stack<T, N>::Capacity() const
	{
		return N;
	}

	template<typename T, size_t N>
	bool Stack<T, N>::Empty() const
	{
		if (size_ != 0) {
			return false;
		}
		return true;
	}

	template<typename T, size_t N>
	void Stack<T, N>::Clear()
	{
		int temp = 0;
		while(Empty() == false)
		{
			temp = data_[size_];
			--size_;
		}
	}

	template <typename T, size_t N>
	fsu::Stack<T, N>::Stack() : capacity_(N), data_(), size_(0) {}

	template <typename T, size_t N>
	fsu::Stack<T, N>::~Stack() { Clear(); }

	template <typename T, size_t N>
	fsu::Stack<T, N>::Stack(const Stack& copy) : capacity_(copy.capacity_), data_(), size_(copy.size_)
	{
		for (size_t i = 0; i < N; ++i) {
			data_[i] = copy.data_[i];
		}
	}

	template <typename T, size_t N>
	fsu::Stack<T, N>::Stack(char ofc, int dir) : capacity_(N), data_(), size_(0)
	{
		for (size_t i = 0; i < N; ++i) {
			data_[i] = ofc;
		}
	}

	template<typename T, size_t N>
	void fsu::Stack<T, N>::Display(std::ostream & os) const
	{
		switch (ofc_) {
		case '\0':
			if (size_ != 0) {
				if (dir_ == 1) {
					for (size_t i = 0; i < (size_ - 1); ++i) {
						os << data_[i];
					}
					os << data_[size_ - 1];
					return;
				}
				else if (dir_ == -1) {
					for (size_t i = size_; i > 0; --i) {
						os << data_[i - 1];
					}
					os << data_[size_];
					return;
				}
			}
			break;
		case '\n':
			if (size_ != 0) {
				if (dir_ == 1) {
					os << ofc_;
					for (size_t i = 0; i < (size_ - 1); ++i) {
						os << data_[i] << ofc_;
					}
					os << data_[size_ - 1];
					return;
				} 
				else if (dir_ == -1) {
					os << ofc_;
					for (size_t i = size_; i > 0; --i) {
						os << data[size_ - 1] << ofc_;	
					}
					os << data_[size_];
					return;
				}
			}
			break;
		case '\t':
			if ((size_ != 0) || (dir_ == -1) || (dir_ == 1)) {
				
				if (dir_ == 1) {
					os << ofc_;
					for (size_t i = 0; i < (size_ - 1); ++i) {
						os << data_[i] << ofc_;
					}
					os << data_[size_ - 1];
					return;
				} 
				else if (dir_ == -1)
				{
					os << ofc_;
					for (size_t i = size_; i > 0; --i) {
						os << ofc_;
						os << data[size_ - 1] << ofc_;
					}
					os << data_[size_];
					return;
				}
			}
			break;
		case ' ':
		default:
			if ((size_ != 0) || (dir_ == -1) || (dir_ == 1)) {
				if (dir_ == 1) {
				for (size_t i = 0; i < (size_ - 1); ++i) {
					os << data_[i] << ' ';
				}
				os << data_[size_ - 1];
				return;
			} else if (dir_ == -1) {
				for (size_t i = size_; i > 0; --i) {
					os << ' ';
					os << data[size_ - 1] << ' ';
				}
				os << data_[size_];
				return;
 			}
			break;
		}

		for (size_t i = 0; i < size_; ++i) {
			os << data_[i];
		}
	}

	template<typename T, size_t N>
	void Stack<T, N>::SetOFC(char ofc = '\0')
	{
		ofc_ = ofc;
	}
	template<typename T, size_t N>
	void Stack<T, N>::SetDIR(int dir = 0)
	{
		dir_ = dir;
	}

	template<typename T, size_t N>
	void Stack<T, N>::Dump(std::ostream & os) const
	{
		std::cout << "Stack Dump(): " << '\n';
		std::cout << "Capacity: " << N << '\n';
		std::cout << "Size:     " << size_ << '\n';
		std::cout << "Array:    " << "[";
		for (size_t i = 0; i < N; ++i) {
			std::cout << data_[i];
			if (i < N - 1) std::cout << ",";
		}
		std::cout << "]\n";
		std::cout << "Stack:    " << "[";
		for (size_t i = 0; i < size_; ++i) {
			std::cout << data_[i];
			if (i < size_ - 1) std::cout << ",";
		}
		std::cout << "]\n";
	}

	template<typename T, size_t N>
	void fsu::Stack<T, N>::Push(const T & t)
	{
		if (size_ < N)
		{
			data_[size_] = t;
			++size_;
		}
	}

	template<typename T, size_t N>
	T fsu::Stack<T, N>::Pop()
	{
		int temp; 
		
		temp = data_[size_];
		--size_;
		return temp;
	}

	template<typename T, size_t N>
	T & Stack<T, N>::Top()
	{
		if (size_ > 0)
			return data_[size_ - 1];
	}
	template<typename T, size_t N>
	const T & Stack<T, N>::Top() const
	{
		if (size_ > 0)
			return data_[size_ - 1];
	}
}
#endif // !TSTACK_H
