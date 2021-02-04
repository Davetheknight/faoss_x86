this will be an awesome OS. 

Since this project is difficult to compile outside of Linux, I've included the latest .iso file within the source code. If you want to code to contribute, maybe you should install a virtual machine, or dual boot linux on your computer.
ATTENTION CONTRIBUTORS. YOU WILL NEED TO PROVIDE INFORMATION ON FUNCTIONS IN THE CASE THAT YOU CREATE NEW ONES IN THE DOCUMENTARY DIRECTORY. IF  YOU DON'T ADD DOCUMENTARY, YOUR PULL REQUESTS WILL NOT BE APPROVED. 

Compilation prerequisites: 

Some UNIX or UNIX-like machine is needed to run this.
Make, dash (the shell), nasm, gcc, qemu, and grub2 are needed. 









Only runs on x86 and x86_64 by the way.




When creating header files replacing standard libraries, please use "M" inside of the header's #ifndef and #define declaration. Example: we have a stdio.h file so we include in the file #ifndef _MSTDIO_H_ #define _MSTDIO_H_ #endif.


HOW TO GOURCE (in your shell): gource --hide dirnames,filenames --seconds-per-day 0.1 --auto-skip-seconds 1 -1280x720 -o - | ffmpeg -y -r 60 -f image2pipe -vcodec ppm -i - -vcodec libx264 -preset slow -pix_fmt yuv420p -crf 18 -threads 0 -bf 0 gource.mp4

