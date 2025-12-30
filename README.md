# MyMultidimensionalArrayClass_CppUserJournal
This is an article I published in C++ User's Journal

https://jacobfilipp.com/DrDobbs/articles/CUJ/1997/9707/rahimi/rahimi.htm
A Multidimensional Array Class
Ali Rahimi
An array is a simple creature in C, perhaps too simple for the more ambitious needs of object-oriented programming in C++. 
An array class can provide the missing services.

Introduction
Arrays in C++ are not first-class objects. As a result, they suffer from the following major limitations (to paraphrase the ARM [1] ):

An array size is fixed at compile time.
An array is one dimensional. A multidimensional array is treated as an array of array.
An array is not self-describing — given just a pointer to an array there is no way to determine its size.
According to the ARM, the last limitation makes "passing pointers to arrays inherently dangerous.''

My goal here is to remove the last limitation and mitigate the second one. I use the template and inheritance features of C++ to create an array class with several desirable properties:

It is self-describing. Given an array object (or a pointer to one) it's possible to learn the number of dimensions and the lower and upper bounds for each dimension (the shape of the array). This "self-describing" feature make it safe to pass pointers to arrays.
It is as easy to use as C/C++ arrays. The usual subscript notation is used to access an array element.
It is almost as efficient as C/C++ arrays.
It can be easily extended to any dimension
It supports range checking and has the capability to raise range violation exceptions.
It can be extended to support variable-size multidimensional arrays.
