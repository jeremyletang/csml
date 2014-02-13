/*
* The MIT License (MIT)
* 
* Copyright (c) 2014 Jeremy Letang (letang.jeremy@gmail.com)
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy of
* this software and associated documentation files (the "Software"), to deal in
* the Software without restriction, including without limitation the rights to
* use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
* the Software, and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
* FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
* IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef CSML_MEMORY_H
#define CSML_MEMORY_H

/* Objects allocators and destructors */

/* On heap allocator constructor */
#define new(complet_type_name, ...)      _new(new_, complet_type_name, __VA_ARGS__)
#define _new(arg1, arg2, ...)            arg1##arg2(__VA_ARGS__)

/* On stack constructor */
#define create(complet_type_name, ...) 	_create(stacked_, complet_type_name, __VA_ARGS__)
#define _create(arg1, arg2, ...)        arg1##arg2(__VA_ARGS__)

/* Destructor for heap and stack object */
#define delete(var)\
if ((var) != 0) {\
    if ((var)->free(var) == true)\
        free(var);\
}

#endif /* CSML_MEMORY_H */
