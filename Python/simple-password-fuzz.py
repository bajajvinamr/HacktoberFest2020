#!/bin/bash
#ssh spam python script

for port in {9000..13999} # set up your range on ports
do
    printf "$port/n"
    ssh -o StrictHostKeyChecking=no -p $port 127.0.0.1
done