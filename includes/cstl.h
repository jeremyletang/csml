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

#include "cstl_queue.h"
#include "cstl_stack.h"


#define new(complet_type_name)      _new(new_, complet_type_name)
#define _new(arg1, arg2)            arg1##arg2()
#define stacked(complet_type_name)  _stacked(stacked_, complet_type_name)
#define _stacked(arg1, arg2)        arg1##arg2()
#define delete(var)                 if (var != 0) {free(var)}

//#define IS_TOTOP(X) _Generic((X), default: 0, struct toto*: 1)                                                                                                                                                                                                             
//#define new(cstl_type, type_name) new_##cstl_type##_##type_name##_t()                                                                                                                                                                                                      
//#define stacked(cstl_type, type_name) stack_##cstl_type##_##type_name##_t()                                                                                                                                                                                                
