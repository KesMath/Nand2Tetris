#!/bin/bash

############################################################################
##### Simple bash script to create projectN.zip to submit on Coursera ######
############################################################################

##### RUN CMD #############
# cd ~/nand2tetris/projects
#./create_submission 3
##########################

export PROJECT_DIR=0$1/project$1
mkdir $PROJECT_DIR
cp $PROJECT_DIR/*.hdl $PROJECT_DIR/
zip $PROJECT_DIR/project$1.zip *
#cleanup
rm $PROJECT_DIR/*.hdl
mv $PROJECT_DIR.zip ../
rm -r $PROJECT_DIR/