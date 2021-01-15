#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <memory>
# include <string>
# include <stack>

namespace ft
{
	template <typename It>
	class ReverseIterator : public It
	{
		public:
			using typename It::link_type;
			using typename It::link_pointer;
			using typename It::value_type;
			using typename It::pointer;
			using typename It::const_pointer;
			using typename It::reference;
			using typename It::const_reference;
		
		
			ReverseIterator() : It(){};
			ReverseIterator(It const & it) : It(it){};
			ReverseIterator(ReverseIterator const & rhs)
			{
				this->current = rhs.current;
			};
			~ReverseIterator(){};
			ReverseIterator &		operator=( ReverseIterator const & rhs )
			{
				this->current = rhs->current;
			}

			ReverseIterator &operator++()
			{
				this->current = this->current->previous;
				return(*this);
			}
			ReverseIterator operator++(int)
			{
				ReverseIterator tmp(*this);
				this->current = this->current->previous;
				return(tmp);
			}

			ReverseIterator &operator--()
			{
				this->current = this->current->next;
				return(*this);
			}
			ReverseIterator operator--(int)
			{
				ReverseIterator tmp(*this);
				this->current = this->current->next;
				return(tmp);
			}
	};
	
	template <class T, class L>
	class Iterator
	{
		public:
			typedef L link_type;
			typedef link_type* link_pointer;
			typedef T value_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;

		protected:
			link_pointer current;

		public:
			//BASICS
			Iterator(link_pointer li)
			{
				this->current = li;
			};

			Iterator( Iterator const & rhs ) : current(rhs.current){};
			~Iterator(){};
			Iterator &		operator=( Iterator const & rhs )
			{
				this->current = rhs->current;
			}

			//BASICS INCREMENTATION
			Iterator &operator++()
			{
				this->current = this->current->next;
				return(*this);
			}
			Iterator operator++(int)
			{
				Iterator tmp(*this);
				this->current = this->current->next;
				return(tmp);
			}

			//Input Category
			bool operator==(const Iterator & rhs)
			{
				return (this->current == rhs->current);
			}
			bool operator!=(const Iterator & rhs)
			{
				return (this->current != rhs->current);
			}
			reference operator*()
			{
				return(this->current->value);
			}
			reference operator->()
			{
				return(this->current->value);
			}

			//Output Category ?????????????????????????? WHAT DO?

			//Forward Specific Category
			Iterator()
			{
				current = NULL;
			};

			//Bidirectional Category
			Iterator &operator--()
			{
				this->current = this->current->previous;
				return(*this);
			}
			Iterator operator--(int)
			{
				Iterator tmp(*this);
				this->current = this->current->previous;
				return(tmp);
			}
	};

	template <typename T>
	class Link
	{
		public :
			T		value;
			Link	*next;
			Link	*previous;
			Link(const T& val) : value(val), next(NULL), previous(NULL) {};
			Link(Link *pre) : next(NULL), previous(pre) {};
			Link() : next(NULL), previous(NULL) {};
	};

	template <class T>
	class List
	{
		private:
			Link<T> *_begin;
			Link<T> *_end;
			Link<T> *_rend;
			size_t _size;
			typedef T value_type;
			typedef typename std::allocator<value_type> allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef Link<value_type> link_type;
			typedef link_type* link_pointer;
			typedef Iterator<value_type, link_type> iterator;
			typedef Iterator<const value_type, const link_type> const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
			//MAKE REVERSE ITERATOR AND CONST REVERSE ITERATOR -----------------------------------------
			//MAKE DIFFERENCE_TYPE AND SIZE_TYPE -------------------------------------------------------

		public:
			explicit List (const allocator_type& alloc = allocator_type());
			//explicit List (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			List (const List& x);
			~List();
			//List<T> &		operator=( List const & rhs );

			//Iterators;
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			//Capacity
			bool empty();
			void size();
			void max_size();

			//Element access
			reference front();
			reference back();

			//Modifiers
			void assign();
			void push_front();
			void pop_front();
			void push_back(const value_type& val);
			void pop_back();
			void insert();
			void erase();
			void swap();
			void resize();
			void clear();

			//Operations
			void splice();
			void remove();
			void remove_if();
			void unique();
			void merge();
			void sort();
			void reverse();			
	};


	//-------------------------- CONSTRUCTOR --------------------------
	template <typename T>
	List<T>::List(const List<T>::allocator_type& alloc) : _begin(NULL), _end(NULL), _size(0)
	{
		(void)alloc;
	}

	template <typename T>
	List<T>::~List()
	{
		
	}

	template <typename T>
	List<T>::List(const List& x)
	{
		(void)x;
	}

	//-------------------------- ITERATORS --------------------------
	template <typename T>
	typename List<T>::iterator List<T>::begin()
	{
		return(iterator(this->_begin));
	}

	template <typename T>
	typename List<T>::const_iterator List<T>::begin() const
	{
		return(const_iterator(this->_begin));
	}

	template <typename T>
	typename List<T>::iterator List<T>::end()
	{
		return(iterator(this->_end));
	}

	template <typename T>
	typename List<T>::const_iterator List<T>::end() const
	{
		return(const_iterator(this->_end));
	}

	//------------------- REVERSE ITERATORS ------------------------
	template <typename T>
	typename List<T>::reverse_iterator List<T>::rbegin()
	{
		return(reverse_iterator(this->_end->previous));
	}

	template <typename T>
	typename List<T>::const_reverse_iterator List<T>::rbegin() const
	{
		return(const_reverse_iterator(this->_end->previous));
	}

	template <typename T>
	typename List<T>::reverse_iterator List<T>::rend()
	{
		return(reverse_iterator(this->_rend));
	}

	template <typename T>
	typename List<T>::const_reverse_iterator List<T>::rend() const
	{
		return(const_reverse_iterator(this->_rend));
	}

	//-------------------------- CAPACITY --------------------------
	template <typename T>
	bool List<T>::empty()
	{
		return(begin() == end());
	}

	//-------------------------- ELEMENT ACCESS --------------------------
	template <typename T>
	typename List<T>::reference List<T>::front()
	{
		return(_begin->value);
	}

	template <typename T>
	typename List<T>::reference List<T>::back()
	{
		return(_end->previous->value);
	}

	//-------------------------- MODIFIERS --------------------------
	template <typename T>
	void List<T>::push_back(const value_type& val)
	{
		if (_begin == NULL)
		{
			_begin = new Link<T>(val);
			_rend = new Link<T>();
			_rend->next = _begin;
			_begin->previous = _rend;
			_begin->next = _end;
			_end = new Link<T>(_begin);
		}
		else
		{
			_end->next = new Link<T>(_end);
			_end->next->previous = _end;
			_end->value = val;
			_end = _end->next;
		}
	}
}

#endif