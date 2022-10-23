#!/bin/bash

############################################################################
##### Simple bash script to create projectN.zip to submit on Coursera ######
############################################################################

##### RUN CMD #############
# cd ~/nand2tetris/projects
#./create_submission 3
##########################

mkdir 0$1/project$1
cp *.hdl project$1/
zip project$1/project$1.zip *
#cleanup
rm *.hdl
mv project$1.zip ../
rm -r project$1/