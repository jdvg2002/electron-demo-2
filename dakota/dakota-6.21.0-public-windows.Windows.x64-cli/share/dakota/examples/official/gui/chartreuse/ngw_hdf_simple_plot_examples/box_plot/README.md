# Summary

This example demonstrates a box-and-whiskers plot of data from the Rosenbrock curve.  The box-and-whiskers plot was produced with Next-Gen Workflow (a tool provided in Dakota GUI) using an HDF5 dataset.

![alt text](img/box_plot.png "Example plot")
 
# Description

The Rosenbrock curve is a common function used in mathematical optimization as a performance test problem.  The Rosenbrock function can be described as follows:

$` f(x,y) = (a-x)^2 + b(y-x^2)^2 `$

The unique solution to this problem lies at the point (x1, x2) = (1, 1), where the function value is zero.

# Contents

- `BoxPlot.iwf` - a workflow file that extracts data from rosen_multidim.dat and creates a box-and-whiskers plot.
- `BoxPlot.plot` - a previously-generated plot file representing data from the Rosenbrock curve.  This plot is viewable in Dakota GUI.
- `dakota_results.h5` - a Dakota HDF5 database file, previously produced by running a Dakota parametric study that explored the Rosenbrock curve. 

# How to run the example

- Open Dakota GUI.
- Import this example into your workspace.
- Double-click the BoxPlot.plot file to view the plot.

# How to create a new plot

![alt text](img/workflow.png "The workflow")

- Open Dakota GUI.
- Import this example into your workspace.
- Double-click BoxPlot.iwf.
- Click on one of the two green play buttons in the action ribbon:

![alt text](img/workflowActions.png "Workflow actions")

- The left play button allows you to define a custom location for running the workflow, while the right play button will run the workflow in the default location, which is a directory called "BoxPlot", located in the same parent directory as BoxPlot.iwf.
- After running, a new "BoxPlot" directory will be created, and a new "BoxPlot.plot" will be located inside.  Additionally, this workflow has been built to automatically open the new plot file as soon as it is generated.

# Further Reading

- [Read in the Dakota GUI manual about other types of plots that can be produced.](https://dakota.sandia.gov/content/chartreuse-1)
- [Read about box-and-whisker plots.](https://en.wikipedia.org/wiki/Box_plot)
- [Read about how to produce HDF5 files using Dakota.](https://dakota.sandia.gov/content/hdf-0)
- To learn more about an individual node in Next-Gen Workflow, use the built-in help files by clicking on a node, then clicking on the question mark icon in the Settings Editor view.