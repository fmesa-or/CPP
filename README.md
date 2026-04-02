<div align="center">

# CPP Modules - 42 School

![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=cplusplus&logoColor=white) ![Makefile](https://img.shields.io/badge/Makefile-427819?style=flat-square) ![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat-square&logo=linux&logoColor=black) ![macOS](https://img.shields.io/badge/macOS-000000?style=flat-square&logo=apple&logoColor=white) ![42 School](https://img.shields.io/badge/42-School-000000?style=flat-square)

*Collection of introductory C++ modules*

---

## ✨ Original Message

> **My first CPP proyects!!**
> 
> Thanks all my colleges for the help to understand C++.

---

## 📚 Available Modules

<details>
<summary><strong>CPP00 - Namespaces, classes, member functions, stdio streams, initialization lists, static, const</strong></summary>

### Contents:
- **ex00**: Megaphone - Application that converts input to uppercase
- **ex01**: My Awesome PhoneBook - Contact management system

### Key Concepts:
- Namespaces in C++
- Classes and member functions
- Input/output with streams (iostream)
- Initialization lists
- Static and const variables

### Compilation:
```bash
cd CPP00/ex01
make
./phonebook
```

</details>

<details>
<summary><strong>CPP01 - Memory allocation, pointers to members, references, switch statement</strong></summary>

### Contents:
- **ex00**: BraiiiiiiinnnzzzZ - Zombie management and memory handling
- **ex01**: Moar brainz - Improved version with new/delete
- **ex02**: HI THIS IS BRAIN - Exploration of pointers and references
- **ex03**: Unnecessary violence - Weapon, HumanA, HumanB classes
- **ex04**: Sed is for losers - Search and replace in files
- **ex05**: Harl 2.0 - Complaint simulator with switch

### Key Concepts:
- Dynamic memory allocation (new/delete)
- Pointers and references
- Pointers to class members
- File handling
- Switch statements

### Compilation:
```bash
cd CPP01/ex05
make
./harl
```

</details>

<details>
<summary><strong>CPP02 - Ad-hoc polymorphism, operator overloading, canonical classes</strong></summary>

### Contents:
- **ex00**: My First Class in Orthodox Canonical Form - Fixed point class
- **ex01**: Towards a more useful fixed-point number - Comparison operators
- **ex02**: Now we're talking - Complete arithmetic operators

### Key Concepts:
- Orthodox Canonical Form
- Operator overloading
- Fixed-point numbers
- Copy constructor and assignment
- Ad-hoc polymorphism

### Compilation:
```bash
cd CPP02/ex02
make
./fixed
```

</details>

<details>
<summary><strong>CPP03 - Inheritance</strong></summary>

### Contents:
- **ex00**: Aaaaand... OPEN YOUR EYES! - Base ClapTrap class
- **ex01**: Serena, my love! - Inheritance with ScavTrap
- **ex02**: Repetitive tasks - Multiple inheritance with FragTrap
- **ex03**: Now it's bigger - DiamondTrap resolving diamond problem

### Key Concepts:
- Single and multiple inheritance
- Constructors and destructors in inheritance
- Diamond problem
- Virtual methods
- Inheritance scope

### Compilation:
```bash
cd CPP03/ex03
make
./diamondtrap
```

</details>

<details>
<summary><strong>CPP04 - Subtype polymorphism, abstract classes, interfaces</strong></summary>

### Contents:
- **ex00**: Polymorphism - Animal, Dog, Cat with virtual methods
- **ex01**: I don't want to set the world on fire - Abstract classes
- **ex02**: Abstract class - Complete animal interface

### Key Concepts:
- Virtual methods and pure virtual methods
- Abstract classes and interfaces
- Subtype polymorphism
- Virtual Constructor Pattern
- Dynamic binding

### Compilation:
```bash
cd CPP04/ex02
make
./animals
```

</details>

<details>
<summary><strong>CPP05 - Repetition and exceptions</strong></summary>

### Contents:
- **ex00**: Mommy, when I grow up, I want to be a bureaucrat - Custom exceptions
- **ex01**: Form up, soldier! - Validation with exceptions
- **ex02**: Shrubbery Creation - Tree generator with exceptions
- **ex03**: The Bureaucrat is never happy - Exception escalation

### Key Concepts:
- Custom exceptions
- Try-catch-throw
- Exception inheritance
- Data validation
- Robust error handling

### Compilation:
```bash
cd CPP05/ex03
make
./bureaucrat
```

</details>

<details>
<summary><strong>CPP06 - Casts</strong></summary>

### Contents:
- **ex00**: Conversion of scalar types - static_cast
- **ex01**: Serialization - Serials and void pointers
- **ex02**: Identify real type - dynamic_cast and RTTI

### Key Concepts:
- static_cast, dynamic_cast, reinterpret_cast, const_cast
- Safe type conversion
- RTTI (Run-Time Type Information)
- Object serialization
- Polymorphism with casts

### Compilation:
```bash
cd CPP06/ex02
make
./identify
```

</details>

<details>
<summary><strong>CPP07 - Templates</strong></summary>

### Contents:
- **ex00**: Templates - Template functions
- **ex01**: Iter - Generic iterators and templates
- **ex02**: Array - Template classes

### Key Concepts:
- Template functions
- Template classes
- Template specialization
- Generic iterators
- Basic metaprogramming

### Compilation:
```bash
cd CPP07/ex02
make
./array
```

</details>

<!--
<details>

<summary><strong>CPP08 - Templated containers, iterators, algorithms</strong></summary>

### Contents:
- **ex00**: Easy find - STL containers and algorithms
- **ex01**: Span - Custom container
- **ex02**: Mutant stack - Stack with iterators

### Key Concepts:
- STL Containers (vector, list, map, set)
- STL Iterators (iterator, const_iterator, reverse_iterator)
- STL Algorithms (find, sort, transform)
- Custom containers
- Generic programming

### Compilation:
```bash
cd CPP08/ex02
make
./mutantstack
```

</details>
-->
---

## 🔨 Common Commands

```bash
# Compile a module
cd CPP0X/exYY
make

# Clean object files
make clean

# Remove executable
make fclean

# Rebuild everything
make re

# Execute
./program_name
```

## 📋 Requirements

- **Compiler**: `c++` (C++98)
- **Flags**: `-Wall -Wextra -Werror -std=c++98  -pedantic`
- **Norm**: 42 School Norm
- **System**: Linux / macOS

## 👥 Authorship

Developed as part of the **42 School Core Curriculum**

---

<div align="center">

Made with ☕ at **42 School**

</div>
