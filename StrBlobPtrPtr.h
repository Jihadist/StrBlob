#pragma once
#include "pch.h"
#include "StrBlobPtr.h"
class StrBlobPtrPtr
{
public:
	StrBlobPtrPtr(StrBlobPtr &a) :sptr(std::make_shared<StrBlobPtr>(a)) {}
	StrBlobPtrPtr();
	~StrBlobPtrPtr();
	StrBlobPtr* operator->() const;
private:
	std::shared_ptr<StrBlobPtr> sptr;
};

