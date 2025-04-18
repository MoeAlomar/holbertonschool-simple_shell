#!/bin/bash
#
# FFx.bash
#

# 1) Create a nested subdirectory under your repo:
mkdir -p tmp/subdir

# 2) Copy /bin/ls into your repo root via that nested path:
#    tmp/subdir/../../hbtn_ls  → resolves to <repo‑root>/hbtn_ls
cp /bin/ls tmp/subdir/../../hbtn_ls

# 3) Now invoke your shell (still in repo root) with the same nested relative path:
echo "tmp/subdir/../../hbtn_ls /var" | ./hsh
