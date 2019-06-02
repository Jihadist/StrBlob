#pragma once
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class StrBlobPtr;

class StrBlob
{
public:
	friend class StrBlobPtr;
	typedef std::vector<std::string>::size_type size_type;
	
	StrBlobPtr begin();
	StrBlobPtr end();

	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	friend bool operator>(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend bool operator>=(const StrBlob &, const StrBlob &);
	friend bool operator<=(const StrBlob &, const StrBlob &);

	StrBlob():data(std::make_shared<std::vector<std::string>>()){}
	
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// добавление и удаление элементов
	//void push_back(const std::string &t) const { data->push_back(t); }
	void push_back(std::string &&s) const { data->push_back(s); };
	void pop_back() const;
	// доступ к элементам
	std::string &front() const;
	std::string &back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	// передавать сообщение при недопустимости data[i]
	void check(size_type i, const std::string &msg) const;

};

