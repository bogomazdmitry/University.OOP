#pragma once
#include <cstddef>
#include <algorithm>

class String
{
private:
	char* str_;
	size_t size_;

public:
	String():
		str_(NULL),
		size_(0){}

	String(const char* str) :
		size_(strlen(str))
	{
		str_ = new char[size_ + 1];
		for (size_t i = 0; i < size_; ++i)
		{
			str_[i] = str[i];
		}
		str_[size_] = '\0';
	}

	String(String&& str) noexcept:
		str_(NULL),
		size_(0)
	{
		std::swap(str_, str.str_);
		std::swap(size_, str.size_);
	}

	String(const String& str) :
		size_(str.size_),
		str_(new char[str.size_ + 1])
	{
		for (size_t i = 0; i < size_; ++i)
		{
			str_[i] = str.str_[i];
		}
		str_[size_] = '\0';
	}

	String& operator=(const String& str)
	{
		if (str_ == str.str_)
		{
			return *this;
		}
		delete[]str_;
		size_ = str.size_;
		str_ = new char[size_ + 1];
		for (size_t i = 0; i < size_; ++i)
		{
			str_[i] = str.str_[i];
		}
		str_[size_] = '\0';
		return *this;
	}

	size_t getSize() const
	{
		return size_;
	}

	~String()
	{
		delete []str_;
		str_ = NULL;
		size_ = 0;
	}

	bool operator<(const String& str) const
	{
		auto s = std::min(str.size_, size_);
		for (size_t i = 0; i < s; ++i)
		{
			if (str_[i] < str.str_[i])
			{
				return true;
			}
			else
			{
				if (str_[i] > str.str_[i])
				{
					return false;
				}
			}
		}
		return s == size_;
	}

	bool operator<=(const String& str) const
	{
		return *this < str || *this == str;
	}

	bool operator>(const String& str) const
	{
		return !(*this <= str);
	}

	bool operator>=(const String& str) const
	{
		return !(*this < str);
	}

	bool operator==(const String& str) const
	{
		if (str.size_ != size_)
		{
			return false;
		}
		for (size_t i = 0; i < size_; ++i)
		{
			if (str_[i] != str.str_[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(const String& str) const
	{
		return !(*this == str);
	}

	friend std::ostream& operator<<(std::ostream& o, const String& str)
	{
		o << str.str_;
		return o;
	}
};

