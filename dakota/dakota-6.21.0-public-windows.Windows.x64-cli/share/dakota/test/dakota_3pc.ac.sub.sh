#!/bin/bash

# Make sure that Dakota passes both the parameters and results file names. 
# If it doesn't, touch FAIL to force the workflow to FAIL
if [ $# -ne 2 ]
then
  touch FAIL
fi

params=$1
results=$2
# Stem of file is correct
if [ "${params:0:5}" != "tb.in" ] || [ "${results:0:6}" != "tb.out" ]
then
  touch FAIL
fi
# Tags exist; in this case, there's an eval tag but no analysis tag because
# there's only one driver
re='^[0-9]+$'
ptag=${params:6}
rtag=${results:7}
if ! [[ "$ptag" =~ $re ]] || ! [[ "$rtag" =~ $re ]]
then
  touch FAIL
fi

# if there have been any failures up to this point, inform Dakota.
if [ -f FAIL ]
then
  echo FAIL > $results
fi

text_book $params tempresults.out 

