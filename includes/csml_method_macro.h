// The MIT License (MIT)
// 
// Copyright (c) 2014 Jeremy Letang (letang.jeremy@gmail.com)
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef CSML_METHOD_MACRO_H
#define CSML_METHOD_MACRO_H

#define push(ptr, var) 					(ptr)->push(ptr, var)
#define top(ptr) 						(ptr)->top(ptr)
#define pop(ptr) 						(ptr)->pop(ptr)
#define is_empty(ptr) 					(ptr)->is_empty(ptr)
#define len(ptr) 						(ptr)->len(ptr)
#define front(ptr) 						(ptr)->front(ptr)
#define push_front(ptr, var) 			(ptr)->push_front(ptr, var)
#define pop_front(ptr)					(ptr)->pop_front(ptr)
#define begin(ptr) 						(ptr)->begin(ptr)
#define end(ptr) 						(ptr)->end(ptr)
#define insert_after(ptr, var1, var2) 	(ptr)->insert_after(ptr, var1, var2)
#define erase_after(ptr, var1) 			(ptr)->erase_after(ptr, var1)
#define erase_in(ptr, var1, var2) 		(ptr)->erase_in(ptr, var1, var2)
#define remove(ptr, var) 				(ptr)->remove(ptr, var)
#define remove_if(ptr, func) 			(ptr)->remove(ptr, func)
#define back(ptr) 						(ptr)->back(ptr)
#define at(ptr, index)					(ptr)->at(ptr, index)
#define push_back(ptr, var) 			(ptr)->push_back(ptr, var)
#define pop_back(ptr)					(ptr)->pop_back(ptr)
#define capacity(ptr) 					(ptr)->capacity(ptr)
#define resize(ptr, size)				(ptr)->resize(ptr, size)
#define clear(ptr) 						(ptr)->clear(ptr)
#define for_each(ptr, func, data) 		(ptr)->for_each(ptr, func, data)
#define swap(ptr, other) 				(ptr)->swap(ptr, other)
#define insert(ptr, ...)	 			(ptr)->insert(ptr, __VA_ARGS__)

#endif // CSML_METHOD_MACRO_H