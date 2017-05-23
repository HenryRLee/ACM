#include "../header.h"

template <class T>
class FakeArray {
public:
	typedef T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef const T* const_pointer;
	typedef const T& const_reference;

	class iterator {
	public:
		typedef T value_type;
		typedef random_access_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef const T* const_pointer;
		typedef const T& const_reference;

		bool operator==(const iterator & other) { return value == other.value; }
		bool operator!=(const iterator & other) { return value != other.value; }
		reference operator*() { return value; }
		pointer operator->() { return &value; }
		iterator& operator++() { ++value; return *this; }
		iterator operator++(int)
		{
			iterator tmp(*this);
			operator++();
			return tmp;
		}
		iterator& operator--() { --value; return *this; }
		iterator operator--(int)
		{
			iterator tmp(*this);
			operator--();
			return tmp;
		}
		friend iterator operator+(iterator lhs, int rhs) {
			lhs.value += rhs;
			return lhs;
		}
		friend iterator operator+(int lhs, iterator rhs) {
			rhs.value += lhs;
			return rhs;
		}
		iterator& operator+=(const int dist) {
			value += dist;
			return *this;
		}
		friend iterator operator-(iterator lhs, int rhs) {
			lhs.value -= rhs;
			return lhs;
		}
		friend difference_type operator-(const iterator& lhs, const iterator& rhs) {
			return difference_type(lhs.value - rhs.value);
		}
		iterator& operator-=(const int dist) {
			value -= dist;
			return *this;
		}
		bool operator<(const iterator& other) { return value < other.value; }
		bool operator<=(const iterator& other) { return value <= other.value; }
		bool operator>(const iterator& other) { return value > other.value; }
		bool operator>=(const iterator& other) { return value >= other.value; }
		reference operator[](int dist) {
			value += dist;
			return value;
		}
		friend void swap(iterator &lhs, iterator &rhs) {
			swap(lhs.value, rhs.value);
		}
		iterator() { }
	private:
		value_type value;
		iterator(const value_type & v) { value = v; }
		friend FakeArray;
	};

	FakeArray(value_type start, value_type end)
   		: start_(start), end_(end) { }

	iterator begin() { return iterator(start_); }
	iterator end() { return iterator(end_); }

private:
	value_type start_;
	value_type end_;
};


