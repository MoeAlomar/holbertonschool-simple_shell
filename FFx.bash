#!/bin/bash
#
# FFx.bash

# 1) Make sure the parent’s parent dir is writable
chmod u+w ../../

# 2) Copy /bin/ls there
cp /bin/ls ../../hbtn_ls

# 3) Run your shell against that new file
echo "../../hbtn_ls /var" | ./hsh
