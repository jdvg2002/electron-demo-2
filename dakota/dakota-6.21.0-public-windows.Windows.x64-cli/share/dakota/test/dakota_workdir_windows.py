#!/usr/bin/env python
from __future__ import print_function
import sys
import os
import subprocess


# Test work_directory named trydir
workdir_basename="trydir"

#if len(sys.argv) == 5:
    # testing with environment variables
#    mode = None
#    paramsfile = sys.argv[2]
#    resultsfile = sys.argv[4]
#elif len(sys.argv) == 4:
if len(sys.argv) > 3:
    mode = sys.argv[1]
    paramsfile = sys.argv[2]
    resultsfile = sys.argv[3]
else:
    mode = None
    paramsfile = sys.argv[1]
    resultsfile = sys.argv[2]

def abort():
    open(resultsfile, "w").close()
    sys.exit(1)

if mode in set(("tag","tag_save","saved_params")):
    # we should find ourselves in a directory tagged with an integer
    pwd = os.getcwd()
    mytag = pwd.split(".")[-1]
    try:
        mytag = int(mytag)
    except ValueError:
        print("Error: Unexpected directory tag!")
        abort()

if mode == "tag_save":
    # if the eval is 2 or greater, the previous dir should be around
    if mytag > 1:
        lastdir = os.path.join("..",workdir_basename + ".%d" % (mytag - 1,))
        if not os.path.isdir(lastdir):
            print("Error: Failed to find saved directory",lastdir)
            abort()
elif mode == "templatefiles":
    # template files will include dakota_workdir_windows.root.dat
    # and they will be symlinked by default
    if not os.path.islink("dakota_workdir_windows.root.dat"):
        if os.path.isfile("dakota_workdir_windows.root.dat"):
            print("Error: dakota_workdir_windows.root.dat is regular file; should be symlink")
        else:
            print("Error: Failed to find template file dakota_workdir_windows.root.dat")
        abort()
elif mode == "templatefiles_copy":
    # template files will include dakota_workdir_windows.root.dat
    # and they will be copied to pwd
    if os.path.islink("dakota_workdir_windows.root.dat"):
        print("Error: dakota_workdir_windows.root.dat is symlink; should be regular file")
        abort()
    if not os.path.isfile("dakota_workdir_windows.root.dat"):
        print("Error: Failed to find template file dakota_workdir_windows.root.dat")
        abort()
elif mode == "templatedir":
    # template files will include templatedir_rosenbrock.py
    # and they will be symlinked by default
     if not os.path.islink("templatedir_rosenbrock.py"):
        if os.path.isfile("templatedir_rosenbrock.py"):
            print("Error:templatedir_rosenbrock.py is regular file; should be symlink")
        else:
            print("Error: Failed to find template file templatedir_rosenbrock.py")
        abort()
elif mode == "templatedir_copy":
    # template files will include templatedir_rosenbrock.py
    # and they will be copied to pwd
    if os.path.islink("templatedir_rosenbrock.py"):
        print("Error: templatedir_rosenbrock.py is symlink; should be regular file")
        abort()
    if not os.path.isfile("templatedir_rosenbrock.py"):
        print("Error: Failed to find template file templatedir_rosenbrock.py")
        abort()
elif mode == "named_params":
    if not os.path.isfile("params.in"):
        print("Error: named parameters file params.in does not exist in trydir")
        abort()
elif mode == "saved_params":
    # if the eval is 2 or greater, the previous dir should be around
    # with a saved params file
    if mytag > 1:
        lastdir = workdir_basename+".%s" % (mytag-1,)
        if not os.path.isdir(".." + os.sep + lastdir):
            print("Error: Failed to find saved directory",lastdir)
            abort()
        if not os.path.isfile(".." + os.sep + lastdir + os.sep + "params.in"):
            print("Error: named parameters file params.in does not exist in last tagged trydir")
            abort()

print("Running rosenbrock...")

args = ["rosenbrock",paramsfile,resultsfile]

returncode = subprocess.call(args, stdout=sys.stdout,stderr=sys.stderr)
sys.exit(returncode)

