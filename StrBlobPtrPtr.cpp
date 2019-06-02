#include "pch.h"
#include "StrBlobPtrPtr.h"


StrBlobPtrPtr::StrBlobPtrPtr()
{
}


StrBlobPtrPtr::~StrBlobPtrPtr()
{
}

StrBlobPtr* StrBlobPtrPtr::operator->() const
{
	auto p = sptr.operator->();
	return p;
}
