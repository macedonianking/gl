#ifndef WC_UNIQUE_PTR_H
#define WC_UNIQUE_PTR_H

#include <stdio.h>
#include <stdlib.h>

template<typename Tp>
class WcUniquePtr
{
private:
	Tp	*mPtr;

public:
	explicit WcUniquePtr(Tp *ptr) :
		mPtr(ptr)
	{
	}

	WcUniquePtr() :
		mPtr(NULL)
	{
	}

	~WcUniquePtr()
	{
		if (mPtr != NULL)
		{
			delete mPtr;
			mPtr = NULL;
		}
	}

	Tp *Get()
	{
		return mPtr;	
	}

	const Tp *Get() const
	{
		return mPtr;
	}

	Tp *Release()
	{
		Tp *ptr = mPtr;
		mPtr = NULL;
		return ptr;
	}

	void Reset(Tp *ptr = NULL)
	{
		if (mPtr != ptr)
		{
			delete mPtr;
			mPtr = ptr;
		}
	}

	WcUniquePtr<Tp>& operator=(Tp *ptr)
	{
		Reset(ptr);
	}

	Tp *operator->()
	{
		return mPtr;
	}

	const Tp *operator() const
	{
		return mPtr;
	}

	Tp &operator*()
	{
		return *mPtr;
	}

	const Tp &operator*() const
	{
		return *mPtr;
	}

private:
	WcUniquePtr(const WcUniquePtr &ptr);
};

template<typename Tp>
class WcUniquePtr<Tp[]>
{
private:
	Tp		*mPtr;

public:
	explicit WcUniquePtr(const Tp ptr[]) :
		mPtr(ptr)
	{
	}

	WcUniquePtr() :
		mPtr(NULL)
	{
	}

	~WcUniquePtr()
	{	
		if (mPtr != NULL)
		{
			delete [] mPtr;
			mPtr = NULL;
		}
	}

	Tp *Get()
	{
		return mPtr;
	}

	const Tp *Get() const
	{
		return mPtr;
	}

	Tp &operator*()
	{
		return *mPtr;
	}

	const Tp &operator() const
	{
		return *mPtr;
	}

	Tp *operator->()
	{
		return mPtr;
	}

	const Tp *operator->() const
	{
		return mPtr;
	}

	Tp &operator[](int i)
	{
		return mPtr[i];
	}

	const Tp &operator[](int i) const
	{
		return mPtr[i];
	}
private:
	WcUniquePtr(const WcUniquePtr &ptr);
};

#endif // WC_UNIQUE_PTR_H
