#include "pch.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"

void StrBlob::pop_back() const
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

std::string & StrBlob::front() const
{
	// если вектор пуст, функция check() передаст следующее
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string & StrBlob::back() const
{
	check(0, "back on Empty StrBlob");
	return data->back();
}

void StrBlob::check(size_type i, const std::string & msg) const
{
	
	if (i >= data->size())
		throw std::out_of_range(msg);
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data==*rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs==rhs);
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
	return rhs < lhs;
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs < rhs);
}