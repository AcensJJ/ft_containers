#ifndef MAP_HPP
# define MAP_HPP

# include "Iterator.hpp"

namespace ft
{
	template < typename Key, typename T >
	class Mtree
	{
		public :
			Key		key;
			T		value;
			Mtree	*parent;
			Mtree	*left;
			Mtree	*right;
			Mtree(const Key& k, const T& val) : key(k), value(val), left(NULL), right(NULL), parent(NULL) {};
			Mtree(Mtree *par, const Key& k, const T& val) : key(k), value(val), left(NULL), right(NULL), parent(par) {};
			Mtree() : key(Key()), value(T()), left(NULL), right(NULL), parent(NULL) {};
	};

	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key,T> > >
	class Map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename std::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::size_type size_type;
			typedef typename allocator_type::difference_type difference_type;

			typedef MapIterator<key_type, Mtree<Key, T> > iterator;
			typedef ConstMapIterator<key_type, Mtree<Key, T> > const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
	
		class value_compare
		{
			protected:
				key_compare comp;
				
				value_compare(key_compare c);
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator()(const value_type& x, const value_type& y) const;
		};

		private:
			pointer _data;
			size_type _size;
			size_type _capacity;
			allocator_type _alloc;
			Mtree<Key, T> *_tree;


			void realloc(size_type len);

		public:
	// Member functions
		explicit Map( const key_compare& comp = key_compare(), const Allocator& alloc = allocator_type() );
		
		// template <class InputIterator>
		// Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		// Map(const Map& x);
		~Map();
		// Map& operator=( const Map& other );

	// Iterators
		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;

		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

	// Capacity
		// bool empty() const;
		// size_type size() const;
		// size_type max_size() const;

	// Element acces
		// T& operator[]( const Key& key );

	// Modifiers
		// std::pair<iterator,bool> insert( const value_type& value );
		// template< class InputIt >
		// void insert( InputIt first, InputIt last );
	
		// void erase( iterator pos );
		// void erase( iterator first, iterator last );
		// size_type erase( const key_type& key );

		// void clear();
		// void swap( map& other );

	// Observers
		// key_compare key_comp() const;
		// std::map::value_compare value_comp() const;

		// Operations
		// iterator find( const Key& key );
		// const_iterator find( const Key& key ) const;
		// size_type count( const Key& key ) const;
		// iterator lower_bound( const Key& key );
		// const_iterator lower_bound( const Key& key ) const;
		// iterator upper_bound( const Key& key );
		// const_iterator upper_bound( const Key& key ) const;
		// std::pair<iterator,iterator> equal_range( const Key& key );
		// std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;	

	// Non-member functions
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator==( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
	};
	//-------------------------- Class --------------------------
	// template< class Key, class T, class Compare, class Allocator >
	// void Map<Key, T, Compare, Allocator>::value_compare(key_compare c) : comp(c) {};

	//-------------------------- Private --------------------------
	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::realloc(size_type len)
	{
		pointer tmp = _alloc.allocate(len);

		for (size_type i = 0; i < (len < _size) ? len : _size; i++)
			tmp[i] = _data[i];
		_alloc.deallocate(_data);
		_data = tmp;
		_capacity = len;
	}
	//-------------------------- CONSTRUCTOR --------------------------
	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator>::Map(const key_compare& c, const allocator_type& a)
	: _data(NULL), _size(0), _capacity(0), _alloc(a), value_compare(c)
	{}

	// template< class Key, class T, class Compare, class Allocator >
	// template< class InputIterator >
	// Map<Key, T, Compare, Allocator>::Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	// {
	// 	;
	// }

	// template< class Key, class T, class Compare, class Allocator >
	// Map<Key, T, Compare, Allocator>::Map(const Map& x)
	// {
	// 	;
	// }

	// template< class Key, class T, class Compare, class Allocator >
	// Map<Key, T, Compare, Allocator> &Map<Key, T, Compare, Allocator>::operator=(Map const & rhs)
	// {
    //     if (this == &rhs) return(*this);
	// 	this->~Map();
    //     return *new(this) Map(rhs);
	// }

	//-------------------------- ... --------------------------

	// Iterators
		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;

		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

	// Capacity
		// bool empty() const;
		// size_type size() const;
		// size_type max_size() const;

	// Element acces
		// T& operator[]( const Key& key );

	// Modifiers
		// std::pair<iterator,bool> insert( const value_type& value );
		// template< class InputIt >
		// void insert( InputIt first, InputIt last );
	
		// void erase( iterator pos );
		// void erase( iterator first, iterator last );
		// size_type erase( const key_type& key );

		// void clear();
		// void swap( map& other );

	// Observers
		// key_compare key_comp() const;
		// std::map::value_compare value_comp() const;

		// Operations
		// iterator find( const Key& key );
		// const_iterator find( const Key& key ) const;
		// size_type count( const Key& key ) const;
		// iterator lower_bound( const Key& key );
		// const_iterator lower_bound( const Key& key ) const;
		// iterator upper_bound( const Key& key );
		// const_iterator upper_bound( const Key& key ) const;
		// std::pair<iterator,iterator> equal_range( const Key& key );
		// std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;	

	// Non-member functions
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator==( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
}

#endif