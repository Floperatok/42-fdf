# <div align="center">⚙️ fdf (a [42](https://42perpignan.fr/) project) ⚙️</div>
<img src=asset/fdf.png with=70%>

## 📑 Introduction
School 42's `fdf` project challenges students to build a wireframe model representing a landscape as a 3D object in which all surfaces are delimited by lines. For doing so, we are asked to use the school's graphics library [minilibx](https://github.com/42Paris/minilibx-linux). This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.\
This project is the opportunity for us to learn the basics of graphics programming, especially how to open a window, place points in space, draw lines and represent 3D objects.
This project is a excellent introduction to the future `42-minirt` project, where we'll be creating a 3D light engine.

Subject : <a href=asset/en.subject.pdf>en.fdf_subject.pdf<a/>

### My grade
[![nsalles's 42 FdF Score](https://badge42.coday.fr/api/v2/clshyl91d071301p436jjiyqr/project/3416754)](https://github.com/Coday-meric/badge42)
## Usage
Download `fdf` and enter the repo :
```sh
git clone https://github.com/Floperatok/42-fdf.git && cd 42-fdf
```
For linux users, you will need to install the following packages :
```sh
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
For Mac and Windows user you can refer to the unofficial [minilibx doc](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) and modify the Makefile.

Compile the project :
```sh
make && make clean
```
The project is now ready to be launched, `fdf` needs a map to read and display. 42 gives us a few maps to try out the project, they can be found in the `maps` folder.\
You can now run `fdf` : 
```sh
./fdf maps/42.fdf
```
A black window with a rotating red 42 wireframe should appear. There are several controls you can use to interact with the wireframe.
| Key           | Effect |
| ------------- | ------ |
| `w`           | Rotation up x axis |
| `s`           | Rotation down x axis |
| `a`           | Rotation left y axis |
| `d`           | Rotation right y axis |
| `q`           | Clockwise rotation |
| `e`           | Anti-Clockwise rotation |
| `tab`         | Enable/Disable auto rotation |
| `space`       | Reset rotation |
| `up arrow`    | Move up |
| `down arrow`  | Move down |
| `left arrow`  | Move left |
| `right arrow` | Move right |
| `+`           | Zoom in |
| `-`           | Zoom out |
| `*`           | Extract |
| `/`           | Press	|
| `t`           | Increase line thickness |
| `r`           | Decrease line thickness |
| `p`           | Change maths |

Enjoy !