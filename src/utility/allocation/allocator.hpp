#ifndef _ALLOCATOR_HPP
#define _ALLOCATOR_HPP

#include <cstdlib>
#include <limits>
//////////////////////////////////
#define je_malloc malloc
/////////////////////////////////
namespace freecraft::allocation
{



    template<typename T>
    struct RemoveConst
    {
        typedef T value_type;
    };




    template<typename T>
    struct RemoveConst<const T>
    {
        typedef T value_type;
    };




    template < typename  T >
    class JEAllocator 
    {

            
        public:
            // type definitions
            typedef RemoveConst<T> Base;
            typedef typename Base::value_type value_type;
            typedef value_type *pointer;
            typedef value_type const*const_pointer;
            typedef value_type &reference;
            typedef value_type const&const_reference;
            typedef std::size_t size_type;
            typedef std::ptrdiff_t difference_type;




            // rebind allocator to type U
            template < typename  U >
            struct rebind 
            {
                typedef JEAllocator<U> other;
            };




            // return address of values
            pointer address(reference value) const 
            {
                return &value;
            }



            const_pointer address(const_reference value) const 
            {
                return &value;
            }



            /* constructors and destructor
            * - nothing to do because the allocator has no state
            */
            JEAllocator() noexcept 
            {
            }



            JEAllocator(const JEAllocator&) noexcept 
            {
            }



            template < typename  U >
            JEAllocator(const JEAllocator<U> &) noexcept 
            {
            }






            ~JEAllocator() noexcept 
            {
            }




            // return maximum number of elements that can be allocated
            size_type max_size() const noexcept 
            {
                return std::numeric_limits<std::size_t>::max() / sizeof(T);
            }







            // allocate but don't initialize num elements of type T
            pointer allocate(size_type num, const void* = 0) 
            {
                //TODO:add the jemalloc header on compile stage
                return (pointer)je_malloc(num * sizeof(T));
            }




            // initialize elements of allocated storage p with value value
            void construct(pointer p, const T &value) 
            {
                // initialize memory with placement new
                new((void*)p)T(value);
            }




            // destroy elements of initialized storage p
            void destroy(pointer p) 
            {
                // destroy objects by calling their destructor
                p->~T();
            }



            // deallocate storage p of deleted elements
            void deallocate(pointer p, size_type num) 
            {
                je_free(p);
            }


    };

    // return that all specializations of this allocator are interchangeable
    template <class T1, class T2>
    bool operator==(const JEAllocator<T1> &, const JEAllocator<T2> &) noexcept 
    {
        return true;
    }



    template <class T1, class T2>
    bool operator!=(const JEAllocator<T1> &, const JEAllocator<T2> &) noexcept 
    {
        return false;
    }

} // namespace freecraft::allocation


#endif // _ALLOCATOR_HPP