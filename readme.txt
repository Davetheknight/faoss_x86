this will be an awesome OS. 

Only runs on x86 and x86_64 by the way.




When creating header files replacing standard libraries, please use "M" inside of the header's #ifndef and #define declaration. Example: we have a stdio.h file so we include in the file #ifndef _MSTDIO_H_ #define _MSTDIO_H_ #endif.


HOW TO GOURCE (in your shell): gource --hide dirnames,filenames --seconds-per-day 0.1 --auto-skip-seconds 1 -1280x720 -o - | ffmpeg -y -r 60 -f image2pipe -vcodec ppm -i - -vcodec libx264 -preset slow -pix_fmt yuv420p -crf 18 -threads 0 -bf 0 gource.mp4

