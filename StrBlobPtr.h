#include "pch.h"
#include "StrBlob.h"
#include <string>

class StrBlobPtr
{
public:

	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &a, size_t sz=0):wptr(a.data),curr(sz){}

	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>>
		check(size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;

};

