# <p style="text-align: center;">Sorting Visualizer</p>
![SortingVisualizer](https://drive.google.com/uc?export=view&id=1_GiN_ZsFBwsxRnq8zH_hnc-4H0I02JRJ)

This is a sorting project written in C++, which includes the SDL2 library for the purpose of demonstrating the different methods each sorting algorithm applies to sort a randomly shuffled array into ascending order.

The sorting algorithms included are:

* [Insertion Sort - Time Complexity: O(n^2) | Space Complexity: O(1)](https://www.geeksforgeeks.org/insertion-sort/)
* [Selection Sort - Time Complexity: O(n^2) | Space Complexity: O(1)](https://www.geeksforgeeks.org/selection-sort/)
* [Bubble Sort - Time Complexity: O(n^2) ~ O(n) | Space Complexity: O(1)](https://www.geeksforgeeks.org/bubble-sort/)
* [Quick Sort - Time Complexity: O(n^2) ~ O(n Logn) | Space Complexity: O(1)](https://www.geeksforgeeks.org/quick-sort/)
* [Heap Sort - Time Complexity: O(n Logn) | Space Complexity: O(1)](https://www.geeksforgeeks.org/heap-sort/)
* [Merge Sort - Time Complexity: T(n) = 2T(n/2) + O(n) | Space Complexity: O(n)](https://www.geeksforgeeks.org/merge-sort/)

## SDL2 Library Setup
This program has only been tested on Unix/Linux-based systems, but compatability for Windows-based systems will be worked on in future updates. For now, the usage of Unix/Linux commands on Windows, as well as any dependencies required by both operating systems, can be obtained by following the links below:

[MinGW-w64 - for Linux](https://www.mingw-w64.org/downloads/)

[MinGW-w64 - for 32 and 64 bit Windows](https://sourceforge.net/projects/mingw-w64/)

[SDL version 2.0.20 (stable)](https://www.libsdl.org/download-2.0.php)

[SDL2_image](https://www.libsdl.org/projects/SDL_image/)

After downloading the SDL2 and SDL2_image libraries, follow the installation instructions below:

[SDL2 Installation Guide](https://wiki.libsdl.org/Installation)

[SDL2_image Documentation](https://libsdl.org/projects/SDL_image/docs/index.html)

To compile and run the program, navigate to the folder and type in the following commands:
```
make
./run
``` 
