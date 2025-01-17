#!/bin/bash

cd ${remote.dir} || exit 9

if [ -f /etc/bashrc ]; then
    source /etc/bashrc
fi

######################## EXPORTED VARIABLES #####################
#
# This script will export the following variables that will be
# available for use by Dakota's analysis driver:
#
#  RELATIVE_LOCATION - the directory that contains the Dakota scripts
#  DAKOTA_PPN - the number of processors per node
#  DAKOTA_APPLIC_CONCURRENCY - the number of concurrent runs
#  DAKOTA_APPLIC_PROCS - the number of processors per job
#
#################################################################

export RELATIVE_LOCATION=..

###################################################
# --- Step 1. Calculate resource availability --- #
###################################################

export DAKOTA_PPN=${num.processors}/${num.nodes}                              # Number of CPUs per node to use if don't want all used
export DAKOTA_APPLIC_CONCURRENCY=${DakotaKey--evaluation_concurrency}         # Number of concurrent application analysis jobs.
                                                                              #   Infer from the number of requested CPUs above, i.e.
                                                                              #   take total available CPU and divide by CPU per job
export DAKOTA_APPLIC_PROCS=$((${num.processors}/DAKOTA_APPLIC_CONCURRENCY))   # DAKOTA_APPLIC_PROCS to number CPUs per job

# !!! It is REQUIRED that DAKOTA_APPLIC_PROCS either divide evenly   !!!
# !!! into DAKOTA_PPN or be an integer multiple of it (typically is) !!!

echo "Checking that constraint between number of processors, number of concurrent runs, and number of processors per run is respected..."
remainder=$((${num.processors}%DAKOTA_APPLIC_CONCURRENCY))
if [ $remainder -gt 0 ];
then
    echo "${num.processors} must be a multiple of $DAKOTA_APPLIC_CONCURRENCY"
    echo "Exiting..."
    exit -1
fi

echo "INFO: Dakota will manage ${DAKOTA_APPLIC_CONCURRENCY} concurrent application jobs,"
echo "      each running on ${DAKOTA_APPLIC_PROCS} cores,"
echo "      with ${DAKOTA_PPN} processes per node"

##############################
# --- Step 2. Run Dakota --- #
##############################

# Optionally remove existing working directories

if [ ${cleanSubdirectory} -eq 1 ]; then
    num_dirs=`find . -name ${DakotaKey--work_directory}.* -type d | wc -l`
    if [ $num_dirs -gt 0 ]; then
      rm -r ${work_subdirectory}.*
    fi
fi

# Load the Dakota module - or replace this section if modules are not available for loading Dakota

# Uncomment if you need to manually init the module system
# if [ -f /etc/profile.d/modules.sh ]; then
#   source /etc/profile.d/modules.sh
# fi

export APREPRO="module load seacas && aprepro"
module load dakota/6.17.0 # <- Replace version number if desired

# Finally, launch the Dakota process

dakota -preproc -input ${input.file.base.name}.in 1>${input.file.base.name}.out 2>&1