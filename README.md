
<h1 align="center"> 🖨 <a href="#"> Printf </a></h1>
<h3 align="center">My newest project as a cadet at École 42. This is my own 
printf function.</h3>
<h4 align="center">
	<b>Status</b>: Finished ✅🚀 (125%)
</h4>
<p align="center">
	<a href="#About">About</a> •
	<a href="#Features">Features</a> •
	<a href="#How-it-works">How it works</a> • 
	<a href="#Author">Author</a>
</p>

## 💻 About <a name='About'></a>

🖨 The goal of this project was to recode the printf function.

### 🎯 Briefing

Part 				| Functions
-------------------	| --------- 
Mandatory Function	| Managing the following conversions: `cspdiuxX%`
Bonus 1				| Management of any combination of the following flags: `'-0.'` And minimal field width with all conversions
Bonus 2				| Manage all of the following flags: `'# +'` (yes, one of them is a space)

---

## ⚙ Features <a name='Features'></a>
Function			| Behavior
---------------		| --------
printf				| Just like the original printf function (man printf), but applying only the flags and types specified in <a href="#About">Briefing</a>

---

## 🚀 How it works <a name='How-it-works'></a>

### Clone this repository
```git
git clone https://github.com/prmarquesz/ft_printf.git
```
### Running Makefile
Go to the directory where you cloned and run the command
```Makefile
make
```
### Available Options
Command | Usage
------- | -----
`make` | Creates the library (equivalent to `make all` and `make libftprintf.a`)
`make clean` | Removes the object files
`make fclean` | Removes the object files and the library
`make re` | Invokes `fclean` rule and then `all`

### Compilation
Include the header (ft_printf.h) in your main function (`#include "ft_printf.h"`),
and run the command
```c
gcc -Wall -Werror -Wextra main.c libftprintf.a
```
### Running the program
```c
./a.out
```

---

# 👨‍🚀 Author <a name='Author'></a>

<a href="#">
 <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/69995036?v=4" width="100px;" alt=""/>
 <br />
 <sub><b>Paulo Roberto Marques</b></sub></a> <a href="#" title="Cadet">🚀</a>


Made with ❤️ by Paulo Roberto Marques 👋🏽  Get in Touch!

[![Linkedin Badge](https://img.shields.io/badge/-Paulo-blue?style=flat-square&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/in/prmarquesz/)](https://www.linkedin.com/in/prmarquesz/) 
[![Instagram Badge](https://img.shields.io/badge/-prmarquesz-red?style=flat-square&logo=Instagram&logoColor=white&link=https://www.instagram.com/prmarquesz/)](https://www.instagram.com/prmarquesz/)