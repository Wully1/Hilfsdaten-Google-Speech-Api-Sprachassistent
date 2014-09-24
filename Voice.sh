#!/bin/bash

echo "Recording... Press Ctrl+C to Stop."
rec file.flac silence 1 0.1 4% 4 0.5 4% rate 8000

echo "Processing..."
curl -o stt.txt -X POST -T file.flac --user-agent 'Mozilla/5.0' --header 'Content-Type: audio/x-flac; rate=8000;' 'https://www.google.com/speech-api/v2/recognize?output=json&lang=eng-us&key=AIzaSyBPmeQoVbscmpVhYK3p43BOiT8aINiM6_4&client=Mozilla/5.0'| sed -e 's/[{}]/''/g' | awk -F\":\" '{print $4}' | awk -F\",\" '{print $1}' | tr -d '\\n'
./Parser
rm file.flac  > /dev/null 2>&1
