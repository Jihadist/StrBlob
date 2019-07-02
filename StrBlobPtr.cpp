#include "pch.h"
#include "StrBlobPtr.h"
#include <functional>


std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string & StrBlobPtr::operator[](size_t n)
{
	auto p = check(n, "dereference out of range.");
	return (*p)[n];
}

const std::string & StrBlobPtr::operator[](size_t n) const
{
	auto p = check(n, "dereference out of range.");
	return (*p)[n];
}

StrBlobPtr & StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr & StrBlobPtr::operator--()
{
	check(curr, "decrement past end of StrBlobPtr");
	--curr;
	return *this;
}

StrBlobPtr & StrBlobPtr::operator++(int)
{
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}

StrBlobPtr & StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}

StrBlobPtr & StrBlobPtr::operator+=(size_t n)
{
	curr += n;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

StrBlobPtr & StrBlobPtr::operator-=(size_t n)
{
	curr -= n;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t n) const
{
	StrBlobPtr ret = *this;
	ret += n;
	return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n) const
{
	StrBlobPtr ret = *this;
	ret += n;
	return ret;
}

std::string & StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

std::string * StrBlobPtr::operator->() const
{
	return &this->operator*();
}

std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::decr()
{
	--curr;
	check(-1, "decrement past begin of StrBlobPtr");
	return *this;
}

#if 0
Sales_data Sales_data::operator+(const Sales_data & rhs)
{
	if (this->bookNo == rhs.bookNo)
	{
		Sales_data ret;
		ret.units_sold = this->units_sold + rhs.units_sold;
		ret.revenue = this->revenue + rhs.revenue;
		return ret;
	}
	return *this;
}
Sales_data Sales_data::operator+=(const Sales_data & rhs)
{
	Sales_data sum = *this;
	sum += rhs;
	return sum;
}
#endif // 0

bool eq(const StrBlobPtr&lhs, const StrBlobPtr&rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	// if the underlying vector is the same 
	if (l == r)
		// then they're equal if they're both null or 
		// if they point to the same element
		return (!r || lhs.curr == rhs.curr);
	else
		return false;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr==rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs==rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr<rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr>rhs.curr;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr<=rhs.curr;
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr>=rhs.curr;
}
