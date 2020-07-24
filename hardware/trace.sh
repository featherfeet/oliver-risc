#!/bin/bash

LD_LIBRARY_PATH=/home/oliver/catkin_ws/devel/lib:/opt/ros/melodic/lib:/home/oliver/altera/13.0sp1/quartus/linux:/usr/local/computecpp/lib:/home/oliver/altera/13.0sp1/quartus/linux64 ltrace -C /home/oliver/altera/13.0sp1/quartus/linux64/quartus_map top &> ltrace.log
