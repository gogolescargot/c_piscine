#!/bin/sh
NUM1=$(echo "$FT_NBR1" | tr "'" '0' |sed 'y/\\\"\?\!/1234/')
NUM2=$(echo "$FT_NBR2" | sed 'y/mrdoc/01234/')
RES=$(echo "obase=13; ibase=5; $NUM1 + $NUM2" | bc)
echo $RES | tr '0123456789ABC' 'gtaio luSnemf'
