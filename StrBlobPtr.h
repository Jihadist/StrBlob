#pragma once
#include "pch.h"
#include "StrBlob.h"
#include <string>

class StrBlobPtr
{
public:

	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &a, size_t sz=0):wptr(a.data),curr(sz){}

	std::string& operator[](size_t n);
	const std::string& operator[](size_t n) const;

	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr& operator++(int);
	StrBlobPtr& operator--(int);
	StrBlobPtr& operator+=(size_t);
	StrBlobPtr& operator-=(size_t);
	StrBlobPtr operator+(size_t) const;
	StrBlobPtr operator-(size_t) const;
	std::string& operator*() const;
	std::string* operator->() const;

	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>>
		check(size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;

};

