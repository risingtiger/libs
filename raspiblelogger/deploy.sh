#!/bin/sh

#rsync -avz --exclude 'node_modules' -e ssh ./ pi@192.168.1.171:/home/pi/raspblelogger/
rsync -avz --exclude 'node_modules' -e -l ssh ./ pi@proxy21.rt3.io:/home/pi/raspblelogger/ -p 36192

