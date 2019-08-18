<center>01. 习惯 C++</center>
-----
[TOC]

# 1. 视 C++ 为一个语言联邦

今天的 C++ 已经是个多重泛型编程语言（multiparadigm programming language），一个同时支持过程形式（procedural）、面向对象形式（object-oriented）、函数形式（functional）、泛型形式（generic）、元编程形式（metaprogramming）的语言。这些能力和弹性使 C++ 成为一个无可匹敌的工具，但也可能引发某些迷惑：所有 “适当用法” 似乎都有例外。我们该如何理解这样一个语言呢？

**最简单的方法是将 C++ 视为一个由相关语言组成的联邦而非单一语言**。在其某个次语言（sublanguage）中，各种守则与通例都倾向简单、直观易懂、并且容易记住。然而当你从一个次语言移往另一个次语言，守则可能改变。为了理解 C++，你必须认识其主要的次语言。幸运的是总共由 4 个：

- **C。**说到底 C++ 仍是以 C 为基础。区块（blocks）、语句（statements）、预处理器（preprocessor）、内置数据类型（built-in data types）、数组（arrays）、指针（pointer）等统统来自 C。许多时候 C++ 对问题的解法其实不过就是较高级的 C 解法，但当你以 C++ 内的 C 成分工作时，高效编程守则映照出 C 语言的局限：没有模板（templates）、没有异常（exceptions）、没有重载（overloading）......
- **Object-Oriented C++。**这部分也就是 C with Classes 所诉求的：classes（包括构造函数和析构函数）、封装（encapsulation）、继承（inheritance）、多态（polymorphism）、虚函数（virtual，动态函数）等等。这一部分是面型对象设计之古典守则在 C++ 上的最直接实施。
- **Template C++。**这是 C++ 的泛型编程（generic programming）部分，也是大多数程序员经验最少的部分。Template 相关考虑与设计已经弥漫整个 C++，良好编程守则中 “唯 template 适用” 的特殊条款并不罕见。实际上由于 template 威力强大，它们带来崭新的编程泛型（programming paradigm），也就是所谓的 template metaprogramming（TMP，模板元编程）。
- **STL。**STL 是个 template 程序库，看名称也知道，但它是非常特殊的一个。它对容器（containers）、迭代器（iterators）、算法（algorithms）以及函数对象（function objects）的规约有极佳的紧密配合与协调，然而 templates 及程序库也可以用其他想法建置出来。STL 有自己特殊的办事方式，当你伙同 STL 一起工作，你必须遵守它的规约。

记住这四个次语言，当你从某个次语言切换到另一个，导致高效编程守则要求你改变策略时，不要感到惊讶。例如对内置类型（即 C-like）而言 **pass-by-value** 通常比 **pass-by-reference** 高效；但当你从 C part of C++ 移往 Object-Oriented C++，由于用户自定义构造函数和析构函数的存在，**pass-by-reference-to-const** 往往更好。运用 Template C++ 时尤其如此，因为彼时你甚至不知道所处理的对象的类型。然而一旦跨入 STL 你就会了解，迭代器和函数对象都是在 C 指针之上塑造出来的，所以对 STL 的迭代器和函数对象而言，旧式的 **pass-by-value** 守则再次使用。