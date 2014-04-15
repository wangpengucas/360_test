#ifndef QIHOO_VECTOR_H_
#define QIHOO_VECTOR_H_
#include <stdlib.h>
#include<iostream>
#include <assert.h>
#include <malloc.h>
namespace qh
{
	static size_t cap_default = 1024;//vector默认容量
    template<class T>
    class vector {
    public:
        //ctor
        vector()
            : data_(NULL), size_(0),cap_(cap_default)
        {
			data_ = new T[cap_*sizeof(T)];
        }

        explicit vector( size_t n, const T& value = T()):cap_(cap_default)
        {
			while(cap_<n)
				cap_+=cap_default;
            data_ = new T[cap_*sizeof(T)];
			size_ = n;
            for (size_t i = 0; i < n; i++)
            {
                *(data_+i) = value;
            }
        }

        vector<T>& operator=(const vector<T>& rhs)
        {
			cap_=cap_default;
			data_ = new T[cap_*sizeof(T)];
            data_ = rhs.data_;
            size_ = rhs.size_;
        }

        //dtor
        ~vector()
        {
            if (data_)
            {
                delete data_;
            }
        }

        //get
        size_t size() const
        {
            return size_;
        }

        // set & get
        T& operator[](size_t index);
		T* begin();
		T* end();
        // set
		void reserve(size_t size);
        void push_back(const T& element);
        void pop_back(const T& element);
		void resize(size_t size);
        //void resize();
        //void reserve();
        void clear();
        bool empty();

    private:
        T*      data_;
        size_t  size_;//容器当前大小
		size_t  cap_;//表示容器的预置容量
    };


	template<class T>
	T & vector<T>::operator[](size_t index)
	{
		if(!(index<size_&&index>=0))
		{
			std::cout<<"out of range"<<std::endl;
			assert(index<size_&&index>=0);
		}
		return *(data_+index);
	}


	template<class T>
	T* vector<T>::begin()
	{
		assert(size_>0);
		return *data_;
	}


	template<class T>
	T* vector<T>::end()
	{
		assert(size_>0);
		return *(data_+size_-1);
	}


	template<class T>
	void vector<T>::reserve(size_t size)
	{

		assert(size>size_);
		T *p =new T[(size-size_)*sizeof(T)];
		if(data_==NULL)
		{
			data_=p;
		}
		else
		{
			memcpy(data_,p,(size-size_)*sizeof(T));
		}
		delete[] p;
	}


	template<class T>
	void vector<T>::push_back(const T& element)
	{
		while(size_>cap_)//如果size大于容器的预置容量了，则将预置容量增加一倍
		{
			cap_+=cap_default;
			reserve(cap_);
		}
		*(data_+size_+1) = element;
		size_++;
	}


	template<class T>
	void vector<T>::pop_back(const T& element)
	{
		assert(size_);
		size_--;
	}


	template<class T>
	void vector<T>::resize(size_t size)
	{
		if(size>size_)
		{
			for(size_t i=size_;i<size;i++)
			{
				data_[i]=0;
			}
			size_=size;
		}
		else
		{
			size_=size;
		}
	}


	template<class T>
	void vector<T>::clear()
	{
		size_=0;
	}

	template<class T>
	bool vector<T>::empty()
	{
		return size_>0?true:false;
	}
}

#endif


